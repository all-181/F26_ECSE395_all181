#include <Arduino.h>



// Put your potentiometer pin assignment here
#define SENSOR_PIN A1

/*void setup() {
    Serial.begin(115200);
    pinMode(SENSOR_PIN, INPUT); // all181: sensor is an input
}

// function to calculate output voltage
float voltage(int analogvalue){
    float voltage;
    //analogRead(sensorPin); gives us 0-4095 values int values
    //use the formula (Analog value*Reference voltage) / (Sensor Resolution) to calculate the output voltage
    voltage = (analogvalue * 3.3) / 4096;  // all181: reference voltage for ESP32 is 3.3V.  Resolution for ESP321 is 4096
    return voltage;
}

void loop() {
    // This is the line for printing in the serial
    // original code: Serial.println(voltage(analogRead(sensorPin)));
    int sensorValue = analogRead(SENSOR_PIN); // all181: This line now reads the sensor pin analong pinout without printing to serial monitor.  The value is stored in a variable.
    float sensorVoltage = voltage(sensorValue); // all181: followed formula to calculate voltage.  
    Serial.println(sensorVoltage); //all181: this line prints voltage
    delay(100);  //all181: this line delays the loop by 100ms before reading and printing the voltage again 
}*/

// take a video of circuit + toggling potentiometer and show serial monitor to prove it is measuring voltage (upload to Canvas)

