# PCB design notes

## Known design features

The current custom PCB includes:

- Bulk capacitor on the 5 V distribution
- Local capacitor for the ESP32 and level shifter
- Series resistor between the level shifter and LED data output
- Additional 5 V/GND terminals for LED power
- Optional connector for a second presence sensor
- BH1750 powered from the ESP32's 3.3 V rail
- ESP32-C3 Super Mini powered through its 5 V pin

## Layout review checklist

- [ ] Confirm capacitor voltage ratings and polarity
- [ ] Confirm the bulk capacitor is close to the relevant power entry/distribution
- [ ] Place local decoupling close to the devices it serves
- [ ] Confirm level-shifter supply, ground, channel, and output-enable wiring
- [ ] Confirm LED data resistor placement and value against the schematic
- [ ] Check 5 V/GND trace widths and connector ratings for worst-case LED current
- [ ] Keep mains and low-voltage areas separated if the AC supply is inside the enclosure
- [ ] Add connector names, pin 1 indicators, polarity, board revision, and QR code
- [ ] Check mounting holes, enclosure clearances, and terminal access
- [ ] Run electrical-rule and design-rule checks before fabrication

## Fabrication files

Add the actual design exports when ready. Prefer a dedicated revision directory if you need to preserve old board versions, for example `hardware/pcb/rev-a/`. Do not commit private manufacturing credentials or order information unless you want it public.
