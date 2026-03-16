# 3D-Printed Case – ESP32 ST7789 154 EC11 GPS

## Overview

This directory contains the 3D-printable enclosure for the ESP32 30-pin +
1.54" ST7789 + EC11 encoder + GPS + TP4057 LiPo build.

## Files

| File | Description |
|------|-------------|
| `case_bottom.stl` | Bottom half of the enclosure (holds ESP32 + charger + battery) |
| `case_top.stl` | Top half (display window opening + encoder shaft hole) |
| `case_assembly.3mf` | Pre-assembled 3MF for direct slicing (optional) |

> **Note:** STL/3MF files are generated from the CAD source (FreeCAD / Fusion 360).
> The case design assumes the following internal dimensions:
> - Display module: ~34 mm × 34 mm footprint, 5 mm depth
> - ESP32 board: ~52 mm × 28 mm footprint
> - LiPo battery: ≤ 40 mm × 30 mm × 8 mm (e.g. 502030 500 mAh)

## Printing Instructions (Creality Print / Ender-3 V3 SE)

### Prerequisites

- [Creality Print](https://www.crealitycloud.com/software-firmware/software) installed
- Ender-3 V3 SE printer (250 × 220 × 220 mm build volume)
- PLA or PETG filament, 1.75 mm

### Step-by-Step

1. **Open Creality Print.**

2. **Select printer:** Click the printer icon (top-left) → search for
   `Ender-3 V3 SE` → confirm.

3. **Import the model:**
   - **File → Import Model** (or drag-and-drop).
   - Import `case_bottom.stl` first, then `case_top.stl`.
   - Each half will appear on the virtual build plate.

4. **Orient the parts:**
   - `case_bottom.stl` – flat base face down (no rotation needed).
   - `case_top.stl` – flat outer face down (display window facing up is printed
     as a bridge or with slight support; flat-down is preferred to avoid support).

5. **Slice settings:**

   | Setting | Recommended Value |
   |---------|------------------|
   | Layer height | 0.20 mm |
   | First layer height | 0.25 mm |
   | Infill density | 20 % |
   | Infill pattern | Gyroid |
   | Perimeter count | 3 |
   | Top solid layers | 4 |
   | Bottom solid layers | 4 |
   | Supports | None (parts are self-supporting) |
   | Build plate adhesion | Brim (5 mm) for first layer |
   | Print speed | 50 mm/s |
   | Nozzle temperature | 200 °C (PLA) / 230 °C (PETG) |
   | Bed temperature | 60 °C (PLA) / 80 °C (PETG) |

6. **Preview the slice:**  
   Click **Slice** and review the layer preview. Verify that the display cutout
   and encoder shaft hole render correctly.

7. **Export G-code:**  
   Click **Export** → save `.gcode` to the SD card that came with the printer.

8. **Start printing:**  
   - Insert the SD card into the Ender-3 V3 SE.
   - On the printer touchscreen: **Print from SD → select your file → Start**.
   - Monitor the first few layers to confirm bed adhesion.
   - Typical print time: ~2 h per half at 0.2 mm / 50 mm/s.

### Post-Processing

- Remove brim with flush cutters.
- If the display window has slight over-hang stringing, use a lighter or heat gun
  briefly at low heat to clean up.
- Drill / ream the encoder shaft hole to exactly 6 mm if tight.

## Assembly

1. Insert the TP4057 charger module into the charging-port recess on the bottom half.
2. Slide the ESP32 dev board onto the mounting pillars / rails inside the bottom half.
3. Connect all wires (see wiring table in main docs) before closing.
4. Route the GPS antenna (if external) through the small side slot.
5. Place the LiPo battery flat in the battery bay and connect to the charger.
6. Fit the top half over the bottom half, guiding the display module into the window.
7. Secure with 4× M2×5 mm self-tapping screws (or press-fit, depending on design).
