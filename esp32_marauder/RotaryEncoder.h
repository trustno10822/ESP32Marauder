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
};

#endif
