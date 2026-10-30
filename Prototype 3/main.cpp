#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h> // all181: includes required library
#include <Adafruit_GFX.h> // all181: includes required library
#include "C:\Users\allan\OneDrive - Case Western Reserve University\org_v1\My Documents\PlatformIO\Projects\Prototype 3 PIO\src\pitches.h" // all181: includes library for buzzer

// OLED 
#define SCREEN_WIDTH 128 // all181: display width in pixels
#define SCREEN_HEIGHT 64 // all181: display height in pixels
#define OLED_RESET -1 // all181: reset pin number
#define SCREEN_ADDRESS 0x3C // all181: screen address (commonly 0x3C, try 0x3D if this does not work)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET); // all181: from test code

// DEFINE INPUTS AND OUTPUTS

// POTENTIOMETER
const int potentiometerPin = 34;  // all181: connected to A2 (analog input)
int potentiometerValue = 0; // all181: initializing a variable to hold the current state of the potentiometer



//START BUTTON 
const int buttonPin = BUTTON; // SW38 on the ESP32
int buttonState = 0; // all181: variable to hold current state of button



// VIBRATION SENSOR (digital input)
const int vibrationPinStop = 26; // all181: connected to 27

// BUZZER
const int buzzerPinOne = 25; //all181: connected to A1 (analog i/o)



int notesList[] = {NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A5};
int notesListHigher[] = {NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A6};
int ourNote = NOTE_C4;
int ourNoteHigher = NOTE_C5;

void showTime(unsigned long ms) {
    unsigned long minutes   = ms / 60000;
    unsigned long seconds   = (ms / 1000) % 60;
    unsigned long millisPart = ms % 1000;        // 0-999 (first digit = tenths)

    char buf[16];
    snprintf(buf, sizeof(buf), "%02lu:%02lu.%03lu", minutes, seconds, millisPart);

    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 28);
    display.print(buf);
    display.display();
}

void setup() {
    // OLED
    Serial.begin(9600); // all181: initialize baud rate for OLED; different from serial monitor
    Wire.begin(22,20);
    Wire.setClock(400000);

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
    pinMode(buttonPin, INPUT);

    // STOP
    pinMode(vibrationPinStop, INPUT); // all181: makes vibration sensor an input

    // BUZZER
    pinMode(buzzerPinOne, OUTPUT);

    // POTENTIOMETER
    pinMode(potentiometerPin, INPUT);

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
    buttonState = digitalRead(buttonPin); // all181: read button value

    if (buttonState == LOW){ // all181: if button is pressed, check what the potentiometer is at!

        potentiometerValue = analogRead(potentiometerPin);

        // choose which note to play (this is the lower octave)
        for (int n = 0; n < 10; n++){
            if (potentiometerValue > 410*n && potentiometerValue < 410*(n+1)){
                ourNote = notesList[n];
                ourNoteHigher = notesListHigher[n];

                display.clearDisplay();
                display.setTextSize(1); // sets text size
                display.setCursor(0,28); // sets cursor position
                display.print("VOLUME:" + String(n) + "/10");
                display.display();
                delay(100);
                
            }
        }

        // play ourNote three times, then play one octave above once
        tone(buzzerPinOne, ourNote, 500);
        delay(500);
        noTone(buzzerPinOne);
        delay(100);

        tone(buzzerPinOne, ourNote, 500);
        delay(500);
        noTone(buzzerPinOne);
        delay(100);

        tone(buzzerPinOne, ourNote, 500);
        delay(500);
        noTone(buzzerPinOne);
        delay(100);   

        tone(buzzerPinOne, ourNoteHigher, 1000);
        delay(1000);
        noTone(buzzerPinOne);
       
                       



unsigned long startTime = millis();
unsigned long elapsed = 0;

while (digitalRead(vibrationPinStop) == 0) {
    elapsed = millis() - startTime;
    showTime(elapsed);              // live updating display
}

// stop detected: grab the final exact time and show it
elapsed = millis() - startTime;
showTime(elapsed);
delay(5000);
display.clearDisplay();
display.display();

    } //else { 
        //delay(100); // all181: add delay of 0.1s between checking if button pressed

    //}


}