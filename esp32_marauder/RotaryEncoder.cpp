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
RotaryEncoder::RotaryEncoder(uint8_t clkPin, uint8_t dtPin)
  : _clkPin(clkPin), _dtPin(dtPin), _ticks(0), _mux(portMUX_INITIALIZER_UNLOCKED), _lastClk(HIGH)
{
}

void RotaryEncoder::begin() {
  pinMode(_clkPin, INPUT_PULLUP);
  pinMode(_dtPin,  INPUT_PULLUP);
  _lastClk = digitalRead(_clkPin);
  attachInterruptArg(digitalPinToInterrupt(_clkPin), isrHandler, this, CHANGE);
}

void IRAM_ATTR RotaryEncoder::isrHandler(void* arg) {
  static_cast<RotaryEncoder*>(arg)->handleISR();
}

void IRAM_ATTR RotaryEncoder::handleISR() {
  uint8_t clkState = digitalRead(_clkPin);
  if (clkState == _lastClk) return;   // noise / bounce guard
  _lastClk = clkState;

  portENTER_CRITICAL_ISR(&_mux);
  if (clkState == LOW) {
    // Falling edge on CLK
    if (digitalRead(_dtPin) == HIGH)
      _ticks++;  // CW
    else
      _ticks--;  // CCW
  }
  portEXIT_CRITICAL_ISR(&_mux);
}

int8_t RotaryEncoder::readTicks() {
  int8_t val;
  portENTER_CRITICAL(&_mux);
  val   = _ticks;
  _ticks = 0;
  portEXIT_CRITICAL(&_mux);
  return val;
}

// Peek at current tick sign without consuming - use readTicks() to consume.
bool RotaryEncoder::rotatedCW() {
  int8_t val;
  portENTER_CRITICAL(&_mux);
  val = _ticks;
  portEXIT_CRITICAL(&_mux);
  return val > 0;
}

bool RotaryEncoder::rotatedCCW() {
  int8_t val;
  portENTER_CRITICAL(&_mux);
  val = _ticks;
  portEXIT_CRITICAL(&_mux);
  return val < 0;
}
