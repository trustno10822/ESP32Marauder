# Gerbers – ESP32 ST7789 154 EC11 GPS PCB

## Ordering Instructions

This folder contains Gerber and drill files ready for PCB fabrication.

### File List

| File | Layer |
|------|-------|
| `esp32_st7789_154_ec11_gps-F_Cu.gtl` | Top copper |
| `esp32_st7789_154_ec11_gps-B_Cu.gbl` | Bottom copper |
| `esp32_st7789_154_ec11_gps-F_Mask.gts` | Top solder mask |
| `esp32_st7789_154_ec11_gps-B_Mask.gbs` | Bottom solder mask |
| `esp32_st7789_154_ec11_gps-F_SilkS.gto` | Top silkscreen |
| `esp32_st7789_154_ec11_gps-B_SilkS.gbo` | Bottom silkscreen |
| `esp32_st7789_154_ec11_gps-Edge_Cuts.gko` | Board outline |
| `esp32_st7789_154_ec11_gps.drl` | Excellon drill file |

### Recommended PCB Specs

| Parameter | Value |
|-----------|-------|
| Material | FR4 |
| Thickness | 1.6 mm |
| Copper weight | 1 oz (35 µm) |
| Surface finish | HASL (lead-free) or ENIG |
| Solder mask | Green |
| Silkscreen | White |
| Layers | 2 |

### Fab Houses

Upload the zipped `gerbers/` folder to any of:
- [JLCPCB](https://jlcpcb.com)
- [PCBWay](https://www.pcbway.com)
- [OSHPark](https://oshpark.com) (accepts KiCad files directly)

> **Note:** To generate actual Gerber files, open the KiCad PCB project and use
> **File → Fabrication Outputs → Gerbers**. This folder documents the expected
> file names and layer assignments.
