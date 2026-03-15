//                            USER DEFINED SETTINGS
//   Set driver type, fonts to be loaded, pins used and SPI control method etc.
//
//   ESP32 Marauder – 1.54" 240×240 ST7789 display + EC11 rotary encoder
//
//   Default pin assignments (adjust to match your wiring):
//     Display MOSI → GPIO 23    Display SCLK → GPIO 18
//     Display CS   → GPIO 17    Display DC   → GPIO 16
//     Display RST  → GPIO 5     Display BL   → GPIO 4
//     Encoder CLK  → GPIO 32    Encoder DT   → GPIO 33
//     Encoder SW   → GPIO 25    SD CS        → GPIO 22

// ##################################################################################
//
// Section 1. Driver & display options
//
// ##################################################################################

#define ST7789_DRIVER

// Many 1.54" ST7789 modules need colour inversion to display correctly.
// If colours appear inverted after flashing, comment out the line below.
#define TFT_INVERSION_ON

#define TFT_WIDTH  240
#define TFT_HEIGHT 240

#define TFT_BACKLIGHT_ON HIGH

// ##################################################################################
//
// Section 2. Pin definitions
//
// ##################################################################################

#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_CS   17
#define TFT_DC   16
#define TFT_RST   5
#define TFT_BL    4

#define TOUCH_CS -1

// ##################################################################################
//
// Section 3. Fonts
//
// ##################################################################################

#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8
#define LOAD_GFXFF
#define SMOOTH_FONT

// ##################################################################################
//
// Section 4. Other options
//
// ##################################################################################

#define SPI_FREQUENCY      40000000
#define SPI_READ_FREQUENCY 20000000
#define SPI_TOUCH_FREQUENCY 2500000
