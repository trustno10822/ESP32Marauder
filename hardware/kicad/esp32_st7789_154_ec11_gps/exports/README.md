# Exports – ESP32 ST7789 154 EC11 GPS PCB

## Contents

This folder holds fabrication documentation exports generated from the KiCad project.

| File | Description |
|------|-------------|
| `schematic.pdf` | Full schematic PDF |
| `pcb_top.png` | PCB top-layer preview (PNG) |
| `pcb_bottom.png` | PCB bottom-layer preview (PNG) |
| `pcb_assembly.svg` | Assembly drawing (SVG) |

## How to Generate

Open the KiCad project (`esp32_st7789_154_ec11_gps.kicad_pro`):

### Schematic PDF
1. Open Schematic Editor.
2. **File → Print** → check "Print to PDF".
3. Save as `exports/schematic.pdf`.

### PCB PNG
1. Open PCB Editor.
2. **File → Export → PNG** (or use the 3D viewer).
3. Save top view as `exports/pcb_top.png` and bottom view as `exports/pcb_bottom.png`.

### SVG
1. Open PCB Editor.
2. **File → Export → SVG**.
3. Save as `exports/pcb_assembly.svg`.
