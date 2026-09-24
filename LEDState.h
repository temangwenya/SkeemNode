/*
 * File: LEDState.h
 * Project SkeemNode
 * Author: Tema Ngwenya

 * Description: LED State Management Class to manage the RGB LED on the ESP32.
 */

// Imports/Includes
#ifndef STATUSLED_H
#define STATUSLED_H

#include <Arduino.h>


class LEDState {
  private:
    int redPin;
    int greenPin;
    int bluePin;

  public:
    LEDState (int r, int g, int b) {
      redPin = r;
      greenPin = g;
      bluePin = b;
    }
    void begin() {
      pinMode(redPin, OUTPUT);
      pinMode(greenPin, OUTPUT);
      pinMode(bluePin, OUTPUT);
      clear();
    }

    void clear() {
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
    }

    void setColors(bool redState, bool blueState) {
      digitalWrite(redPin, redState ? HIGH : LOW);
      digitalWrite(bluePin, blueState ? HIGH : LOW);
    }
};

#endif