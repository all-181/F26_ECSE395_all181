**Name:** Allison Ludwig
**Document:** Lab 4: Actuator Adventures

This is my third assignment working with the ESP32.  This assignment focuses on connecting actuators to the ESP32.

Steps:

The first part of this lab was to connect a TT motor to the ESP32 and power it.
I used the given ESP32 diagram to locate the correct pins.  Note that A0 and A1 are valid output pins, unlike some other input-only pins that must be avoided.
Decreasing the value of the input in analogWrite() decreases the speed of the spinning.
Swapping which pin has a nonzero input for analogWrite() changes CCW to CW spinning.
Increasing delay() input increases the amount of spin time, and decreasing the input decreases the amount of spin time.

Location of Code:

