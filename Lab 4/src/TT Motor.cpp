#include <Arduino.h>

// TODO: Define your pins
// Hint: Look at your wiring. Which pins did you use?
const int MOTOR_B_1A = 26; // Replace 0 with your pin number
const int MOTOR_B_2A = 25; // Replace 0 with your pin number
/*

void setup() {

  Serial.begin(115200); // set baud rate
  pinMode(MOTOR_B_1A, OUTPUT);
  pinMode(MOTOR_B_2A, OUTPUT);  

Serial.println("ON");

  analogWrite(MOTOR_B_1A, 0);
  analogWrite(MOTOR_B_2A, 200);

  delay(1000);

Serial.println("OFF");

  analogWrite(MOTOR_B_1A, 0);  
  analogWrite(MOTOR_B_2A, 0);

  Serial.println("DONE");
}

void loop() {

}
*/

// Note:
// - Please modify the `analogWrite()`, swap the `analogWrite()`, and modify the `delay()`.
// - You don't have to put anything in the loop.
//      - If you would like to run the code again, please press the `RESET BUTTON` on your ESP32. 