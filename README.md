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

<a href="https://beyondmicrocontrol.github.io/AsciiCAD/index.html?d=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">Input module</a>

# Tools

<a href=https://beyondmicrocontrol.github.io/EurorackSoundbar/tools/TOOLS_CATALOG.html>TOOLS</a>
