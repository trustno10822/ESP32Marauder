# Marauder EC11-240 — Single-Sided DIY PCB

Carrier board for an **ESP32 DevKit V1 (30-pin)** running the
`MARAUDER_EC11_240` firmware target:

| Module | Connection |
|---|---|
| ST7789 1.54 " 240×240 SPI display | 8-pin male header J2 |
| EC11 rotary encoder | 5-pin male header J3 |
| MicroSD card SPI module | 6-pin male header J4 |

The board is designed for **one-sided (B.Cu only) toner-transfer** fabrication
on a copper-clad laminate using a **Brother L2420DW** laser printer.

---

## Bill of Materials

| Ref | Value | Qty | Notes |
|-----|-------|-----|-------|
| J1a | 1×15 female header, 2.54 mm | 1 | ESP32 left column |
| J1b | 1×15 female header, 2.54 mm | 1 | ESP32 right column |
| J2 | 1×8 male header, 2.54 mm | 1 | ST7789 display |
| J3 | 1×5 male header, 2.54 mm | 1 | EC11 encoder |
| J4 | 1×6 male header, 2.54 mm | 1 | MicroSD module |
| PCB | FR4 single-sided copper-clad, ≥ 1.6 mm | 1 | ~90 × 56 mm |

---

## Board overview

```
 ┌──────────────────────────────────────────────────────────────┐
 │  +3V3 bus ═══════════════════════════════════════════════════│
 │                                                              │
 │ J3         J1a        J1b          J2             J4        │
 │ Encoder  ESP32-L    ESP32-R    Display (8)    SD Card (6)   │
 │ (5-pin)  (15-pin)   (15-pin)   VCC GND …      VCC GND …    │
 │  GND                                                         │
 │  VCC                                                         │
 │  SW ────────────── IO25                                      │
 │  DT ────────────── IO33                                      │
 │  CLK ─────────────IO32                                       │
 │                              ══ SPI bus (MOSI/MISO/SCLK) ══ │
 │                                                              │
 │  GND bus ════════════════════════════════════════════════════│
 └──────────────────────────────────────────────────────────────┘
```

---

## Connector pinouts

### J1a — ESP32 DevKit left column (pin 1 = top, USB end)

| Pin | GPIO | Signal |
|-----|------|--------|
| 1 | 3V3 | **+3V3 rail** |
| 2 | EN | — |
| 3 | IO36 | — |
| 4 | IO39 | — |
| 5 | IO34 | — |
| 6 | IO35 | — |
| **7** | **IO32** | **ENC_CLK** |
| **8** | **IO33** | **ENC_DT** |
| **9** | **IO25** | **ENC_SW** |
| 10 | IO26 | — |
| 11 | IO27 | — |
| 12 | IO14 | — |
| 13 | IO12 | — |
| **14** | **GND** | **GND rail** |
| 15 | IO13 | — |

### J1b — ESP32 DevKit right column (pin 1 = top, USB end)

| Pin | GPIO | Signal |
|-----|------|--------|
| 1 | VIN | 5 V input |
| **2** | **GND** | **GND rail** |
| **3** | **IO23** | **TFT_MOSI / SD_MOSI** |
| **4** | **IO22** | **SD_CS** |
| 5 | IO1 / TX | — |
| 6 | IO3 / RX | — |
| 7 | IO21 | — |
| **8** | **IO19** | **TFT_MISO / SD_MISO** |
| **9** | **IO18** | **TFT_SCLK / SD_SCK** |
| **10** | **IO5** | **TFT_RST** |
| **11** | **IO17** | **TFT_CS** |
| **12** | **IO16** | **TFT_DC** |
| **13** | **IO4** | **TFT_BL** |
| 14 | IO0 | — |
| 15 | IO2 | — |

### J2 — ST7789 display (8-pin)

| Pin | Signal |
|-----|--------|
| 1 | VCC (3.3 V) |
| 2 | GND |
| 3 | SCL / TFT_SCLK (IO18) |
| 4 | SDA / TFT_MOSI (IO23) |
| 5 | RES / TFT_RST (IO5) |
| 6 | DC / TFT_DC (IO16) |
| 7 | CS / TFT_CS (IO17) |
| 8 | BLK / TFT_BL (IO4) |

> Some 7-pin display modules omit the CS pin (tied internally to GND).  
> In that case bridge pin 7 (CS) to GND on the module.

### J3 — EC11 rotary encoder (5-pin)

| Pin | Signal |
|-----|--------|
| 1 | GND |
| 2 | VCC (3.3 V) |
| 3 | SW / ENC_SW (IO25) |
| 4 | DT / ENC_DT (IO33) |
| 5 | CLK / ENC_CLK (IO32) |

> Rotate clockwise → scroll **down** in menus.  
> Rotate counter-clockwise → scroll **up** in menus.  
> Press → **select** / confirm.

### J4 — MicroSD SPI module (6-pin)

| Pin | Signal |
|-----|--------|
| 1 | VCC (3.3 V) |
| 2 | GND |
| 3 | MISO (IO19) |
| 4 | MOSI (IO23) |
| 5 | SCK (IO18) |
| 6 | CS (IO22) |

---

## PCB design rules (toner-transfer friendly)

| Parameter | Value |
|-----------|-------|
| Minimum track width | 0.6 mm |
| Power track width | 1.0 mm |
| Minimum clearance | 0.5 mm |
| Via drill | 1.0 mm |
| Via annular ring | 0.3 mm |
| Copper layer | **B.Cu only** (single-sided) |
| Board size | 88.9 × 55.88 mm |

---

## Fabricating with the toner-transfer method

### What you need

| Item | Specification |
|------|--------------|
| Laser printer | Brother L2420DW (or any 1200 DPI mono laser) |
| Transfer paper | Glossy photo paper, 135–200 g/m² (HP Premium Glossy recommended) |
| Copper-clad board | FR4 or phenolic, **single-sided**, ~90 × 60 mm, ≥ 1.6 mm |
| Ferric chloride | PCB etching solution (or ammonium persulphate) |
| Clothes iron | Temperature-adjustable |
| Acetone or IPA | Board cleaning |
| Fine sandpaper | 400–800 grit |
| Permanent marker | For touch-up |

---

### Step 1 — Export the print file from KiCad

1. Open `Marauder-EC11-240.kicad_pcb` in **KiCad 6** (or newer).
2. Go to **File → Plot** (`Ctrl+Shift+P`).
3. Configure the plot dialog:

   | Setting | Value |
   |---------|-------|
   | Plot format | **PDF** (or SVG) |
   | Include layers | **B.Cu**, **Edge.Cuts** |
   | Mirror | ☑ **Checked** (B.Cu must be mirrored so copper faces board) |
   | Drill marks | None |
   | Scale | **1:1** |
   | Line width | 0.1 mm minimum |

4. Click **Plot** and save the PDF.

> **Why mirror?** You iron the toner side face-down onto the copper.  
> After transfer the pattern appears correctly oriented from the top.

---

### Step 2 — Print on glossy photo paper (Brother L2420DW)

1. Open the exported PDF in **Adobe Acrobat Reader** (not browser, for accuracy).
2. Print settings:

   | Setting | Value |
   |---------|-------|
   | Printer | Brother L2420DW |
   | Paper size | **A5** (or A4 with manual crop margin) |
   | Scaling | **Actual size / 100%** — NEVER "fit to page" |
   | Paper type | Glossy photo / Heavy paper (≥ 135 g/m²) |
   | Quality | **Best / 1200 DPI** |
   | Density | **Maximum / Darkest** (toner density slider to max) |
   | Duplex | Off |

3. Load glossy side **face-down** in the manual-feed tray.
4. Print one test page and verify the board outline measures exactly  
   **88.9 × 55.88 mm** with a ruler.

> **Tip:** On Brother L2420DW open the toner save setting and make sure it  
> is **OFF**. Toner save mode reduces density and causes poor transfer.

---

### Step 3 — Prepare the copper-clad board

1. Cut the copper-clad board to approximately **92 × 60 mm** (a few mm  
   of extra margin that will be cut away after etching).
2. Sand the copper surface lightly with 400-grit paper in circular motions  
   to remove oxidation and improve adhesion.
3. Wipe with **acetone** (or IPA), then let dry. **Do not touch the copper  
   surface with bare hands** after cleaning.

---

### Step 4 — Toner transfer (ironing)

1. Place the printed sheet **toner-side down** on the copper surface,  
   aligned so the board outline sits on the clean copper.
2. Tape two edges down with heat-resistant tape.
3. Set your iron to **cotton / high heat (~180–200 °C)**  
   with **no steam**.
4. Pre-heat the board from the bare paper side for 30 seconds.
5. Apply firm, even pressure for **3–4 minutes**, working in small circles.  
   Pay extra attention to edges and corners.
6. Let cool for **5 minutes** without disturbing.
7. Immerse the board in **warm water** (≈ 40 °C) for 3–5 minutes.
8. Gently rub the paper away with your fingers — do not peel; let the paper  
   disintegrate naturally.
9. Inspect the transferred pattern:
   - Solid, continuous traces = good.
   - Broken or thin spots: touch up with a **permanent marker** (CD-marker).
   - Bridged traces: cut carefully with a sharp knife or 0.5 mm drill.

---

### Step 5 — Etching

> ⚠️ Work in a ventilated area. Ferric chloride stains permanently.  
> Wear gloves and eye protection.

1. Prepare a tray of **ferric chloride solution** at ≈ 40 °C  
   (warm solution etches faster).
2. Submerge the board — agitate gently.
3. Typical etch time: **15–30 minutes** depending on solution freshness.
4. Check every 5 minutes. Remove when all exposed copper has dissolved and  
   only the toner-covered traces remain.
5. Rinse thoroughly under running water.
6. Remove toner with **acetone** on a cloth — the copper traces will appear.

---

### Step 6 — Drilling

Drill all pads with a **1.0 mm drill bit** in a PCB drill or Dremel:

- All through-hole pads on J1a, J1b, J2, J3, J4 use 1.0 mm holes.
- Keep drill perpendicular to the board.
- A drill press gives the best results; a drill guide helps if using a hand tool.

---

### Step 7 — Tinning & assembly

1. Apply **flux** to the copper traces.
2. Tin all copper traces with solder for corrosion protection and easier  
   component soldering.
3. Insert pin headers (cut from a long strip if needed):
   - J1a, J1b: female headers (so the DevKit plugs in).
   - J2, J3, J4: male headers (modules plug in from above).
4. Solder from the **copper side** (B side = bottom of board).
5. Trim any long pin stubs with flush cutters.

---

### Step 8 — Test

1. Plug in the ESP32 DevKit **before** connecting any modules.
2. Flash the `MARAUDER_EC11_240` firmware (see main project README).
3. Connect modules one at a time, checking for correct voltage:
   - J2 pin 1 (VCC) should read 3.3 V.
   - J3 pin 2 (VCC) should read 3.3 V.
   - J4 pin 1 (VCC) should read 3.3 V.
4. If the display does not initialize, check the `TFT_INVERSION_ON` define in  
   `User_Setup_marauder_ec11_240.h` and toggle it.

---

## Firmware configuration reminder

Enable the board in `esp32_marauder/configs.h`:

```c
#define MARAUDER_EC11_240
```

And copy `User_Setup_marauder_ec11_240.h` to your TFT_eSPI library directory,
then uncomment the matching line in the library's `User_Setup_Select.h`.

Default GPIO assignments:

| Signal | GPIO |
|--------|------|
| TFT_MOSI | 23 |
| TFT_MISO | 19 |
| TFT_SCLK | 18 |
| TFT_CS | 17 |
| TFT_DC | 16 |
| TFT_RST | 5 |
| TFT_BL | 4 |
| SD_CS | 22 |
| ENCODER_CLK | 32 |
| ENCODER_DT | 33 |
| ENCODER_SW (C_BTN) | 25 |

---

## KiCad files in this directory

| File | Purpose |
|------|---------|
| `Marauder-EC11-240.kicad_pro` | KiCad 6 project configuration |
| `Marauder-EC11-240.kicad_sch` | Schematic |
| `Marauder-EC11-240.kicad_pcb` | Single-sided PCB layout |

Open `Marauder-EC11-240.kicad_pro` with **KiCad 6.0** or newer to view and
edit the design. You can also generate Gerber files from the PCB editor if you
want to order the board professionally (use the B.Cu + Edge.Cuts layers only).
