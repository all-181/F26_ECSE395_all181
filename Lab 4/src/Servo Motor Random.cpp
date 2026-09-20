#include <ESP32Servo.h> //all181: include library

Servo myServo; //all181: pin 26, output pin, number found on esp32 diagram
const int servoPin = 26;

// variable for random angle
int randomAngle; 

// Variable for pulse width
int pulseWidth;

// Define the minimum and maximum pulse widths for the servo
const int minPulseWidth = 500; // 0.5 ms
const int maxPulseWidth = 2500; // 2.5 ms

void setup() {
  // Attach the servo to the specified pin and set its pulse width range
  myServo.attach(servoPin, minPulseWidth, maxPulseWidth);

  // Set the PWM frequency for the servo
  myServo.setPeriodHertz(50); // Standard 50Hz servo
}

void loop() {
    //  --- SECTION 1: Make a Random Angle Between 0 to 180 ---
    randomAngle = random(0,180); // random(A,B); returns a random value between A and B

    // ---SECTION 2: Map Pulse Width with Angle
    pulseWidth = map(randomAngle, 0, 180, minPulseWidth, maxPulseWidth); // all181: create a pulsewidth that corresponds to the random angle
    myServo.writeMicroseconds(pulseWidth); // all181: write pulse width to servo motor

    delay(random(400,1000)); // change delay to range between 400ms and 1000ms
}