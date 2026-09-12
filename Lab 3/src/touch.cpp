#include <Arduino.h> 

#define LED_PIN 13 //all181: The general input-output pin 13 is assigned to control the LED
#define SENSOR_PIN A1  //all181: sets that sensor pin is connected to pin 0

void setup() {
  Serial.begin(115200);//all181: match this baud rate
  pinMode(LED_PIN, OUTPUT);  // all181: LED is an output
  pinMode(SENSOR_PIN, INPUT);  // all181: sensor is an input
}

// GOAL: Display "Touch detected!" if touch detected and "No touch detected...," if no touch detected
// GOAL: When sensor is touched, LED will light up/*

void loop(){
int sensorValue = digitalRead(SENSOR_PIN);

// creating an if, else statement

if (sensorValue == 1){
    Serial.println("Touch detected!");
    digitalWrite(LED_PIN, HIGH); // all181: if the sensor is touched (if), turn the builtin LED on

}
else{
    Serial.println("No touch detected...");
    digitalWrite(LED_PIN, LOW);// all181: if the sensor is not touched (else), turn the LED off

}

delay(100); //all181: delay the loop 100ms and then recheck if the sensor is touched

}