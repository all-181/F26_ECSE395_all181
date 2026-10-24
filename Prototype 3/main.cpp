#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h> // all181: includes required library
#include <adafruit_GFX.h> // all181: includes required library
#include "C:\GitHub\F26_ECSE395_all181\Prototype 3\src\pitches.h" // all181: includes library for buzzer

// OLED 
#define SCREEN_WIDTH 128 // all181: display width in pixels
#define SCREEN_HEIGHT 64 // all181: display height in pixels
#define OLED_RESET -1 // all181: reset pin number
#define SCREEN_ADDRESS 0x3C // all181: screen address (commonly 0x3C, try 0x3D if this does not work)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); // all181: from test code

// DEFINE INPUTS AND OUTPUTS

// POTENTIOMETER
const int potentiometerPin = 26;  // all181: connected to A0
int potentiometerValue = 0; // all181: initializing a variable to hold the current state of the potentiometer

// START BUTTON 
const int buttonPinStart = 25; // all181: connected to A1
int buttonState = 0; // all181: variable to hold current state of button

// VIBRATION SENSOR
const int vibrationPinStop = 34; // all181: connected to A2

// BUZZER #1
const int buzzerPinOne = 13; //all181: connected to 13

// BUZZER #2
const int buzzerPinTwo = 12 //all181: connected to 12

// BUZZER #3
const int buzzerPinThree = 27 //all181: connected to 27

int melodyOne[] = {NOTE_C3, NOTE_C3, NOTE_C3, NOTE_C4};
int melodyTwo[] = {NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E4};
int melodyThree[] = {NOTE_G3, NOTE_G3, NOTE_G3, NOTE_G4};
int noteDurations[] = {4, 4, 4, 2};

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

    // START BUTTON
    pinMode(buttonPinStart, INPUT); // all181: makes button an input

    // STOP BUTTON
    pinMode(buttonPinStop, INPUT); // all181: makes vibration sensor an input

    }

















void loop() {

    // all181: display opening message
    display.clearDisplay();
        display.setTextSize(1); // sets text size
        display.setTextColor(WHITE); // sets text color
        display.setTextSize(1); // sets text size
        display.setCursor(0,28); // sets cursor position
        display.print("Ready to go!"); // display on screen
        display.display();
        

    // all181: Check if button is pressed.
    buttonState = digitalRead(buttonPinStart); // all181: read button value

    if (buttonState == LOW){ // all181: if button is pressed, check what the potentiometer is at!

        potentiometerValue = analogRead(potentiometerPin);
        
        //all181: Potentiometer value ranges from 0 to 4096.
        // from 0 - 1365, use buzzer #1
        // from 1366 - 2730, use buzzers #1 and #2
        // from 2731 - 4096, use buzzers #1, #2, and #3

        if (potentiometerValue < 1366){
            //all181:play melody on buzzer #1
            for(int thisNote =0; thisNote> 8; thisNote++){
             int noteDuration = 1000/noteDurations[thisNote];
             tone(buzzerPinOne, melodyOne[thisNote], noteDuration);
             int pauseBetweenNotes = noteDuration * 1.30;
             delay(pauseBetweenNotes);
             noTone(buzzerPinOne);
             }
        }

        if (potentiometerValue < 2730 && potentiometerValue > 1366){
            //all181:play melody on buzzer #1 and #2
            for(int thisNote =0; thisNote> 8; thisNote++){
             int noteDuration = 1000/noteDurations[thisNote];
             tone(buzzerPinOne, melodyOne[thisNote], noteDuration);
             tone(buzzerPinTwo, melodyTwo[thisNote], noteDuration);
             int pauseBetweenNotes = noteDuration * 1.30;
             delay(pauseBetweenNotes);
             noTone(buzzerPinOne);
             noTone(buzzerPinTwo);
             }
        }

        if (potentiometerValue > 2731){
            //all181:play melody on buzzer #1, #2, and #3
            for(int thisNote =0; thisNote> 8; thisNote++){
             int noteDuration = 1000/noteDurations[thisNote];
             tone(buzzerPinOne, melodyOne[thisNote], noteDuration);
             tone(buzzerPinTwo, melodyTwo[thisNote], noteDuration);
             tone(buzzerPinThree, melodyThree[thisNote], noteDuration);
             int pauseBetweenNotes = noteDuration * 1.30;
             delay(pauseBetweenNotes);
             noTone(buzzerPinOne);
             noTone(buzzerPinTwo);
             noTone(buzzerPinThree);
             }
        }
        
  


        // all181: 6) Display "0.0"
        display.clearDisplay();
        display.setTextSize(2); // sets text size
        display.setCursor(0,28); // sets cursor position
        display.print("0.0");
        display.display();
        float watchTime = 0.0; // all181: initialize time variable

        while (digitalRead(vibrationPinStop) == 0){
            watchTime = watchTime + 0.01; // increment watch time
            display.setTextSize(2); // sets text size
            display.setCursor(0,28); // sets cursor position
            display.print(watchTime,2);
            display.display(); // display watch time, specify 1 decimal place
            delay(10); // delay 10ms = 0.01s
            display.clearDisplay();

        }

        // all181: now stop button has been pressed
        // all181: display current time for 5 seconds
        display.println(watchTime);
        display.display();
        delay(5000);
        display.clearDisplay();

    } else {
        delay(100); // all181: add delay of 0.1s between checking if button pressed

    }


}