# KiCad Schematic – ESP32 ST7789 154 EC11 GPS

## Schematic: esp32_st7789_154_ec11_gps.kicad_sch

This KiCad schematic covers the following interconnects:

### Components / Sub-circuits

1. **ESP32 30-pin Dev Board** (U1)  
   - 30-pin DIP/SMD footprint  
   - Exposed GPIOs: 4, 5, 16, 17, 18, 21, 22, 23, 25, 32, 33  
   - Power: 3.3 V, GND, VIN (5 V from charger)

2. **1.54" ST7789 + EC11 Module** (CN1 – 12-pin header 2.54 mm pitch)  
   - Pins: GND, VDO, SCL, SDA, RES, DC, CS, BLK, TRA, TRB, PSH, K0

3. **GPS Module** (CN2 – 4-pin header 2.54 mm pitch)  
   - Pins: GND, VCC, TX, RX

4. **TP4057 LiPo Charger** (CN3 – pads)  
   - VUSB (5 V input), GND, BAT+, BAT–, OUT+ (3.3 V), OUT–

5. **LiPo Battery Connector** (CN4 – 2-pin JST PH 2.0)  
   - BAT+, BAT–

### Net Connections (Summary)

| Net | From | To |
|-----|------|----|
| GND | All grounds | Common GND plane |
| +3V3 | TP4057 OUT+ | ESP32 3.3V, CN1-VDO, CN2-VCC |
| +5V | TP4057 VUSB | USB connector |
| TFT_SCK | ESP32 IO18 | CN1-SCL |
| TFT_MOSI | ESP32 IO23 | CN1-SDA |
| TFT_RST | ESP32 IO5 | CN1-RES |
| TFT_DC | ESP32 IO16 | CN1-DC |
| TFT_CS | ESP32 IO17 | CN1-CS |
| TFT_BL | ESP32 IO4 | CN1-BLK |
| ENC_A | ESP32 IO32 | CN1-TRA |
| ENC_B | ESP32 IO33 | CN1-TRB |
| ENC_SW | ESP32 IO25 | CN1-PSH |
| GPS_TX | CN2-TX | ESP32 IO21 (RX2) |
| GPS_RX | CN2-RX | ESP32 IO22 (TX2) |

### Pull-up Resistors

- R1: 10 kΩ on ENC_A (CN1-TRA) to +3V3 (optional; ESP32 internal pull-up used by firmware)
- R2: 10 kΩ on ENC_B (CN1-TRB) to +3V3 (optional)
- R3: 10 kΩ on ENC_SW (CN1-PSH) to +3V3 (optional; ESP32 internal pull-up used by firmware)

### Decoupling Capacitors

- C1: 100 nF ceramic on +3V3 near ESP32
- C2: 10 µF electrolytic on +3V3 near ESP32
- C3: 100 nF ceramic on GPS VCC

---

## How to Open in KiCad 7/8

1. Open KiCad.
2. **File → Open Project** → select `esp32_st7789_154_ec11_gps.kicad_pro`.
3. Open the Schematic Editor (`.kicad_sch`) and PCB Editor (`.kicad_pcb`).

## Exporting Fabrication Files

### Gerbers (from PCB Editor)
1. **File → Fabrication Outputs → Gerbers**.
2. Set output directory to `gerbers/`.
3. Enable all required layers (F.Cu, B.Cu, F.Mask, B.Mask, F.SilkS, Edge.Cuts).
4. Click **Generate Drill Files** → `gerbers/`.
5. Zip the `gerbers/` folder for upload to fab house.

### PNG / SVG / PDF Exports
1. **File → Export → SVG** → save to `exports/`.
2. **File → Print** → save as PDF → `exports/schematic.pdf`.
3. **View → 3D Viewer** → File → Export → PNG → `exports/pcb_top.png`.
