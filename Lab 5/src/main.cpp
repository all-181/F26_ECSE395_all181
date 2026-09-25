#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h> // all181: includes required library
#include <adafruit_GFX.h> // all181: includes required library


// OLED 
#define SCREEN_WIDTH 128 // all181: display width in pixels
#define SCREEN_HEIGHT 64 //all181: display height in pixels

#define OLED_RESET -1 // all181: reset pin number
#define SCREEN_ADDRESS 0x3C // all181: screen address (commonly 0x3C, try 0x3D if this does not work)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); // all181: from test code


// BUTTON 
const int buttonPin = 26; // all181: connected button sensor to A0
int buttonState = 0; // all181: variable to hold current state of button

// VIBRATION SENSOR 
const int sensorPin = 25; // all181: connected vibration sensor to A1


void setup() {
    // OLED
    Serial.begin(9600); // all181: initialize baud rate for OLED; different from serial monitor

    // all181: check to see if we can write to the OLED screen
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)){
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
        ;
    }
        // Check to see if OLED works
        // all181: These same commands are commonly repeated.  Comments for their functionality are here.
        display.clearDisplay(); // all181: wipes any existing input off of display
        display.setTextSize(1); // all181: sets text size
        display.setTextColor(WHITE); // all181: sets text color
        display.setCursor(0,28); // all181: sets position where text starts (middle left of screen)
        display.println("Loading..."); // all181: write what to display on screen
        display.display(); // all181: displays on screen
        delay(2000); // all181: wait 2s
        display.clearDisplay(); 

    // Button
    pinMode(buttonPin, INPUT); // all181: makes button an input

    // Vibration Sensor
    pinMode(sensorPin, INPUT); // all181: makes vibration sensor an input

    }



void loop() {

    // all181: 1) display opening message
    display.clearDisplay();
        display.setTextSize(1); // sets text size
        display.setTextColor(WHITE); // sets text color
        display.setTextSize(1); // sets text size
        display.setCursor(0,28); // sets cursor position
        display.print("Ready to go!"); // display on screen
        display.display();
        

    // all181: 2) Check if button is pressed.  If pressed, go to step 3.  If not, loop back.
    buttonState = digitalRead(buttonPin); // all181: read button value

    if (buttonState == LOW){ // all181: if button is pressed

        //all181: 3-5) Display "3...2...1..."
        display.clearDisplay();
        display.setTextSize(2); // sets text size
        display.setCursor(0,28); // sets cursor position
        display.print("3");
        display.display();
        delay(1000); // all181: wait a second
        display.clearDisplay();
        display.setTextSize(2); // sets text size
        display.setCursor(0,28); // sets cursor position
        display.print("2");
        display.display();
        delay(1000); // all181: wait a second
        display.clearDisplay();
        display.setTextSize(2); // sets text size
        display.setCursor(0,28); // sets cursor position
        display.print("1");
        display.display();
        delay(1000); // all181: wait a second
        display.clearDisplay();


        // all181: 6) Display "0.0"
        display.setTextSize(2); // sets text size
        display.setCursor(0,28); // sets cursor position
        display.print("0.0");
        display.display();
        float watchTime = 0.0; // all181: initialize time variable

        while (digitalRead(sensorPin) == 0){
            watchTime = watchTime + 0.1; // increment watch time
            display.setTextSize(2); // sets text size
            display.setCursor(0,28); // sets cursor position
            display.print(watchTime,1);
            display.display(); // display watch time, specify 1 decimal place
            delay(100); // delay 100ms = 0.1s
            display.clearDisplay();

        }

        // all181: now, vibration module has been set off
        // all181: display current time for 5 seconds
        display.println(watchTime);
        display.display();
        delay(5000);
        display.clearDisplay();

    } else {
        delay(100); // all181: add delay of 0.1s between checking if button pressed

    }


}