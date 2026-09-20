**Name:** Allison Ludwig
**Document:** Lab 4: Actuator Adventures

This is my third assignment working with the ESP32.  This assignment focuses on connecting actuators to the ESP32.

Tools used:
+ Personal computer running VS Code on Windows with extension Platform.io
+ Language C++
+ ESP32
+ USB-C connecting ESP32 and personal computer
+ TT motor
+ Servo motor
+ Lab manual provided

Steps:

The first part of this lab was to connect a TT motor to the ESP32 and power it.
I used the given ESP32 diagram to locate the correct pins.  Note that A0 and A1 are valid output pins, unlike some other input-only pins that must be avoided.

See photo of setup in _photos videos_ folder under _Lab 4_ folder titled ecse395_lab4_tt_circuit

+ Decreasing the value of the input in analogWrite() decreases the speed of the spinning.  I decreased the value from 255 to 200 to observe this.
+ Swapping which pin has a nonzero input for analogWrite() changes CCW to CW spinning.  Originally, the motor spun CCW, but after the swap, it spun CW.
+ Increasing delay() input increases the amount of spin time, and decreasing the input decreases the amount of spin time.  

The second part of the lab was to control the length and direction of spinning for the TT motor.  The goal was 5 seconds spinning clockwise, 2 second stop, 5 second spin CCW, then 2 second stop, then loop.  See _TT Motor Rotate_ for code.
A video of this working is uploaded to _pictures videos_ folder in _Lab 4_ folder titled ecse395_lab4_1

The third part of the lab was to connect a Servo motor to the ESP32 and power it.  
To do this, first we had to download the correct library from Platform.io.
The Servo motor uses pulse-width modulation (PWM) for its control type.  This means that the width of the pulse is being changed in order to communicate what angle the motor is supposed to spin to.  

See photo of setup in _pictures videos_ folder under _Lab 4_ folder titled ecse395_lab4_servo_circuit

The variables _minPulseWidth_ and _maxPulseWidth_ are the range of widths, in microseconds (us), that correspond to the minimum and maximum angles.  For example, an input of _minPulseWidth_ will result in the lowest angle allowed.

The next step in this part was to change some variables one at a time and note their impact.  After changing one variable, I changed it back to its original value in order to more fully realize the impact of changing the next variable.

_minPulseWidth_: 
+ Changed from 500 to 1500
+ No visible change.  This is because the change is internal.  A pulse of width 1500us now results in the lowest angle possible.

_maxPulseWidth_:
+ Changed from 2500 to 4000
+ No visible change.  This is because the change is internal.  A pulse of width 4000us now results in the highest angle possible.

_setPeriodHertz_:
+ Changed from 50 to 10
+ Decreasing the frequency increases the time between each pulse.  Thus, the motor's movement becomes less smooth.  

_Rotation Range_:
+ To change the rotation range, I changed the values of 180 in the initial lines of each for loop to 90.
+ Instead of rotating 180 degrees, the motor now only rotates 90 degrees back and forth.

_delay_
+ Changed to 50
+ Increasing the delay increases the time that is spent in rest between iterations of the for loop, thus increasing the time between pulses and motor movement, making the motion less smooth.

The fourth part of the lab was to modify the code so the servo motor moves to random angles between 0 degrees and 180 degrees with different delays.
To do this, we used the _random()_ function.  See comments in code for explanation on methodology.
A video of this working is uploaded to _pictures videos_ folder in _Lab 4_ folder titled ecse395_lab4_2

Location of Code:

All code for this lab is in src folder in Lab 4.
TT Motor.cpp --> first part
TT Motor Rotate.cpp --> second part
Servo Motor.cpp --> third part
Servo Motor Random.cpp --> fourth part

Videos are uploaded in _pictures videos_ folder in _Lab 4_ folder.

**Time Reporting and Reflection:**

+ This assignment took me 50 minutes before class, 55 minutes of class, 120 minutes outside of class in the lab, and 60 additional minutes completing the write-up after the lab.

+ Medium

+ I had trouble uploading my code to the ESP32, which was resolved when I double-checked my electrical connections.  I then had trouble because I did not realize that some pins are input-only, but after switching the pin that connected the motor to the ESP32, I was able to fix this.  Overall, this assignment took me a lot of time, but it was not due to the assignment being overly hard.

+ I feel uncomfortable with consistently using the ESP32.  I will fix this by going in to lab outside of class and redoing old labs to ensure that I know how to use the device.

+ I appreciate the extra time allotted for this assignmet.

