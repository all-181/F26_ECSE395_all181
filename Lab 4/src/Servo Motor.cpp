/*#include <Arduino.h>
#include <ESP32Servo.h> //all181: reference the new library
// Don't forget to include the library!!
// From PlatfromIO library, search for ESP32 servo and add it to the project

// Define the servo and the pin it is connected to, what is your servo pin?
Servo myServo;
const int servoPin = 26; //all181: defined correct pin using diagram provided

// Define the minimum and maximum pulse widths for the servo
const int minPulseWidth = 500; // 0.5 ms //all181: (changed to 1500)
const int maxPulseWidth = 2500; // 2.5 ms //all181: (changed to 4000)

void setup() {
  // all181: attach the servo to the specified pin and set its pulse width range (explanation of pulse width modulation in actuator adventures markdown file)
  myServo.attach(servoPin, minPulseWidth, maxPulseWidth);

  // Set the PWM frequency for the servo
  myServo.setPeriodHertz(50); //all181:Standard 50Hz servo; changed to 10
}

void loop() {
  // Rotate the servo from 0 to 180 degrees //all181:(change 180 to 90)
  for (int angle = 0; angle <= 180; angle++) {
    int pulseWidth;
    //all181:the map function is a function that maps min angle degrees to min pulse width, and max angle degrees to max pulse width
    // map(angle, min angle, max angle, min pulse width, max pulse width)
    pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth); //all181: change 180 to 90
    myServo.writeMicroseconds(pulseWidth); //all181: send pulse to servo
    delay(50); //all181:change to 50
  }

  // Rotate the servo from 180 to 0 degrees
  // all181: change <= to >=
  for (int angle = 180; angle >= 0; angle--) { //all181: change 180 to 90
    int pulseWidth;
    // the map function is a puction that maps 0 degrees to 500 pulse width, and 180 degrees to 2500 pulse width
    // map(angle, min angle, max angle, min pulse width, max pulse width)
    pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth); //all181: change 180 to 90
    myServo.writeMicroseconds(pulseWidth); //all181: send pulse to servo
    delay(50);  //all181: change to 50
  }
} */