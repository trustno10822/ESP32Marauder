# Complete Beginner Setup Guide
## ESP32 Marauder — 1.54" ST7789 Display + Rotary Encoder + GPS + LiPo Battery

**Who this guide is for:** You have never programmed a microcontroller before,
or you have but want every detail spelled out.
Every step is written assuming you are starting from zero.

---

## Table of Contents

1. [What the project does](#1-what-the-project-does)
2. [Shopping list](#2-shopping-list)
3. [Tools you will need](#3-tools-you-will-need)
4. [Install Arduino IDE 2](#4-install-arduino-ide-2)
5. [Add ESP32 board support to Arduino IDE](#5-add-esp32-board-support-to-arduino-ide)
6. [Install the required libraries](#6-install-the-required-libraries)
7. [Download the ESP32 Marauder code](#7-download-the-esp32-marauder-code)
8. [Understand the two files you must edit](#8-understand-the-two-files-you-must-edit)
9. [Edit User\_Setup\_Select.h](#9-edit-user_setup_selecth)
10. [Edit configs.h](#10-edit-configh)
11. [Wire the display module to the ESP32](#11-wire-the-display-module-to-the-esp32)
12. [Wire the GPS module to the ESP32](#12-wire-the-gps-module-to-the-esp32)
13. [Wire the TP4057 charger and LiPo battery](#13-wire-the-tp4057-charger-and-lipo-battery)
14. [Double-check all your wiring](#14-double-check-all-your-wiring)
15. [Build and flash the firmware](#15-build-and-flash-the-firmware)
16. [First-boot checks](#16-first-boot-checks)
17. [Using the rotary encoder](#17-using-the-rotary-encoder)
18. [3D-print the case](#18-3d-print-the-case)
19. [Put everything in the case](#19-put-everything-in-the-case)
20. [Troubleshooting](#20-troubleshooting)

---

## 1. What the project does

ESP32 Marauder is open-source firmware that turns an ESP32 microcontroller into a
Wi-Fi and Bluetooth security testing tool.
This guide specifically sets up the build that uses:

- A small 1.54-inch colour display so you can see what the device is doing.
- A rotary knob (encoder) you twist and click to navigate the menus.
- A GPS module so the device can log where scans were done.
- A rechargeable LiPo battery so you can use it unplugged.

> **Important:** Only use this device on networks and devices you own or have
> explicit permission to test. Unauthorised scanning is illegal in most countries.

---

## 2. Shopping list

You can find every part by searching the exact name or number below on Amazon,
AliExpress, eBay, Adafruit, SparkFun, or a local electronics shop.

| # | Part | What to search | Approximate cost |
|---|------|----------------|-----------------|
| 1 | **ESP32 30-pin development board** | "DOIT ESP32 DEVKIT V1 30 pin" | $5–$10 |
| 2 | **1.54" ST7789 SPI TFT + EC11 encoder module (12-pin)** | "1.54 inch ST7789 rotary encoder TFT 12 pin" | $8–$15 |
| 3 | **GPS module 4-pin** | "Neo-6M GPS module" or "GY-NEO6MV2" | $5–$10 |
| 4 | **TP4057 LiPo charger module** | "TP4057 1S LiPo charger module micro USB" | $1–$3 |
| 5 | **3.7 V LiPo battery** | "3.7V 502035 400mAh LiPo flat battery JST" | $3–$6 |
| 6 | **Dupont jumper wires (female-to-female)** | "20cm female to female dupont jumper wire 40pcs" | $2–$4 |
| 7 | **Micro-USB cable** (to flash + charge) | You probably have one already | — |
| 8 | **4× M2×5 mm screws** (for the case) | "M2 5mm self-tapping screw" | < $1 |

> **Tip:** If the 12-pin display module does not say "ST7789" on the listing, look for
> one with the exact 12 pin labels: GND, VDO, SCL, SDA, RES, DC, CS, BLK, TRA, TRB,
> PSH, K0 printed on the PCB or in the description. That is the right one.

---

## 3. Tools you will need

- A computer running **Windows 10/11**, **macOS 12+**, or **Ubuntu 20.04+**.
- A **Micro-USB cable** that carries data (many cheap charging-only cables do not work
  for flashing — if the computer does not see the device, try a different cable).
- **Small flathead and Phillips screwdrivers** (for case assembly).
- **Needle-nose pliers** (optional but helpful for jumper wires).
- **Soldering iron** — only needed if you want permanent connections; jumper wires are
  fine for a breadboard prototype.
- A **3D printer** (Ender-3 V3 SE or similar) if you want to print the case.
  The case is optional — the project works fine without one.

---

## 4. Install Arduino IDE 2

Arduino IDE is the program you use on your computer to write code and send it to the
ESP32. We need version **2** (not the older version 1.8).

### Windows

1. Open your web browser and go to: **https://www.arduino.cc/en/software**
2. Under "Arduino IDE 2", click **"Windows Win 10 and newer, 64 bits"**.
3. A page will ask you to donate or "just download". Click **"Just Download"**.
4. Your browser will download a file called something like
   `arduino-ide_2.x.x_Windows_64bit.exe`.
5. Double-click that file.
6. The installer will open. Click **"I Agree"** → **"Next"** → **"Install"**.
7. When it finishes, click **"Finish"**. Arduino IDE is now installed.
8. Find **Arduino IDE** in your Start menu or desktop and open it.
   The first time it opens, it may take a minute to load.

### macOS

1. Go to **https://www.arduino.cc/en/software**
2. Click **"macOS Intel"** or **"macOS Apple Silicon"** depending on your Mac
   (Apple Silicon = M1/M2/M3 chip; older Macs use Intel).
3. Download and open the `.dmg` file.
4. Drag the **Arduino IDE** icon into your **Applications** folder.
5. Open it from Applications. If macOS says "can't open because it's from an
   unidentified developer", go to **System Settings → Privacy & Security** and click
   **"Open Anyway"**.

### Linux (Ubuntu/Debian)

1. Go to **https://www.arduino.cc/en/software**
2. Click **"Linux 64 bits"**.
3. Download the `.AppImage` file.
4. Open a terminal and run:
   ```bash
   chmod +x arduino-ide_2.x.x_Linux_64bit.AppImage
   ./arduino-ide_2.x.x_Linux_64bit.AppImage
   ```
5. On Ubuntu you may also install via the Snap store:
   ```bash
   sudo snap install arduino
   ```

---

## 5. Add ESP32 board support to Arduino IDE

By default, Arduino IDE only knows about Arduino boards. We need to teach it about
ESP32 microcontrollers.

1. Open **Arduino IDE**.
2. Click the menu **File → Preferences** (on macOS: **Arduino IDE → Settings**).
3. Find the field labelled **"Additional boards manager URLs"**.
4. Click the small icon at the right end of that field (it looks like two overlapping
   squares) to open a multi-line editor.
5. On a **new line**, paste exactly this URL:
   ```
   https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
   ```
6. Click **OK**, then click **OK** again to close Preferences.
7. Now open the **Boards Manager**: click the icon on the left sidebar that looks like
   a circuit board, or go to **Tools → Board → Boards Manager**.
8. In the search box, type: `esp32`
9. You will see a result called **"esp32 by Espressif Systems"**.
   Click **Install**. This may take a few minutes — it is downloading everything
   needed to compile code for the ESP32.
10. When the progress bar finishes and you see the **"Installed"** badge, close the
    Boards Manager panel.

---

## 6. Install the required libraries

Libraries are pre-written code that the firmware depends on. We need to install several.

### Method: Library Manager (recommended for most libraries)

1. In Arduino IDE, click the **Library Manager** icon on the left sidebar
   (it looks like a stack of books), or go to **Sketch → Include Library → Manage Libraries**.
2. Use the search box to find and install each library in the table below.
   For each one: search → click the result → click **Install**.
   If asked to install dependencies, click **Install all**.

| Library name to search | Author | Notes |
|------------------------|--------|-------|
| `TFT_eSPI` | Bodmer | Display driver — **required** |
| `MicroNMEA` | Steve Marple | GPS sentence parsing |
| `LinkedList` | ivanseidel | Data structures used internally |
| `SoftwareSerial` | (built-in for ESP32) | May already be present |

> **Note:** After installing `TFT_eSPI`, Arduino IDE may warn you that the library
> needs a user setup file. That is normal — we will fix that in a later step.

### The remaining library is installed differently

`ESPAsyncWebServer` is included directly in the Marauder repository. You do **not**
need to install it separately.

---

## 7. Download the ESP32 Marauder code

### Option A — Download as a ZIP (easiest, no Git required)

1. Open your browser and go to:
   **https://github.com/trustno10822/ESP32Marauder**
2. Click the green **"Code"** button near the top right.
3. In the dropdown, click **"Download ZIP"**.
4. Save the file somewhere easy to find, like your Desktop.
5. **Extract / unzip** the downloaded file:
   - **Windows:** Right-click the zip → "Extract All" → choose a location → Extract.
   - **macOS:** Double-click the zip — it extracts automatically into the same folder.
   - **Linux:** `unzip ESP32Marauder-main.zip`
6. You should now have a folder called `ESP32Marauder-main` (or similar).
   Inside it you will find folders like `esp32_marauder`, `libraries`,
   `User_Setup_Select.h`, etc.

### Option B — Clone with Git (if you know Git)

```bash
git clone https://github.com/trustno10822/ESP32Marauder.git
cd ESP32Marauder
```

---

## 8. Understand the two files you must edit

Before you can build the firmware, you need to change exactly **two lines** across
**two files**. This is like telling the software which hardware it is running on.

| File | What you change | Why |
|------|----------------|-----|
| `User_Setup_Select.h` (in the root folder) | Uncomment one `#include` line | Tells the display library which screen type to use |
| `esp32_marauder/configs.h` | Uncomment one `#define` line | Tells the firmware which board it is running on |

A line that starts with `//` is **commented out** (disabled).
Removing the `//` **enables** that line.

---

## 9. Edit User\_Setup\_Select.h

This file is in the **root folder** of the project (the top-level folder you unzipped).

1. Open **Arduino IDE**.
2. Go to **File → Open**.
3. Navigate to the `ESP32Marauder-main` folder, then open the folder
   `esp32_marauder` inside it, and open the file `esp32_marauder.ino`.
   *(The `.ino` file is the main sketch — opening it also loads all the other files.)*
4. In the tabs along the top of the editor you will **not** see `User_Setup_Select.h`
   directly — it lives one level up.  
   The easiest way to edit it is to open it separately:
   - Go to **File → Open** again.
   - Navigate up one folder to `ESP32Marauder-main`.
   - Open `User_Setup_Select.h`.
   - It opens in a new Arduino IDE window.

5. You are now looking at a long file full of commented-out `#include` lines.
   Look for this line (it is near the bottom of the `#include` block):

   ```cpp
   //#include <User_Setup_marauder_st7789_154_ec11.h>  // ESP32 30-pin + 1.54" ST7789 ...
   ```

6. Remove the `//` at the very start of that line so it reads:

   ```cpp
   #include <User_Setup_marauder_st7789_154_ec11.h>  // ESP32 30-pin + 1.54" ST7789 ...
   ```

7. **Make sure every other `#include` line in that block is commented out** (has `//`
   at the start). Only **one** should be active. Scroll up and down to check.
   If you see any others without `//`, add `//` to the front of them.

8. Press **Ctrl+S** (Windows/Linux) or **Cmd+S** (macOS) to save the file.

---

## 10. Edit configs.h

This file is inside the `esp32_marauder` subfolder.

1. In Arduino IDE, go back to the window that has `esp32_marauder.ino` open.
2. Look at the tabs at the top of the code editor. Click the tab labelled **`configs`**
   (or `configs.h`).
   - If you do not see it, try clicking the small **right-arrow** at the far right of
     the tab bar to scroll through more tabs.
3. Near the top of `configs.h`, you will see a block of lines that look like this:

   ```cpp
   //// BOARD TARGETS
   //#define MARAUDER_M5STICKC
   //#define MARAUDER_MINI
   //#define MARAUDER_V7
   ... (many more commented-out lines) ...
   //#define MARAUDER_ST7789_EC11_240 // ESP32 30-pin + 1.54" ST7789 ...
   //// END BOARD TARGETS
   ```

4. Find the line that says:

   ```cpp
   //#define MARAUDER_ST7789_EC11_240
   ```

5. Remove the `//` at the start so it reads:

   ```cpp
   #define MARAUDER_ST7789_EC11_240
   ```

6. **Make sure all other `#define` lines in that block still have `//`** in front of
   them. There should be exactly **one** active board target.

7. Save with **Ctrl+S** / **Cmd+S**.

---

## 11. Wire the display module to the ESP32

### What you have

Your 1.54" display module has a **12-pin header**. The pins are labelled on the PCB.
Your ESP32 30-pin dev board has labelled pins on both long edges.

> **Safety first:** Do NOT connect anything to power yet. Wire everything up
> with the board **unplugged** from USB.

### Colour-code suggestion

Use different coloured Dupont wires to keep track. A common convention:
- **Black** = GND
- **Red** = 3.3 V / power
- **Yellow** = clock signals
- **Green/Blue** = data
- **White/Orange** = control signals

### Connection table

Connect each display pin to the corresponding ESP32 pin using a Dupont jumper wire.
Find the pin label on both sides and connect them one at a time.

| Display pin label | → | ESP32 pin label |
|-------------------|---|----------------|
| **GND** | → | **GND** (any GND pin; there are several) |
| **VDO** | → | **3.3V** (the pin labelled "3V3" or "3.3V") ⚠️ NOT 5V |
| **SCL** | → | **GPIO18** (also labelled "D18" or "18") |
| **SDA** | → | **GPIO23** (also labelled "D23" or "23") |
| **RES** | → | **GPIO5** (also labelled "D5" or "5") |
| **DC** | → | **GPIO16** (also labelled "D16" or "16") |
| **CS** | → | **GPIO17** (also labelled "D17" or "17") |
| **BLK** | → | **GPIO4** (also labelled "D4" or "4") |
| **TRA** | → | **GPIO32** (also labelled "32") |
| **TRB** | → | **GPIO33** (also labelled "33") |
| **PSH** | → | **GPIO25** (also labelled "25") |
| **K0** | → | Leave unconnected (not used) |

### Finding pins on the ESP32 dev board

ESP32 30-pin boards have a silkscreen (white text) next to each pin.
The pins run down both long edges.
- One edge has: EN, VP(36), VN(39), D34, D35, D32, D33, D25, D26, D27, D14, D12, D13, GND, VIN
- Other edge: 3V3, GND, D15, D2, D4, RX2(16), TX2(17), D5, D18, D19, D21, RX0, TX0, D22, D23

> **Tip:** If you can not read the tiny labels, search "ESP32 DEVKIT V1 30 pin pinout"
> and print or open the pinout diagram next to you while wiring.

### Step-by-step wiring for the display

Work through the table above one row at a time:

1. Pick up a black wire. Push one end into the **GND** hole on the display module's
   12-pin header. Push the other end into any **GND** pin on the ESP32.
2. Pick up a red wire. Push one end into **VDO** on the display. Push the other
   into the **3V3** pin on the ESP32. ⚠️ Double-check this is 3V3, not VIN (5V).
3. Continue through the rest of the table the same way.
4. The **K0** pin has nothing connected to it — leave it empty.

---

## 12. Wire the GPS module to the ESP32

Your GPS module (e.g., Neo-6M) has **4 pins** labelled on its PCB.

| GPS pin label | → | ESP32 pin label |
|---------------|---|----------------|
| **GND** | → | **GND** (any remaining GND pin) |
| **VCC** | → | **3.3V** (same 3V3 rail; most Neo-6M modules work at 3.3 V) |
| **TX** | → | **GPIO21** — *this is the ESP32's RECEIVE pin* |
| **RX** | → | **GPIO22** — *this is the ESP32's TRANSMIT pin* |

> **Why does TX go to GPIO21 and not a "TX" pin?**  
> The GPS module's TX (transmit) wire must connect to the ESP32's RX (receive) — they
> talk to each other in opposite directions. GPIO21 is used as RX2 in the firmware.
> Think of it like two people talking: one person's mouth (TX) goes into the other
> person's ear (RX).

---

## 13. Wire the TP4057 charger and LiPo battery

The TP4057 module charges your LiPo battery from USB and then powers the ESP32.

### What the charger module looks like

It is a small PCB, roughly 2–3 cm long, with:
- A Micro-USB port on one end (plug your phone charger cable in here to charge).
- Pads or pins labelled **BAT+**, **BAT–**, and sometimes **OUT+**, **OUT–** or **5V**, **GND**.
- Sometimes a small LED that glows red while charging and turns off when full.

### Connecting the battery

Most TP4057 modules come with (or accept) a small 2-pin JST connector for the battery.

1. Connect the **LiPo battery's positive wire (red)** to the **BAT+** pad/pin on the
   charger module.
2. Connect the **LiPo battery's negative wire (black)** to the **BAT–** pad/pin.

> ⚠️ **Never reverse battery polarity.** Red = positive (+), Black = negative (−).
> A reversed battery can permanently damage both the charger and the battery.

### Connecting the charger output to the ESP32

Some TP4057 breakout boards include a built-in AMS1117 3.3 V regulator and have
pins labelled **OUT+** and **OUT–** (or **3.3V out** and **GND**).

- **If your board has OUT+ and OUT– / 3.3V out:** Connect OUT+ → ESP32 **3V3** and
  OUT– → ESP32 **GND**.
- **If your board only has BAT+ as an output** (raw 3.7–4.2 V):  
  Connect BAT+ → ESP32 **VIN** (the 5V tolerant power input). The ESP32's onboard
  AMS1117 will regulate it down to 3.3 V.

> **Ask yourself:** Does the ESP32 dev board have a `VIN` pin?  
> If yes, and your charger outputs raw battery voltage, use VIN.  
> If the charger has a regulated 3.3 V output, use 3V3.

### Summary

```
USB power source (phone charger)
    |
    ↓ (Micro-USB cable)
TP4057 module
    ├── BAT+ ←→ LiPo battery red wire (+)
    ├── BAT– ←→ LiPo battery black wire (−)
    ├── OUT+ / 3.3V ──→ ESP32 3V3 (or VIN if raw voltage)
    └── OUT– / GND  ──→ ESP32 GND
```

---

## 14. Double-check all your wiring

Before plugging anything into USB, go through this checklist slowly and carefully.

- [ ] **Display VDO** is connected to **ESP32 3V3**, NOT 5V/VIN.
- [ ] **Display GND** is connected to **ESP32 GND**.
- [ ] **SCL → GPIO18**, **SDA → GPIO23**, **RES → GPIO5**, **DC → GPIO16**,
      **CS → GPIO17**, **BLK → GPIO4** — all correct.
- [ ] **TRA → GPIO32**, **TRB → GPIO33**, **PSH → GPIO25** — encoder pins correct.
- [ ] **GPS TX → GPIO21**, **GPS RX → GPIO22** — not backwards.
- [ ] **GPS VCC → 3V3**, **GPS GND → GND**.
- [ ] **Battery polarity correct** (red to BAT+, black to BAT–) on charger.
- [ ] No wires are touching each other where they should not be (no bare metal contact
      between different signal wires).
- [ ] Dupont connectors are fully seated (pushed all the way in).

---

## 15. Build and flash the firmware

Now we compile (build) the code and send (flash) it to the ESP32.

### Step 1 — Open the sketch

In Arduino IDE, go to **File → Open** and navigate to:

```
ESP32Marauder-main/
  esp32_marauder/
    esp32_marauder.ino
```

Open `esp32_marauder.ino`. A row of file tabs will appear at the top — that is normal;
the project has many files.

### Step 2 — Select the correct board

1. Click **Tools → Board → esp32 → DOIT ESP32 DEVKIT V1**  
   *(If you do not see "DOIT ESP32 DEVKIT V1", choose "ESP32 Dev Module" instead —
   they are the same thing.)*
2. Click **Tools → Partition Scheme → Minimal SPIFFS (1.9MB APP with OTA/190KB SPIFFS)**

### Step 3 — Connect the ESP32 to your computer

1. Use a Micro-USB cable to connect the ESP32 dev board to your computer.
   Use one of the board's built-in USB ports (most 30-pin boards have a Micro-USB
   port on the short end).
2. **Windows:** Your computer may ask to install a driver.
   - If the board uses a **CH340** chip (common on cheap boards), download the driver
     from: https://www.wch.cn/downloads/CH341SER_EXE.html
   - If the board uses a **CP2102** chip, download from:
     https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers
   - Install the driver, then unplug and replug the USB cable.
3. **macOS / Linux:** Usually no driver needed.

### Step 4 — Select the COM port

1. In Arduino IDE, click **Tools → Port**.
2. You should see a new port appear (it was not there before you plugged in the cable).
   - **Windows:** It will be called something like `COM3` or `COM4`.
   - **macOS:** Something like `/dev/cu.usbserial-XXXX`.
   - **Linux:** Something like `/dev/ttyUSB0`.
3. Click that port to select it.

> **What if no new port appears?**
> - Try a different USB cable (many cheap cables are charge-only and have no data wires).
> - Try a different USB port on your computer.
> - On Windows, open Device Manager and look under "Ports (COM & LPT)" — if there is
>   a yellow warning triangle, the driver is not installed correctly.

### Step 5 — Upload speed

1. Click **Tools → Upload Speed → 921600** (fastest; reduces wait time).
   If you get upload errors later, try **460800** or **115200**.

### Step 6 — Compile and upload

1. Click the **right-pointing arrow (→)** button in the top-left of Arduino IDE
   (or press **Ctrl+U** / **Cmd+U**). This compiles AND uploads in one step.
2. You will see a progress bar and text scrolling in the bottom panel.
   This takes **2–5 minutes** the first time — it is compiling a lot of code.
3. Look for this at the bottom when it finishes:

   ```
   Leaving...
   Hard resetting via RTS pin...
   ```

   That means the upload was successful! 🎉

> **If you see red error text:**  
> Read the first red line carefully. Common errors and fixes are in the
> [Troubleshooting](#20-troubleshooting) section at the end of this guide.

---

## 16. First-boot checks

After a successful upload, the ESP32 resets automatically and runs the new firmware.

### Check 1 — Display turns on

The 1.54" screen should light up and show the ESP32 Marauder splash screen
(the project name and version). This confirms the display wiring and driver are correct.

**If the screen stays white/blank or shows garbage:**  
See [Troubleshooting](#20-troubleshooting) → "Display is white" or "Display shows garbage".

### Check 2 — Serial Monitor confirms boot

1. In Arduino IDE, click **Tools → Serial Monitor** (or press **Ctrl+Shift+M**).
2. In the bottom-right of the Serial Monitor, set the baud rate to **115200**.
3. Press the **EN (Reset)** button on the ESP32 dev board.
4. You should see text scroll by, ending with something like:

   ```
   ESP-IDF version is: ...
   GPS Attached Successfully
   ```
   or
   ```
   GPS Not Found
   ```

   Either is OK at this stage — GPS requires you to be outdoors with a clear sky.

### Check 3 — Encoder works

After the splash screen, the device shows the main menu.
Slowly twist the rotary knob.
- Turning it **clockwise** should move the menu selection **down**.
- Turning it **counter-clockwise** should move the selection **up**.

**If it moves the wrong direction:**  
See [Troubleshooting](#20-troubleshooting) → "Encoder direction reversed".

### Check 4 — GPS (outdoors)

Take the device outside where the sky is visible.
Wait up to **2 minutes** for the GPS to acquire a satellite fix.
The status bar at the top of the display shows a GPS icon:
- 🔴 **Red** = no fix yet (still searching).
- 🟢 **Green** = fix acquired, you can see a satellite count.

---

## 17. Using the rotary encoder

The encoder is your main way of interacting with the device.

| Action | What it does |
|--------|-------------|
| Turn knob **clockwise** | Move menu selection **down** |
| Turn knob **counter-clockwise** | Move menu selection **up** |
| **Press (click)** the knob | **Select** the highlighted menu item |
| **Press** the knob while a scan is running | Stop the scan and return to menu |

Navigate to a menu item, press the knob to enter it, then use the knob to start
scans or attacks. Press the knob at any time to go back or stop.

---

## 18. 3D-print the case

This section is only for people who have a 3D printer.
The project works perfectly without a case — feel free to skip this section.

### What you need

- **Creality Print** software (free):
  https://www.crealitycloud.com/software-firmware/software
- **Ender-3 V3 SE** (or any FDM printer with at least 80 mm × 80 mm build area).
- **PLA filament**, 1.75 mm (recommended for beginners — PETG also works).
- The STL files from the repository:
  ```
  hardware/case/esp32_st7789_154_ec11_gps_case/case_bottom.stl
  hardware/case/esp32_st7789_154_ec11_gps_case/case_top.stl
  ```

### Step-by-step: Install and open Creality Print

1. Go to https://www.crealitycloud.com/software-firmware/software
2. Download the version for your operating system.
3. Install it the same way you install any program.
4. Open Creality Print.

### Step-by-step: Set up your printer in Creality Print

1. The first time you open Creality Print, a "Add Printer" wizard may appear
   automatically. If not, click the **printer icon** in the top-left corner.
2. In the list of Creality printers, find and click **"Ender-3 V3 SE"**.
3. Click **"Add"** or **"Confirm"**.
4. The build plate in the main view will change to match the Ender-3 V3 SE's size
   (220 × 220 mm). 

### Step-by-step: Import the STL files

1. In Creality Print, click **"File" → "Import Model"** (or press **Ctrl+I**).
2. Navigate to `ESP32Marauder-main/hardware/case/esp32_st7789_154_ec11_gps_case/`.
3. Select `case_bottom.stl` and click **Open**.
   The bottom part of the case will appear on the virtual build plate.
4. Repeat: **File → Import Model** → select `case_top.stl`.
   Both parts are now on the build plate.

### Step-by-step: Arrange the parts on the build plate

1. Click on `case_bottom` to select it.
2. Make sure it is lying flat (the wide flat face on the bottom).
   If it is tilted, right-click it and choose **"Lay Flat"** or use the rotate tool.
3. Click on `case_top`.
4. Make sure the flat outer face of the lid is facing down on the build plate.
5. Move the two parts so they do not overlap. Leave at least 5 mm between them.

### Step-by-step: Set slice settings

1. On the right side of Creality Print, find the **"Slice Settings"** or
   **"Print Settings"** panel.
2. Set the following values:

   | Setting | Value to enter | Where to find it |
   |---------|---------------|-----------------|
   | **Layer Height** | `0.20 mm` | Basic / Layer |
   | **First Layer Height** | `0.25 mm` | Basic / Layer |
   | **Infill Density** | `20%` | Basic / Infill |
   | **Infill Pattern** | `Gyroid` | Advanced / Infill |
   | **Wall Loops / Perimeters** | `3` | Basic / Shell |
   | **Top Layers** | `4` | Basic / Shell |
   | **Bottom Layers** | `4` | Basic / Shell |
   | **Support** | `None` (off) | Basic / Support |
   | **Build Plate Adhesion** | `Brim` | Basic / Build Plate Adhesion |
   | **Brim Width** | `5 mm` | Basic / Build Plate Adhesion |
   | **Print Speed** | `50 mm/s` | Basic / Speed |
   | **Nozzle Temperature** | `200 °C` (PLA) | Basic / Temperature |
   | **Bed Temperature** | `60 °C` (PLA) | Basic / Temperature |

3. Click the **"Slice"** button (usually at the bottom right).
   Creality Print will calculate every layer. This takes 10–60 seconds.

### Step-by-step: Preview and export

1. After slicing, the view switches to a layer-by-layer preview.
   Use the slider on the right to scroll through layers and check the print looks right.
   Look for the display window cutout and the encoder shaft hole in the top piece.
2. If everything looks correct, click **"Export"** (or **"Save to File"**).
3. Save the `.gcode` file to the **SD card** that came with your Ender-3 V3 SE.
4. Safely remove the SD card from your computer.

### Step-by-step: Print on the Ender-3 V3 SE

1. Insert the SD card into the slot on the front or side of the Ender-3 V3 SE.
2. On the printer's touchscreen, tap **"Print"**.
3. Navigate to your file (it will have the `.gcode` extension) and tap it.
4. Tap **"Print"** to start.
5. **Watch the first layer!** The first few minutes are critical:
   - The plastic should stick flat to the bed with no gaps or curling.
   - If it is not sticking, pause the print and adjust the bed levelling (the
     printer has an automatic levelling feature — run it from the menu first
     if you have not already).
6. Once the first layer looks good, you can step away.
7. Estimated print time: **~2 hours per half** at these settings.

### Post-print finishing

1. Once the print is done and cool, remove it from the build plate.
   Flex the plate gently and the part should pop off.
2. **Remove the brim:** Use a sharp hobby knife, flush cutters, or your fingernails
   to peel the thin border strip (brim) off the part edges.
3. **Clean up the encoder hole:** Push the encoder shaft through the hole in the top
   piece. If it is slightly tight, twist a 6 mm drill bit by hand (no drill needed)
   to widen it slightly.

---

## 19. Put everything in the case

Once you have both halves printed and your wiring confirmed working:

1. **Lay out all parts:** ESP32 board, display module, GPS module, TP4057 charger,
   LiPo battery, wires, and the two case halves.

2. **Start with the bottom half:**
   - Slide the **TP4057 charger** into the slot near the USB port cutout.
   - Lower the **ESP32 dev board** into the mounting area, flat side down.
   - Connect the charger's OUT+ → ESP32 3V3 and OUT– → ESP32 GND now if you have
     not already (easier to do before closing the case).

3. **Connect the battery:**
   - Plug the **LiPo battery's JST connector** into the charger's BAT port.
   - Lay the battery flat in the battery bay.

4. **Route the GPS module:**
   - Tuck the GPS module to one side.
   - If the GPS has an external antenna, route the antenna wire through the small
     slot on the side of the case.

5. **Attach the display / top half:**
   - Double-check all 12 display wires are still connected.
   - Lower the **top half** of the case over the bottom half, guiding the encoder
     shaft through the round hole and the display face into the rectangular window.
   - Press the two halves together until they sit flush.

6. **Secure with screws:**
   - Drive 4× M2×5 mm screws into the corner holes.
   - Do not over-tighten — the case is plastic and the threads can strip.

7. **Test before final assembly:** Before driving in all screws, plug in the USB cable
   and confirm the device still boots correctly (display lights up, encoder works).

---

## 20. Troubleshooting

Work through the table below by matching your symptom to the "Likely cause" column.

### Compile / upload errors

| Error message (in red) | What it means | How to fix |
|------------------------|---------------|-----------|
| `Board not found` or `No such file` | Board support not installed | Redo [Step 5](#5-add-esp32-board-support-to-arduino-ide) |
| `TFT_eSPI: no user setup selected` | `User_Setup_Select.h` not edited | Redo [Step 9](#9-edit-user_setup_selecth) |
| `'ENCODER_CLK' was not declared` | Wrong board target in configs.h | Redo [Step 10](#10-edit-configh) |
| `Sketch uses 100% of program storage` warning (but still uploads) | Normal — ignore it | Nothing |
| `A fatal error occurred: Failed to connect to ESP32` | Wrong port or bad cable | Try a different USB cable; hold the `BOOT` button on the ESP32 while clicking Upload |
| `No module named esptool` | Python/esptool issue | Use the Arduino IDE upload method instead |

### Display problems

| Symptom | Likely cause | Fix |
|---------|--------------|-----|
| Screen is completely **white** (nothing drawn) | Display driver mismatch or inversion | Open `User_Setup_marauder_st7789_154_ec11.h`, change `#define TFT_INVERSION_ON` to `#define TFT_INVERSION_OFF` (or vice versa). Save, re-upload. |
| Screen shows **colours but everything looks wrong** (red looks blue, etc.) | Colour order mismatch | In the same setup file, change `TFT_RGB_ORDER TFT_RGB` to `TFT_RGB_ORDER TFT_BGR`. Save, re-upload. |
| Screen is **black / no backlight** | BLK wire not connected or wrong GPIO | Check the wire from the display's **BLK** pin goes to **GPIO4** on the ESP32. |
| Screen shows **partial image or garbage** | Loose wire | Gently press on each Dupont connector on the display header and the ESP32 to re-seat them. |
| Screen works but is **upside down / rotated** | Orientation setting | This is uncommon for ST7789; if it happens, report it as a new issue on GitHub. |

### Encoder problems

| Symptom | Fix |
|---------|-----|
| Turning the knob does **nothing** | Check TRA→GPIO32 and TRB→GPIO33 are connected. |
| Menu moves **backwards** (CW should go down but goes up) | In `esp32_marauder/configs.h`, swap the values of `ENCODER_CLK` and `ENCODER_DT`: change `#define ENCODER_CLK 32` to `33` and `#define ENCODER_DT 33` to `32`. Save, re-upload. |
| **Pressing the knob** does nothing | Check PSH→GPIO25 is connected. |

### GPS problems

| Symptom | Fix |
|---------|-----|
| Serial Monitor says `GPS Not Found` | Check TX→GPIO21 and RX→GPIO22. Remember TX on the GPS → GPIO21 (not GPIO22). |
| GPS found but never gets a fix | Go outside with a clear view of the sky. First fix can take up to 5 minutes. |
| GPS says `GPS Attached Successfully` indoors | Normal — "attached" just means the module was detected; a fix still requires sky visibility. |

### Power problems

| Symptom | Fix |
|---------|-----|
| Nothing turns on when plugged in via USB | Try a different Micro-USB cable. |
| Device resets randomly / brown-out | LiPo charge too low or power wiring is loose. Charge the battery first. |
| Charging LED never lights up on TP4057 | Confirm USB cable is plugged fully into the TP4057 module's USB port (not the ESP32's). |

---

## You are done! 🎉

Your ESP32 Marauder with the 1.54" ST7789 display, rotary encoder, GPS, and LiPo
battery is ready to use.

**Remember:** Only scan networks and devices you own or have permission to test.

If you have questions or run into a problem not covered here, open an issue on GitHub:
**https://github.com/trustno10822/ESP32Marauder/issues**
