# Eurorack Soundbar
Goal: A table with fitting speaker & synth electronics for a MIDI keyboard.

<a href="https://github.com/flyingzebra/EurorackSoundbar/blob/main/illustrations/Clavinova CLP 153S.png"><img src="/illustrations/Clavinova CLP 153S.png?raw=true" width=40% align=left block></a>

# Piano enclosures deserve better design
It all started with buying an all-in-one furnished hammer-action piano with built-in synth and speakers, but ending 25 years later with a shell containing a terribly old synth and procrastinating MIDI interface.  That said, while build quality on all parts of the piano gracefull survived decades of playing, electronics inside turned out to be fashion-sensitive. As a matter of fact, furniture built-in synths sooner or later all become **OBSOLETE**. I long thought about flinging out the guts out of my good old Clavinova from Yamaha built around a synth chip from 1991 (YMW258-F), but selling my old piano in its original state and figure out a more future-proof enclosure sounded like a better idea, as I really wanted an enclosure allowing more flexibility.  So, here's the plan: 
* Buy a multi-sensor MIDI keyboard - I fell for a KAWAI VPC1, but any model will do.
* Design a slim, good-looking table on wheels carrying about 30Kg=66lbs of keyboard and another 20Kg=44lbs of soundbar.
* Design a soundbar including a standardised built-in rack space for replacable electronics : **A Eurorack Soundbar as it were!**

<a href=https://github.com/flyingzebra/EurorackSoundbar/blob/main/illustrations/Piano_Speaker_Glance.png><img src="/illustrations/Piano_Speaker_Glance.png?raw=true" width=100% block></a>


# Eurorack Soundbar Requirements
## Furniture
1.1) Elegant & aesthetically matching the MIDI keyboard<br>
1.2) Providing table surface fitting Piano Keyboard + Soundbar.<br>
1.3) Sturdy enough to bear stress and strain caused by ~50Kg=110lbs of weight<br>
1.4) Providing maximum leg space horizontally and vertically.<br>
1.5) Height-adjustable to some extent.<br>
1.6) Piano-black glossy paint finish.<br>

## Speaker enclosure - passive part
2.1) Perfectly fitting keyboard width, and height aligned with the top of the speaker grills.<br>
2.2) Best compromise between good bass production and small enclosure volume.<br>
2.3) Rich sound spectrum and spatial perception ideal for instrument sound reproduction.<br>
2.4) Optional built-in passive filter and accessble attenuators whenever necessary.<br>
2.5) Die-cast, anti-reflection and airleak-proof speaker enclosure.<br>
2.6) Vibration isolation between table & enclosure.<br>
2.7) Does not vibrate or glide off the table.<br>
2.8) Re-openable, allowing replacement of speakers provided with inside fixture.<br>
2.9) All speaker leads and filter leads come straight out of the pressure cabinet. (No electrical circuits inside)<br>
2.10) One common connector (male part) providing electrically separate access to all enclosed speakers and filters.<br>
2.11) Nicely fitting speaker cover frame wrapped in speaker cover fabric, with magnetic attachment<br>
2.12) Speakers pointing upwards, providing a fairly unobstructed sound path<br>

## Electronics enclosure - active part
3.1) One common connector (female part, heading towards the amplifier) with configurable dispatching jumpers.<br>
3.2) Standard Eurorack frame housing 3U 84HP (decisive for speaker enclosure depth).<br>
3.3) Eurorack power source (Low noise 15-35V source for Amps, 5V & 3V3 regulated source for MCU's and controllers), optionally with a 1-button on/off and power-on sequence.<br>
3.4) A good compromise on the divide between Eurorack enclosure height (located between bottom plate and face plate) and speaker enclosure duct height (located under the Eurorack bottom plate).<br>
3.6) Mains inlet connector with fast fuse and manual switch.<br>
3.5) At least 3 essential Eurorack modules<br>
   - Amp (2 x 30-80W)
   - Piano connector face plate (USB-midi, MIDI-in/out)
   - Synth module (MIDI-in to audio)

3.6) Optional Eurorack modules - just brainstorming<br>
   - Battery module providing mobile power
   - Additional experimental synths (without patch cable clutter)
   - MIDI merger/splitter module
   - MIDI controller module (encoders, buttons, sliders, tone wheels, LEDs, touchscreens...)
   - MIDI sequencer / tempo

# Getting sketchy with it
<a href=https://github.com/flyingzebra/EurorackSoundbar/blob/main/illustrations/sketch.jpg><img src="/illustrations/sketch.jpg?raw=true" width=40% align=left block></a>
This is the initial sketch, for what it's worth, outlining all elements including the Piano; we'll come back later on the exact measures and additional features; obviously depending on the MIDI keyboard outer dimensions one has purchased.  

This is our first step, planning how this soundbar will fit best fit behind your MIDI keyboard, the outer dimensions of the table, how your knees will ideally fit under that table, and many other practical considerations.

<a href="https://github.com/flyingzebra/EurorackSoundbar/blob/main/illustrations/Clavinova CLP 153S.png"><img src="/illustrations/ergonomy.png?raw=true" width=35% block></a>


# Hardware

<a href="https://beyondmicrocontrol.github.io/AsciiCAD/index.html?LZSS=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">Input module</a>

# Tools

<a href=https://beyondmicrocontrol.github.io/EurorackSoundbar/tools/TOOLS_CATALOG.html>TOOLS</a>
