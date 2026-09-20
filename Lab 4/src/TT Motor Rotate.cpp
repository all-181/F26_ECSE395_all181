/*#include <Arduino.h>

// Define your pins
const int MOTOR_B_1A = 26;  //all181: found correct pin using esp32 diagram
const int MOTOR_B_2A = 25; //all181: found correct pin using esp32 diagram

void setup() {
  //Initialize Serial communication
  Serial.begin(115200); //all181: set baud rate

  // Set your motor pins as OUTPUTs
  pinMode(MOTOR_B_1A, OUTPUT);
  pinMode(MOTOR_B_2A, OUTPUT); 

  Serial.println("Setup complete");
}

void loop() {
  // --- SECTION 1: Clokwise (5s) ---
  Serial.println("Rotate clockwise for 5 seconds");
  
  //all181: wrote HIGH to one pin and LOW to the other, tested physically to determine this is correct CW configuration
  digitalWrite(MOTOR_B_1A, LOW);
  digitalWrite(MOTOR_B_2A, HIGH);
  
  delay(5000);  // all181: run for 5000ms = 5s

  // --- SECTION 2: Stop (2s) ---
  Serial.println("Stop rotation");
  
  //all181: Turn off the motor => turn both to low
  digitalWrite(MOTOR_B_1A, LOW);
  digitalWrite(MOTOR_B_2A, LOW);

  delay(2000); //all181: stop for 2000ms = 2s

  // --- SECTION 3: Counterclockwise (5s) ---
  Serial.println("Rotate counterclockwise for 5 seconds");
  
  // all181: wrote HIGH to one pin and LOW to the other (opposite configuration as CW)
  digitalWrite(MOTOR_B_1A, HIGH);
  digitalWrite(MOTOR_B_2A, LOW);

  delay(5000);

  // --- SECTION 4: Stop (2s) ---
  Serial.println("Stop rotation");
  
  // all181: Turn off the motor => LOW both
  digitalWrite(MOTOR_B_1A, LOW);
  digitalWrite(MOTOR_B_2A, LOW);

  delay(2000);
}
*/