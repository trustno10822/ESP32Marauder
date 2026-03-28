#pragma once

#ifndef RotaryEncoder_h
#define RotaryEncoder_h

#include <Arduino.h>

class RotaryEncoder {
  private:
    int clk_pin;
    int dt_pin;
    volatile int8_t rotation_count;
    int last_clk_state;

    static portMUX_TYPE mux;
    static RotaryEncoder* instance;
    static void IRAM_ATTR isr();

  public:
    RotaryEncoder();
    RotaryEncoder(int clk_pin, int dt_pin);

    bool rotatedCW();
    bool rotatedCCW();
// ISR-driven rotary encoder class.
// Tracks CW and CCW ticks in an interrupt-safe manner.
// Usage:
//   RotaryEncoder encoder(CLK_PIN, DT_PIN);
//   encoder.begin();
//   int8_t ticks = encoder.readTicks(); // positive = CW, negative = CCW
class RotaryEncoder {
  public:
    RotaryEncoder(uint8_t clkPin, uint8_t dtPin);

    void begin();

    // Returns accumulated ticks since last call (positive = CW, negative = CCW).
    // Resets the counter after reading.
    int8_t readTicks();

    // Convenience wrappers - consume and check direction since last call
    bool rotatedCW();
    bool rotatedCCW();

  private:
    uint8_t _clkPin;
    uint8_t _dtPin;

    volatile int8_t _ticks;
    portMUX_TYPE _mux;

    uint8_t _lastClk;

    static void IRAM_ATTR isrHandler(void* arg);
    void IRAM_ATTR handleISR();
};

#endif
