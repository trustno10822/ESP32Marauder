//                            USER DEFINED SETTINGS
//   Set driver type, fonts to be loaded, pins used and SPI control method etc
//
//   This setup file is for the ESP32 30-pin dev board with a 1.54" ST7789
//   240x240 SPI TFT + integrated EC11 rotary encoder (12-pin module).
//   Module pinout (module label -> ESP32 GPIO):
//     GND  -> GND
//     VDO  -> 3.3V
//     SCL  -> GPIO 18 (SCLK)
//     SDA  -> GPIO 23 (MOSI)
//     RES  -> GPIO  5 (RST)
//     DC   -> GPIO 16 (DC)
//     CS   -> GPIO 17 (CS)
//     BLK  -> GPIO  4 (Backlight)
//     TRA  -> GPIO 32 (Encoder CLK / A)
//     TRB  -> GPIO 33 (Encoder DT  / B)
//     PSH  -> GPIO 25 (Encoder push button)
//     K0   -> (optional extra key, not used by default)

// Only define one driver; ST7789 for this 1.54" 240x240 module
#define ST7789_DRIVER

// No MISO on this write-only 12-pin module
// #define TFT_MISO -1

// ST7789 240x240 portrait dimensions
#define TFT_WIDTH  240
#define TFT_HEIGHT 240

// Colour order - try TFT_RGB first; change to TFT_BGR if colours look wrong
#define TFT_RGB_ORDER TFT_RGB

// Some 1.54" ST7789 panels need inversion to display correct colours
#define TFT_INVERSION_ON

// Backlight: HIGH = on
#define TFT_BACKLIGHT_ON HIGH

// Pin definitions - ESP32 hardware SPI (VSPI)
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS   17
#define TFT_DC   16
#define TFT_RST   5
#define TFT_BL    4  // Backlight control (BLK pin on module)

#define TOUCH_CS -1  // No touch controller on this module

// Fonts
#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF
#define SMOOTH_FONT

// SPI clock - 40 MHz is typically fine for ST7789
#define SPI_FREQUENCY  40000000
#define SPI_READ_FREQUENCY  6000000
#define SPI_TOUCH_FREQUENCY 2500000
