<!---[![License: MIT](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/justcallmekoko/ESP32Marauder/blob/master/LICENSE)--->
<!---[![Gitter](https://badges.gitter.im/justcallmekoko/ESP32Marauder.png)](https://gitter.im/justcallmekoko/ESP32Marauder)--->
<!---[![Build Status](https://travis-ci.com/justcallmekoko/ESP32Marauder.svg?branch=master)](https://travis-ci.com/justcallmekoko/ESP32Marauder)--->
<!---Shields/Badges https://shields.io/--->

# ESP32 Marauder
<p align="center"><img alt="Marauder logo" src="https://github.com/justcallmekoko/ESP32Marauder/blob/master/pictures/marauder_skull_patch_04_full_final.png?raw=true" width="300"></p>
<p align="center">
  <b>A suite of WiFi/Bluetooth offensive and defensive tools for the ESP32</b>
  <br><br>
  <a href="https://github.com/justcallmekoko/ESP32Marauder/blob/master/LICENSE"><img alt="License" src="https://img.shields.io/github/license/mashape/apistatus.svg"></a>
  <a href="https://gitter.im/justcallmekoko/ESP32Marauder"><img alt="Gitter" src="https://badges.gitter.im/justcallmekoko/ESP32Marauder.png"/></a>
  <a href="https://github.com/justcallmekoko/ESP32Marauder/releases/latest"><img src="https://img.shields.io/github/downloads/justcallmekoko/ESP32Marauder/total" alt="Downloads"/></a>
  <br>
  <a href="https://twitter.com/intent/follow?screen_name=jcmkyoutube"><img src="https://img.shields.io/twitter/follow/jcmkyoutube?style=social&logo=twitter" alt="Twitter"></a>
  <a href="https://www.instagram.com/just.call.me.koko"><img src="https://img.shields.io/badge/Follow%20Me-Instagram-orange" alt="Instagram"/></a>
  <br><br>
</p>
    
[![Build and Push](https://github.com/justcallmekoko/ESP32Marauder/actions/workflows/build_push.yml/badge.svg)](https://github.com/justcallmekoko/ESP32Marauder/actions/workflows/build_push.yml)

## Table of Contents
- [About](#about)
- [Getting Started](#getting-started)
- [Features](#features)
- [DIY Build](#diy-build)
  - [Hardware Requirements](#hardware-requirements)
  - [Wiring Diagram](#wiring-diagram)
  - [Flashing Firmware](#flashing-firmware)
- [Updating Firmware](#updating-firmware)
  - [Web Update](#web-update)
  - [SD Card Update](#sd-card-update)
- [3D Printed Enclosure](#3d-printed-enclosure)
- [Special Thanks](#special-thanks)
- [For Sale](#for-sale)

## About

The ESP32 Marauder is a portable WiFi and Bluetooth security testing device for penetration testers and security researchers. Originally inspired by [Spacehuhn's](https://github.com/Spacehuhn) [esp8266_deauther](https://github.com/Spacehuhn/esp8266_deauther) project, it provides a comprehensive suite of tools for analyzing and testing wireless networks and Bluetooth devices.

**⚠️ Legal Disclaimer**: Use this tool responsibly and only on networks and devices you own or have explicit permission to test. Unauthorized access to networks is illegal in most countries.

**Note**: Due to limitations in Espressif's ESP32-IDF, the ESP32 cannot transmit deauthentication frames.

For more information, check out:
- 📺 [YouTube Video Tutorial](https://www.youtube.com/watch?v=BGFO1wA29o8)
- 📝 [Hackster.io Article](https://www.hackster.io/news/esp32-marauder-puts-a-bluetooth-wi-fi-pen-testing-toolkit-in-your-pocket-32d389f6e66f)
- 📚 [Project Wiki](https://github.com/justcallmekoko/ESP32Marauder/wiki)
- 🐛 [Issue Tracker](https://github.com/justcallmekoko/ESP32Marauder/issues)
- 📷 [#esp32marauder on Instagram](https://www.instagram.com/explore/tags/esp32marauder/)

## Getting Started

Download the [latest release](https://github.com/justcallmekoko/ESP32Marauder/releases/latest) of the firmware.

Check out the [project wiki](https://github.com/justcallmekoko/ESP32Marauder/wiki) for detailed documentation and tutorials.

## Features

### WiFi Capabilities
- **Scan Access Points**: Discover nearby WiFi networks and their details
- **Scan Stations**: Detect WiFi client devices
- **Probe Request Sniffing**: Monitor [probe request frames](https://mrncciew.com/2014/10/27/cwap-802-11-probe-requestresponse/) from wireless devices
- **Beacon Sniffing**: Capture [beacon frames](https://en.wikipedia.org/wiki/Beacon_frame) from access points
- **Beacon Spam**: Broadcast multiple fake SSIDs (List mode or Random mode)
- **Rick Roll Beacon**: Broadcast Rick Astley lyrics as WiFi access points
- **EAPOL/PMKID Capture**: Capture handshake frames for WPA/WPA2 analysis
- **Packet Monitor**: Visualize WiFi packet density with real-time graphs
- **Deauth Detection**: Detect deauthentication attacks on nearby networks
- **WiFi Wardriving**: Log GPS coordinates with discovered access points
- **SSID Management**: Generate, add, or clear custom SSID lists

### Bluetooth Capabilities
- **Bluetooth Scanning**: Discover nearby Bluetooth and BLE devices
- **Bluetooth Sniffing**: Capture Bluetooth traffic for analysis
- **Flock Wardriving**: Bluetooth wardriving with GPS logging
- **Card Skimmer Detection**: Identify potential Bluetooth-enabled credit card skimmers
- **Detect Pwnagotchi**: Find nearby Pwnagotchi devices
- **Detect Espressif Devices**: Identify ESP32/ESP8266 devices in range

### System Features
- **Save to SD Card**: Store PCAP files for later analysis with Wireshark
- **Firmware Updates**: Update via web interface or SD card
- **GPS Support**: Add location data to wardriving captures
- **Battery Monitoring**: Track battery level and charging status
- **Touch Interface**: Navigate using touchscreen or physical buttons
- **Command Line Interface**: Control via serial commands

## DIY Build

<p align="center"><img alt="DIY Marauder" src="https://github.com/justcallmekoko/ESP32Marauder/blob/master/pictures/diy.png?raw=true" width="600"></p>

### Hardware Requirements

- **ESP32 Development Board** (any variant)
- **2.8" TFT Touch Screen** with ILI9341 driver (240x320 resolution)
- **MicroSD Card** (non-Samsung recommended)
- **Jumper Wires**
- **Breadboard** (for prototyping)
- **Optional**: GPS module, battery, analog battery monitoring circuit

### Wiring Diagram

#### Display and SD Card Connections

| SD Card | 2.8" TFT | ESP32  |
| ------- | -------- | ------ |
|         | VCC      | VCC    |
|         | GND      | GND    |
|         | CS       | GPIO17 |
|         | RESET    | GPIO5  |
|         | D/C      | GPIO16 |
| SD_MOSI | MOSI     | GPIO23 |
| SD_SCK  | SCK      | GPIO18 |
|         | LED      | GPIO32 |
| SD_MISO | MISO     | GPIO19 |
|         | T_CLK    | GPIO18 |
|         | T_CS     | GPIO21 |
|         | T_DI     | GPIO23 |
|         | T_DO     | GPIO19 |
|         | T_IRQ    | (not connected) |
| SD_CS   |          | GPIO12 |

See the [schematic](https://github.com/justcallmekoko/ESP32Marauder/blob/master/schematics/Schematic_ESP32-Marauder-2_ESP32-Marauder-2-Schematic_20191007113616_png.png) for more details.

#### Optional: Battery Monitoring Circuit

For analog battery monitoring, use a 4:1 voltage divider with an optional MOSFET. For charge detection, use a 1:2 voltage divider (changes battery icon color while charging).

| Battery | ESP32  |
| ------- | ------ |
| BAT +   | GPIO34 |
| MOSFET  | GPIO13 |
| CHARGE +| GPIO27 |

### Flashing Firmware

#### Using Arduino IDE

1. **Install Arduino IDE**
   - Download from [arduino.cc](https://www.arduino.cc/en/main/software)

2. **Add ESP32 Board Support**
   - Go to `File` > `Preferences`
   - Add to "Additional Boards Manager URLs": `https://dl.espressif.com/dl/package_esp32_index.json`
   - Go to `Tools` > `Board` > `Boards Manager`
   - Search for "esp32" and install "esp32 by Espressif Systems"

3. **Install Required Libraries**
   - Install [SimpleList](https://github.com/spacehuhn/SimpleList) by Spacehuhn
     - Download the repository
     - In Arduino IDE: `Sketch` > `Include Library` > `Add .ZIP Library...`
   - Install [TFT_eSPI](https://github.com/justcallmekoko/TFT_eSPI) (justcallmekoko's fork)
     - Download the repository
     - Add via `Sketch` > `Include Library` > `Add .ZIP Library...`
     - Apply modifications from [this issue](https://github.com/justcallmekoko/ESP32Marauder/issues/2#issuecomment-555695918)

4. **Install ESP32 Filesystem Uploader**
   - Follow [these instructions](https://github.com/me-no-dev/arduino-esp32fs-plugin)

5. **Install CH340 Drivers**
   - Download [CH340 drivers](https://github.com/justcallmekoko/ESP32Marauder/blob/master/Drivers/CH34x_Install_Windows_v3_4.EXE) if needed

6. **Flash the Firmware**
   - Clone or download this repository
   - Open `esp32_marauder/esp32_marauder.ino`
   - If using analog battery monitoring: In `MenuFunctions.h`, set `#define BATTERY_ANALOG_ON` to `1`
   - Connect your ESP32 via USB
   - Select the COM port under `Tools` > `Port`
   - Select "LOLIN D32" under `Tools` > `Boards`
   - Click `ESP32 Sketch Data Upload` and wait for SPIFFS upload
   - Click the Upload button

## Updating Firmware

### Web Update

1. Download the [latest release](https://github.com/justcallmekoko/ESP32Marauder/releases/latest) `.bin` file
2. On Marauder, navigate to `Device` > `Update Firmware` > `Web Update`
3. Connect to the "MarauderOTA" WiFi network (password: `justcallmekoko`)
4. Open a browser and go to `http://192.168.4.1`
5. Log in with username: `admin`, password: `admin`
6. Click `Browse`, select the `.bin` file, and click `Update`
7. Marauder will reboot automatically

### SD Card Update

**Note**: Samsung MicroSD cards may cause boot issues.

1. Download the [latest release](https://github.com/justcallmekoko/ESP32Marauder/releases/latest) `.bin` file
2. Copy the `.bin` file to the root of your SD card
3. Rename the file to `update.bin`
4. Power off Marauder and insert the SD card
5. Power on and navigate to `Device` > `Update Firmware` > `SD Update`
6. Confirm the update
7. Marauder will reboot automatically

## 3D Printed Enclosure

STL files are available for 3D printing your own enclosure:
- [GitHub](https://github.com/justcallmekoko/ESP32Marauder/tree/master/3Dfiles)
- [Thingiverse](https://www.thingiverse.com/thing:4146626)

**Required Hardware**:
- 4x M2.5x10mm hex screws
- Face plate (printed)
- Enclosure body (printed)

**Assembly**:
1. Print both the face plate and body
2. Mount the face plate onto the screen PCB using the alignment pegs
3. Lower the Marauder into the enclosure body
4. Ensure the battery sits in the center trench
5. Fasten with 4 hex screws (flush with face plate surface)

## Special Thanks

- [Spacehuhn](https://github.com/spacehuhn) - For the [SimpleList](https://github.com/spacehuhn/SimpleList) library, menu structure design, and buffer class for PCAP files
- [Ivanseidel](https://github.com/ivanseidel) - For the thread-safe [LinkedList](https://github.com/ivanseidel/LinkedList) library
- [Bodmer](https://github.com/Bodmer) - For the comprehensive [TFT_eSPI](https://github.com/Bodmer/TFT_eSPI) library
- [HyderHasnain](https://github.com/hyderhasnain) - For the adaptable [line graph](https://github.com/hyderhasnain/arduino_touchscreen_controller/blob/master/Code/AccelGraph_Original.ino) used in packet monitor

## For Sale

You can purchase pre-built ESP32 Marauder devices at [justcallmekokollc.com](https://www.justcallmekokollc.com)
