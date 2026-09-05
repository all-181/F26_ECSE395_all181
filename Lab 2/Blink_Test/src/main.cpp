#include <Arduino.h>
// This is required in PlatformIO but hidden in the standard Arduino IDE.
//This tells the compiler to include definitions from the Arduino library

#define LED_PIN 13 //The general input-output pin 13 is assigned to control the LED

void setup() {
  pinMode(LED_PIN, OUTPUT);
  // TODO: Define your baud rates
  // Baud rate is the speed of data transmission, measuring the number of signal changes per second in communication channel
  // Increasing baud rate can speed up data transfer but may introduce errors if the hardware or connection is not stable
  // Use short USB cables when using higher baud rates
  // Some ESP32 boards experience more noise at higher baud rates
  Serial.begin(115200); // Start the Serial connection
}

void loop() {
  // loop() is an infinite loop function in C++ (basically while(true) in matlab?)
  // Define your text output to Serial Monitor
  // The Serial Monitor is ???
  Serial.println("think beyond the possible"); // Print the words to the Serial Monitor.
  
//Goal: Create blinks increasing in frequency
//Learn how to use while loops in C++


  //increase frequency after every cicle

  int i = 900;

  while (i > 30) {
    digitalWrite(LED_PIN, HIGH);
    delay(i);
    digitalWrite(LED_PIN, LOW);
    delay(i);
    i = i - 30;
  }
}