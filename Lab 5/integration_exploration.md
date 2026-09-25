**Name:** Allison Ludwig
**Lab 5:** Sensor Actuation Integration

**Assignment Overview:**

I intend to design a stopwatch.

**Repository Overview:**

**Steps:**

First, I read over example code for each new component I would be using.

OLED:
Tutorial Site: https://docs.sunfounder.com/projects/umsk/en/latest/03_esp32/esp32_lesson27_oled.html#esp32-lesson27-oled 
Wiring diagram is found on tutorial site.
Adafruit SSD1306 Library: Designed to help with interfacing of SSD1306 OLED display.  
Adafruit GFX Library: Core graphics library for displaying text, colors, shapes, etc.  This will be necessary for displaying the intended stopwatch numbers.
Sample code, which my code is based on, is found on tutorial site. 

Button:
Tutorial Site: https://docs.sunfounder.com/projects/umsk/en/latest/03_esp32/esp32_lesson01_button.html#eps32-lesson01-button
Wiring diagram is found on tutorial site.
No additional libraries are needed.
When pressed, the button closes the circuit.  When unpressed, the button leaves an open circuit.

Vibration Sensor:
Tutorial Site: https://docs.sunfounder.com/projects/umsk/en/latest/03_esp32/esp32_lesson24_vibration_sensor.html#esp32-lesson24-vibration-sensor
Wiring diagram is found on tutorial site.
This is a digital sensor that will go high (1) when the amplitude of a vibration exceeds the reference voltage set, and otherwise will go low (0).

Next, I wrote an algorithm for my stopwatch.

1. Initial state is not counting and has "Ready to go!" displayed.
2. Check if button is pressed.  If button is pressed, go to step 3.  If not, go to step 1.
3. Display "3" for 1 second.
4. Display "2" for 1 second.
5. Display "1" for 1 second.
6. Display "0.0"
7. Count up every tenth of a second (0.1s = 100 ms).  For example, 0.1 seconds after step 6, display "0.01".  
8. Check if vibration module is pressed.  
9. If pressed, display current time for 5 seconds, then go to step 1.  If not pressed, go to step 7.






**Setup and Preparation:**
I am using the Vibration Sensor Module (SW-420).
This module can detect vibrations or shocks on a surface.
I am also using the Button Module.
The button module detects the state of a button.
I am using the OLED Display Module (SSD1306).
This module can display text, graphics, and images.

**In-Class Task Description:**

**Documentation:**
Vibration Sensor: https://docs.sunfounder.com/projects/umsk/en/latest/01_components_basic/24-component_vibration.html
OLED: https://docs.sunfounder.com/projects/umsk/en/latest/01_components_basic/27-component_oled.html 
Button: https://docs.sunfounder.com/projects/umsk/en/latest/01_components_basic/01-component_button.html 
**Tools Used:**

**Upload Process:**

**System Explanation:**
Picture:
Video: