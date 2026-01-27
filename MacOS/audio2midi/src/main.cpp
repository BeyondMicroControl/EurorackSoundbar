#include <cmath>
#include <cstdint>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

#include <libremidi/libremidi.hpp>
#include <sndfile.h>

extern "C" {
#include <aubio/aubio.h>
}

static int hz_to_midi(float hz)
{
  if (hz <= 0.f) return -1;
  return int(std::lround(69.0 + 12.0 * std::log2(hz / 440.0)));
}

static float rms(const float* x, int n)
{
  double s = 0.0;
  for(int i = 0; i < n; ++i) s += double(x[i]) * double(x[i]);
  return float(std::sqrt(s / std::max(1, n)));
}

int main(int argc, char** argv)
{
  if(argc < 2)
  {
    std::cerr << "Usage: audio2midi <file.wav>\n";
    return 1;
  }

  const char* path = argv[1];

  // ---- open wav
  SF_INFO info{};
  SNDFILE* f = sf_open(path, SFM_READ, &info);
  if(!f)
  {
    std::cerr << "Failed to open wav: " << sf_strerror(nullptr) << "\n";
    return 1;
  }

  const int sr = info.samplerate;
  const int ch = info.channels;

  std::cout << "WAV: " << path << " sr=" << sr << " ch=" << ch
            << " frames=" << info.frames << "\n";

  // ---- MIDI out
  libremidi::midi_out midi;
  midi.open_virtual_port("Audio2MIDI");

  // ---- aubio pitch
  // Buffer sizes: start conservative; we can tune later.
  const uint32_t hop = 256;
  const uint32_t win = 2048;

  aubio_pitch_t* pitch = new_aubio_pitch("yin", win, hop, sr);
  aubio_pitch_set_unit(pitch, "Hz");
  aubio_pitch_set_silence(pitch, -50.0f);     // dB silence threshold (heuristic)
  aubio_pitch_set_tolerance(pitch, 0.85f);    // higher = stricter

  fvec_t* in  = new_fvec(hop);
  fvec_t* out = new_fvec(1);

  // ---- audio buffers
  std::vector<float> interleaved(hop * ch);
  std::vector<float> mono(hop);

  // ---- note tracking state
  const uint8_t midi_ch = 0; // channel 1

  bool note_on = false;
  int current_note = -1;

  // thresholds (tune later)
  const float rms_on  = 0.01f;   // start note if louder than this
  const float rms_off = 0.006f;  // end note if quieter than this
  const int   stable_frames_needed = 3; // require N consecutive frames
  const int   note_change_hysteresis = 1; // semitones tolerance before changing

  int stable_note = -1;
  int stable_count = 0;

  // For “real-time pacing” based on audio time
  int64_t frames_read_total = 0;
  auto start = std::chrono::steady_clock::now();

  while(true)
  {
    sf_count_t n = sf_readf_float(f, interleaved.data(), hop);
    if(n <= 0) break;

    frames_read_total += n;

    // mixdown to mono for aubio
    for(int i = 0; i < (int)n; ++i)
    {
      double s = 0.0;
      for(int c = 0; c < ch; ++c) s += interleaved[i*ch + c];
      mono[i] = float(s / std::max(1, ch));
    }
    // if last block is short, zero-pad remainder
    for(int i = (int)n; i < (int)hop; ++i) mono[i] = 0.f;

    // copy into aubio input vector
    for(uint32_t i = 0; i < hop; ++i) in->data[i] = mono[i];

    // compute pitch
    aubio_pitch_do(pitch, in, out);
    float hz = out->data[0];

    // compute loudness for note gating
    float e = rms(mono.data(), (int)n);

    // convert to MIDI note
    int note = hz_to_midi(hz);

    // stability logic: require same note across several hops
    if(note > 0)
    {
      if(stable_note < 0 || std::abs(note - stable_note) <= note_change_hysteresis)
      {
        stable_count++;
      }
      else
      {
        stable_note = note;
        stable_count = 1;
      }

      if(stable_note < 0) stable_note = note;
      if(stable_note != note && stable_count == 1) stable_note = note;
    }
    else
    {
      stable_note = -1;
      stable_count = 0;
    }

    const bool stable_enough = (stable_note > 0 && stable_count >= stable_frames_needed);

    // Note on/off state machine
    if(!note_on)
    {
      if(stable_enough && e >= rms_on)
      {
        current_note = stable_note;
        uint8_t vel = (uint8_t)std::clamp(int(e * 8000.0f), 1, 127);
        midi.send_message({ uint8_t(0x90 | midi_ch), uint8_t(current_note), vel });
        note_on = true;
        // std::cout << "ON  note=" << current_note << " hz=" << hz << " rms=" << e << "\n";
      }
    }
    else
    {
      // turn off if silent
      if(e <= rms_off || !stable_enough)
      {
        midi.send_message({ uint8_t(0x80 | midi_ch), uint8_t(current_note), uint8_t(0) });
        note_on = false;
        current_note = -1;
        // std::cout << "OFF rms=" << e << "\n";
      }
      else if(stable_note > 0 && std::abs(stable_note - current_note) >= 2)
      {
        // change note (simple: note-off then note-on)
        midi.send_message({ uint8_t(0x80 | midi_ch), uint8_t(current_note), uint8_t(0) });
        current_note = stable_note;
        uint8_t vel = (uint8_t)std::clamp(int(e * 8000.0f), 1, 127);
        midi.send_message({ uint8_t(0x90 | midi_ch), uint8_t(current_note), vel });
        // std::cout << "CHG note=" << current_note << "\n";
      }
    }

    // Real-time pacing
    double t_sec = double(frames_read_total) / double(sr);
    auto target = start + std::chrono::duration_cast<std::chrono::steady_clock::duration>(
                           std::chrono::duration<double>(t_sec));
    std::this_thread::sleep_until(target);
  }

  // clean up / ensure note off
  if(note_on && current_note > 0)
    midi.send_message({ uint8_t(0x80 | midi_ch), uint8_t(current_note), uint8_t(0) });

  del_fvec(in);
  del_fvec(out);
  del_aubio_pitch(pitch);
  aubio_cleanup();

  sf_close(f);
  std::cout << "Done.\n";
  return 0;
}
