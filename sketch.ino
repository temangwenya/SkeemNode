/* FILE INFO: 
  * File: SkeemNode.ino
  * Project SkeemNode
  * Author: Tema Ngwenya

  * Description: Main Hardware Sketch for SkeemNode
    * This sketch is designed to run on an ESP32 microcontroller and manage two buttons and an RGB LED.
    * It utilizes the Button and LEDState classes to handle button states and LED color output.
 */


/* DEVELOPER NOTE:
  * BUTTON_1 = Silent SOS (BLUE)
  * BUTTON_2 = Loud Alarm (RED) */

// Imports/Includes
#include <Arduino.h>
#include "Button.h"
#include "LEDState.h"


// Instantiate hardware objects with their pins
Button button1(4); // Silent SOS (Default)
Button button2(5); // Loud Alarm
LEDState ledState(16, 15, 2); // Red, Green, Blue pins

void setup() {
  // Start up Serial Monitor
  Serial.begin(115200);
  Serial.println("SkeemNode Serial Monitor");
  Serial.println("------------------------");
  Serial.println("");

  // Initialize objects
  button1.begin();
  button2.begin();
  ledState.begin();

  
}

void loop() {
  bool btn1On = button1.isPressed();
  bool btn2On = button2.isPressed();

  // Update LED state via object method
  ledState.setColors(btn2On, btn1On);

  // Log only when a button state changes
  if (button1.hasChanged() || button2.hasChanged()) {
    if (btn1On && btn2On) {
      Serial.println("[STATE] Button 1: ON  | Button 2: ON  -- MAGENTA");
    } else if (btn1On) {
      Serial.println("[STATE] Button 1: ON  | Button 2: OFF -- BLUE");
    } else if (btn2On) {
      Serial.println("[STATE] Button 1: OFF | Button 2: ON  -- RED");
    } else {
      Serial.println("[STATE] Button 1: OFF | Button 2: OFF -- CLEAR");
    }
  }

  delay(20); // Delay to make serial monitor readable
}