/*
 * RotaryEncoder encoder library for Arduino.
 */

#pragma once

#include "stdint.h"


class RotaryEncoder
{
  public:
    enum ButtonState {
      BUTTON_RESET = 0x00,
      BUTTON_PRESSED = 0x01,
      BUTTON_RELEASED = 0x10,
      BUTTON_PRESSED_RELEASED = 0x11
    };

    enum Direction {
      DIRECTION_NONE = 0x00,
      DIRECTION_CW = 0x10,
      DIRECTION_CCW = 0x20
    };

    RotaryEncoder(uint8_t pin1, uint8_t pin2);
    RotaryEncoder(uint8_t pin1, uint8_t pin2, uint8_t buttonPin);

    // read and process pins
    Direction process();

    bool buttonPressedReleased(uint16_t debounce_delay = 50);
    bool buttonPressedHeld(uint16_t delay_millis = 500);
    uint8_t readButton();
    void resetButton();

  private:
  	void init(uint8_t pin1, uint8_t pin2);
    uint8_t state;
    uint8_t pin1;
    uint8_t pin2;
    uint8_t buttonPin;
    uint8_t buttonState;
    uint32_t buttonTimer;
};

