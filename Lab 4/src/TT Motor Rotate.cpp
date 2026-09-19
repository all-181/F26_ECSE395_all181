/*#include <Arduino.h>

// TODO: Define your pins
// Hint: Look at your wiring. Which pins did you use?
const int MOTOR_B_1A = 26;
const int MOTOR_B_2A = 25;

void setup() {
  // TODO: Initialize Serial communication
  Serial.begin(115200); // set baud rate

  // TODO: Set your motor pins as OUTPUTs
  pinMode(MOTOR_B_1A, OUTPUT);
  pinMode(MOTOR_B_2A, OUTPUT); 

  Serial.println("Setup complete");
}

void loop() {
  // --- SECTION 1: Clokwise (5s) ---
  Serial.println("Rotate clockwise for 5 seconds");
  
  // TODO: Write HIGH to one pin and LOW to the other
  digitalWrite(MOTOR_B_1A, LOW);
  digitalWrite(MOTOR_B_2A, HIGH);
  
  delay(5000);  // run for 5000ms = 5s

  // --- SECTION 2: Stop (2s) ---
  Serial.println("Stop rotation");
  
  // TODO: Turn off the motor => turn both to low
  digitalWrite(MOTOR_B_1A, LOW);
  digitalWrite(MOTOR_B_2A, LOW);

  delay(2000); // stop for 2000ms = 2s

  // --- SECTION 3: Counterclockwise (5s) ---
  Serial.println("Rotate counterclockwise for 5 seconds");
  
  // TODO: Write HIGH to one pin and LOW to the other
  digitalWrite(MOTOR_B_1A, HIGH);
  digitalWrite(MOTOR_B_2A, LOW);

  delay(5000);

  // --- SECTION 4: Stop (2s) ---
  Serial.println("Stop rotation");
  
  // TODO: Turn off the motor
  digitalWrite(MOTOR_B_1A, LOW);
  digitalWrite(MOTOR_B_2A, LOW);

  delay(2000);
}
*/