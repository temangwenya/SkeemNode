/*
 * File: Button.h
 * Project SkeemNode
 * Author: Tema Ngwenya

 * Description: Button class for managing button states on the ESP32.
*/

// Imports/Includes
#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
  private:
    int pin;
    bool lastState;

// Constructors
  public:
    Button(int attachPin) {
      pin = attachPin;
       lastState = HIGH; // HIGH = released (using INPUT_PULLUP)
    }

//Methods
  void begin() {
      pinMode(pin, INPUT_PULLUP);
    }    
  // Check if button is currently pressed
    bool isPressed() {
      return digitalRead(pin) == LOW;
    }

    // Check if the state changed this loop cycle
    bool hasChanged() {
      bool currentState = digitalRead(pin);
      if (currentState != lastState) {
        lastState = currentState;
        return true;
      }
      return false;
    }
};

#endif