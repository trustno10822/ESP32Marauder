#include "RotaryEncoder.h"

RotaryEncoder* RotaryEncoder::instance = nullptr;
portMUX_TYPE RotaryEncoder::mux = portMUX_INITIALIZER_UNLOCKED;

RotaryEncoder::RotaryEncoder() {
  this->clk_pin = 0;
  this->dt_pin = 0;
  this->rotation_count = 0;
  this->last_clk_state = LOW;
}

RotaryEncoder::RotaryEncoder(int clk_pin, int dt_pin) {
  this->clk_pin = clk_pin;
  this->dt_pin = dt_pin;
  this->rotation_count = 0;

  pinMode(clk_pin, INPUT_PULLUP);
  pinMode(dt_pin, INPUT_PULLUP);

  this->last_clk_state = digitalRead(clk_pin);

  instance = this;
  attachInterrupt(digitalPinToInterrupt(clk_pin), RotaryEncoder::isr, FALLING);
}

void IRAM_ATTR RotaryEncoder::isr() {
  if (!instance) return;
  portENTER_CRITICAL_ISR(&mux);
  // On falling edge of CLK: DT HIGH = clockwise, DT LOW = counter-clockwise
  if (digitalRead(instance->dt_pin) == HIGH) {
    instance->rotation_count++;
  } else {
    instance->rotation_count--;
  }
  portEXIT_CRITICAL_ISR(&mux);
}

bool RotaryEncoder::rotatedCW() {
  portENTER_CRITICAL(&mux);
  bool result = (rotation_count > 0);
  if (result) rotation_count = 0;
  portEXIT_CRITICAL(&mux);
  return result;
}

bool RotaryEncoder::rotatedCCW() {
  portENTER_CRITICAL(&mux);
  bool result = (rotation_count < 0);
  if (result) rotation_count = 0;
  portEXIT_CRITICAL(&mux);
  return result;
}
