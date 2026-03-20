# ESP32 30-pin + 1.54" ST7789 240×240 + EC11 Encoder + GPS + TP4057 LiPo

> 🆕 **New to this project? Start here first:**  
> **[Complete Beginner Setup Guide](../BEGINNER_SETUP_GUIDE.md)** — every step explained
> in plain English, from shopping list to first boot. No prior experience required.

## Overview

This page is the technical reference for the hardware build.
It documents pins, KiCad PCB layout, and firmware config for:
an ESP32 30-pin development board paired with a 1.54" ST7789 SPI TFT + integrated EC11 rotary
encoder module (12-pin header), a 4-pin GPS module, a TP4057-based LiPo charger, and
a 3.7 V LiPo battery. A KiCad PCB and 3D-printed case are provided to house the build.

**Firmware board target:** `MARAUDER_ST7789_EC11_240`

---

## Bill of Materials

| Qty | Part | Notes |
|-----|------|-------|
| 1 | ESP32 30-pin development board | e.g. DOIT ESP32 DEVKIT V1, 30-pin variant |
| 1 | 1.54" ST7789 SPI TFT + EC11 encoder module (12-pin) | 240×240 px, integrated rotary encoder + push button |
| 1 | GPS module, 4-pin (GND / VCC / TX / RX) | e.g. Neo-6M or Neo-8M breakout |
| 1 | TP4057 LiPo charger module | Micro-USB or Type-C input, 1S output |
| 1 | 3.7 V LiPo battery | 500–2000 mAh depending on case size |
| 1 | PCB (fabricated from provided Gerbers) | See `hardware/kicad/esp32_st7789_154_ec11_gps/gerbers/` |
| 4 | M2×5 mm screws | For case assembly |
| – | 22 AWG wire or 2.54 mm Dupont jumper cables | For wiring sub-modules |

---

## Pin/Wiring Reference

### 1.54" ST7789 + Encoder Module (12-pin header)

| Module Pin | Signal | ESP32 GPIO | Notes |
|-----------|--------|------------|-------|
| GND | Ground | GND | |
| VDO | Power | 3.3 V | **3.3 V only** – do not connect 5 V |
| SCL | SPI Clock | GPIO 18 | VSPI CLK |
| SDA | SPI MOSI | GPIO 23 | VSPI MOSI |
| RES | TFT Reset | GPIO 5 | |
| DC | Data/Command | GPIO 16 | |
| CS | Chip Select | GPIO 17 | |
| BLK | Backlight | GPIO 4 | HIGH = on |
| TRA | Encoder A (CLK) | GPIO 32 | |
| TRB | Encoder B (DT) | GPIO 33 | |
| PSH | Encoder push button | GPIO 25 | Active-low, internal pull-up |
| K0 | Extra key | Not connected | Optional; connect to any free GPIO if needed |

### GPS Module (4-pin)

| Module Pin | Signal | ESP32 GPIO | Notes |
|-----------|--------|------------|-------|
| GND | Ground | GND | |
| VCC | Power | 3.3 V | Check module spec – some need 5 V with internal regulator |
| TX | UART TX (module → ESP32) | GPIO 21 (RX2) | UART2 |
| RX | UART RX (ESP32 → module) | GPIO 22 (TX2) | UART2 |

> **Note:** The GPS module's TX connects to the ESP32's RX pin, and vice versa.

### TP4057 LiPo Charger

| Charger Pin | Connection |
|-------------|-----------|
| IN+ / VUSB | USB 5 V input |
| IN– / GND | GND |
| BAT+ | LiPo battery + |
| BAT– | LiPo battery – |
| OUT+ | ESP32 `VIN` (or `3.3V` if using AMS1117 on charger board) |
| OUT– | GND |

> Many TP4057 modules include an onboard AMS1117-3.3 regulator. If yours does, connect
> `OUT+` → ESP32 `3.3V`. If not, connect through a separate 3.3 V LDO.

---

## KiCad PCB

The KiCad project is located at:

```
hardware/kicad/esp32_st7789_154_ec11_gps/
├── esp32_st7789_154_ec11_gps.kicad_pro   # KiCad project file
├── esp32_st7789_154_ec11_gps.kicad_sch   # Schematic
├── esp32_st7789_154_ec11_gps.kicad_pcb   # PCB layout
├── exports/
│   ├── schematic.pdf                      # Schematic export
│   ├── pcb_top.png                        # Top-layer preview
│   ├── pcb_bottom.png                     # Bottom-layer preview
│   └── pcb_assembly.svg                   # Assembly drawing
└── gerbers/
    ├── *.gtl  (top copper)
    ├── *.gbl  (bottom copper)
    ├── *.gts  (top solder mask)
    ├── *.gbs  (bottom solder mask)
    ├── *.gto  (top silkscreen)
    ├── *.gbo  (bottom silkscreen)
    ├── *.drl  (drill file)
    └── *.gko  (board outline)
```

### Ordering the PCB

1. Zip the entire `gerbers/` folder.
2. Upload to your preferred PCB fab (JLCPCB, PCBWay, OSHPark, etc.).
3. Recommended specs: 1.6 mm FR4, 1 oz copper, HASL finish, green solder mask.

---

## 3D-Printed Case

Case files are located at:

```
hardware/case/esp32_st7789_154_ec11_gps_case/
├── case_bottom.stl     # Bottom half of enclosure
├── case_top.stl        # Top half (display window cut-out, encoder hole)
├── case_assembly.3mf   # Combined assembly (optional)
└── PRINT_INSTRUCTIONS.md
```

### Slicing with Creality Print for Ender-3 V3 SE

1. **Open Creality Print** (download from https://www.crealitycloud.com/software-firmware/software).
2. **Select printer:** Ender-3 V3 SE.
3. **Import STL files:** File → Import → `case_bottom.stl`, then repeat for `case_top.stl`.
4. **Slice settings (recommended):**

   | Setting | Value |
   |---------|-------|
   | Layer height | 0.2 mm |
   | Infill | 20% Gyroid |
   | Supports | None (parts are designed to print without supports) |
   | Perimeters | 3 |
   | Top/bottom layers | 4 |
   | Filament | PLA or PETG, 1.75 mm |
   | Nozzle temp | PLA: 200 °C / PETG: 230 °C |
   | Bed temp | PLA: 60 °C / PETG: 80 °C |

5. **Orientation:** Place flat faces down on the build plate.
6. **Slice** and review the preview. Export the `.gcode` file to an SD card.
7. **Print** on the Ender-3 V3 SE. Typical print time: ~2–3 h per half at 0.2 mm.

### Assembly

1. Press the ESP32 dev board into the bottom case half (friction fit or M2 stand-offs).
2. Route the display/encoder ribbon/wires through the top-case opening.
3. Seat the display module into the top-case window.
4. Connect GPS module and LiPo charger inside the bottom half.
5. Close the case and secure with 4× M2×5 mm screws.

---

## Firmware Configuration

### Step 1 – Select the TFT_eSPI user setup

In `User_Setup_Select.h`, uncomment **only** this line (comment out all others):

```cpp
#include <User_Setup_marauder_st7789_154_ec11.h>
```

### Step 2 – Enable the board target

In `esp32_marauder/configs.h`, in the `BOARD TARGETS` block, uncomment:

```cpp
#define MARAUDER_ST7789_EC11_240
```

and comment out any previously active target.

### Step 3 – Build and flash

Using Arduino IDE:
1. Install the **ESP32 board package** (Espressif Systems) via Board Manager.
2. Select **Board:** `DOIT ESP32 DEVKIT V1` (or equivalent 30-pin board).
3. Select **Partition Scheme:** `Minimal SPIFFS (1.9MB APP with OTA/190KB SPIFFS)`.
4. Select the correct **COM port**.
5. Click **Upload** (Ctrl+U).

Using `esptool.py` with a pre-built binary:
```bash
esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 921600 \
  write_flash -z 0x1000 firmware.bin
```

### Step 4 – Verify display

On first boot the splash screen should appear on the ST7789 display. If the screen is
white or colours look inverted, edit `User_Setup_marauder_st7789_154_ec11.h`:

- Toggle `TFT_INVERSION_ON` / `TFT_INVERSION_OFF`.
- Swap `TFT_RGB_ORDER` between `TFT_RGB` and `TFT_BGR`.

### Step 5 – Verify encoder

Rotate the encoder knob – the menu selection should move up or down. If the direction
is reversed, swap `ENCODER_CLK` and `ENCODER_DT` in `configs.h`.

Press the encoder push button to select the highlighted menu item.

---

## GPS Verification

1. Power on with a clear view of the sky.
2. Check the Serial Monitor (115200 baud) for `GPS Attached Successfully`.
3. The status bar on the display shows `GPS` with a satellite count.
4. A red GPS icon means no fix; green means fix acquired.

---

## Troubleshooting

| Symptom | Likely cause | Fix |
|---------|--------------|-----|
| White / blank display | Wrong driver or inversion | Toggle `TFT_INVERSION_ON`/`OFF` in setup file |
| Inverted colours | Wrong colour order | Swap `TFT_RGB_ORDER` |
| Encoder direction reversed | TRA/TRB swapped | Swap `ENCODER_CLK` / `ENCODER_DT` |
| GPS not detected | Wrong UART or wiring | Check TX→RX21, RX→TX22 |
| No compile / undefined | Wrong board target or setup | Ensure only `MARAUDER_ST7789_EC11_240` is defined |
| Backlight off | BLK wiring or pin | Check GPIO 4 → BLK, `TFT_BL 4` in setup |
