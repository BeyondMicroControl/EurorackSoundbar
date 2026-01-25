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

<a href="https://beyondmicrocontrol.github.io/AsciiCAD/index.html?d=eNrdms1u20YQx+9+ij3WMFhrJerDR4VOWyGSjEqKYMCwb77WQFsYbU8uD0EPRUADpEUENVoIAtIiBtpD0EOB5BHyEHySzPJzl9xd0eLXpsSGjiRyOfub2Zn/roRQfHiO7TkW21YodfAusrbd5tkmnA+6y+19rfaEdnjOLZwPrzznjWffRM2CD16+i1vUM1x61pvizuDcf3WGW/p5yp7M0O5+CR4Bn/8KD6E+OiBW3ZK3kwffkEvCt5w3V/DnMLLRs3/zL9m0260Pf0WvLN+wNfpsauwjtDQMePU71eED0zmnbRDPauf24uKCfH73niWTbX969h/bHvLYZoVozITO3dvIEDcEgmKnWQF87+V/cUt4BVTXaPnFAblp+ZQQiv2VcjPfibExJs+NSHTA9XvsrXZwazro3vpnM3HY3b+M9WTIYUyQcWj+OE5Sno5v3+j9KECsbQOyI7o1u9mK4VxfX7PuveHGvokSYznNpSbBl9PjAM1DZLUbdECHR9CjmI2dmpTxZJMfYbd79LRnnI5SmcZFZ3iqY52kFLjkVY48eO85r0nUCYCY1JlFnhpl9ln3iHSdd4yCLpDw/XwH7RmBhx5VXFibq69MUvuFZYiuAhD8cb1J1SCuF6qtbLLxcKpbmFbJu4fwxPjxkJWSqvWQO1GIormRZjVcsU2qYnNCS1SzqcICFh4moUXVSpM/B/PFfyltxSmadRb/LfM2KwCooiSYsRKst0zn/wSWPp8/iUz+O/N8VTTFZjslkarYbM8MpqBoCdAJC0MKlwIqg09LoDOYD+STluqXC+lscXn5zXc/Iv3z1rkYklKCxeLBkskVmeLIg2k4myDj6tvvL3/QJn3Ua7UmX/0kiqVqNY9El+YRLjljIufEqVMscQdeRC5RKNIVmxt4zppMacmxHE2D7EhHQ13ai4dnV/W1ibuG6ZNhk6YyO8UIGbPTNtyktTJUAFqWihIaSRBRhVUSm8ZMOb2FT28R0MMZep1lhx1ZkmebVkEifMV0EDMrTWL/2n//5PnCR0RO7Y6GJsb4GSZhh9HwCKy9Qt7qhSLKR0qmPO2TDSuLA248A1JtpHUIuLYWWmOQuBsOCDg19I+YWXEFxJa5NKAnPh+k6QQQ1vzXMBFnp3M07CdOX71gFnqK6CFLBK6gGpIjG03JNERalyBrRTGFFgRZT4DM5K+Wq1RLyb8Ux58Rwvu17AiY0snChQuZDoPO0Hrwf3wEcOfGOCyrw26U6ShP1azEJEkAsLYbx0pdQOIvq1baAeIhIO4TxAOC+HgYIdZFiOvSctIMC4g7jSOOky8PsC9lRlNfymgDArgfAMaQHyDHDkWCxuRu/zcvFAWLg9gfeoP+sGR6CRvggSPigV6QRTAUNeKBdsYDFluFm5WWkhUZ4O42gpups+wsddaTr+czZMx97hqGRIK7UU2cnYLuGmICPKyGVlb0KCFbheSBea8e5htY7TC2xHFCwnpyMh8FupVQhjPWtVh4EMotaqimWCmpoHcFwAF1n6DO+asF/pKJuwr1w3Q0P0EQq2MfIGRpDOuoYAk1N56h8dPjoPRxbVRmB9DNwgNsg30q3Ze0J8Tq6vzbYyKAte0NRls3oUmvy9gJytB4Vdf3PvcSok1sQKYWW6VsGJl59nVzrXTMpjYes1h23wjKJYUbaa4It1I7mgJflLH1ZCnqGKmTVNkq5fml6PaW+u4Qukax7dqMdwrtoX06PuH6R61dYWllzKGNixxK/mTP5UdsYeVbBqjKdK4t2AhxU9YXUrulECjWiS2cSBX9nKupoaK8v6V+/E+plBxSNd/9fVK1pSq65XxLWCh4KhlaCd/jqTaoWqt3dZ5ptNZWNKxdK6errpt2r5JI4UHtUCGVH06B6vi/aa5y9VGNqvYRPUJjEQ==">Input module</a>

# Tools

<a href=https://beyondmicrocontrol.github.io/EurorackSoundbar/tools/TOOLS_CATALOG.html>TOOLS</a>
