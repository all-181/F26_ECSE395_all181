#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h> // includes required library
#include <adafruit_GFX.h> // includes required library


// OLED STUFF
#define SCREEN_WIDTH 128 // display width in pixels
#define SCREEN_HEIGHT 6 // display height in pixels

#define OLED_RESET -1 // all181: reset pin number
#define SCREEN_ADDRESS 0x3C // all181: 

Adafruit_SSD1306
display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



// BUTTON STUFF
const int buttonPin = 26; // all181:
const int ledPin = 25; // all181: 
int buttonState = 0; // variable to hold current state of button

// VIBRATION SENSOR STUFF
const int sensorPin = 34; // all181:


void setup() {
    // OLED
    Serial.begin(9600); //initialize baud rate for OLED

        display.clearDisplay();
        display.setTextSize(1); // sets text size
        display.setTextColor(WHITE); // sets text color
        display.setCursor(0,28); // sets cursor position
        display.println("Ready?"); // display on screen
        delay(2000); // wait 2s
        display.clearDisplay(); // clear screen

    // Button
    pinMode(buttonPin, INPUT); // makes button an input
    pinMode(ledPin, OUTPUT); // all181:

    // Vibration Sensor
    pinMode(sensorPin, INPUT); // makes vibration sensor an input

    }



void loop() {


    // 1) display opening message
    display.clearDisplay();
        display.setTextSize(1); // sets text size
        display.setTextColor(WHITE); // sets text color
        display.setCursor(0,28); // sets cursor position
        display.println("Ready to go!"); // display on screen
        display.display();
        

    // 2) Check if button is pressed.  If pressed, go to step 3.  If not, loop back.
    buttonState = digitalRead(buttonPin); // HIGH is pressed, LOW is not pressed

    if (buttonPin == HIGH){

        // 3-5) Display "3...2...1..."
        display.clearDisplay();
        display.println("3");
        display.display();
        delay(1000);
        display.clearDisplay();
        display.println("2");
        display.display();
        delay(1000);
        display.clearDisplay();
        display.println("1");
        display.display();
        delay(1000);
        display.clearDisplay();


        // 6) Display "0.0"
        display.println("0.0");
        display.display();
        float watchTime = 0.0;

        while (digitalRead(sensorPin) == 0){
            watchTime = watchTime + 0.1; // increment watch time
            display.println(watchTime,1);
            display.display(); // display watch time, specify 1 decimal place
            delay(100); // delay 100ms = 0.1s
            display.clearDisplay();

        }

        // now, vibration module has been set off
        // display current time for 5 seconds
        display.println(watchTime);
        display.display();
        delay(5000);
        display.clearDisplay();

    } else {
        delay(100); // all181: add delay of 0.1s between checking if button pressed

    }


}