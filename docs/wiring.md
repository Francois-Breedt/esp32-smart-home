# Wiring guide

This is a functional wiring reference, not a substitute for the final schematic. Check the PCB silkscreen and schematic before connecting power.

## ESP32-C3 and sensors

| Signal | Connection |
|---|---|
| ESP32 GPIO0 | BH1750 SDA |
| ESP32 GPIO1 | BH1750 SCL |
| ESP32 3.3 V | BH1750 VCC |
| ESP32 GND | BH1750 GND |
| ESP32 GPIO3 | LD2410C OUT |
| ESP32 GPIO4 | Optional second sensor digital output |
| ESP32 GPIO10 | Level-shifter input for LED data |

The BH1750 is intended to run from 3.3 V. Check the specific breakout board before powering it, as some boards include regulators or I²C pull-ups connected to their supply rail.

## LED strip

- Supply LED 5 V and GND from the power distribution designed for the strip.
- Connect ESP32 GND, level-shifter GND, and LED power-supply GND together.
- Route GPIO10 through the level shifter and series resistor to the LED data input, following the actual PCB schematic.
- Do not power the strip through the ESP32-C3 Super Mini.
- Check the strip's required data protocol, voltage, direction arrow, and current before connecting it.

## Presence sensor OUT

The LD2410C OUT pin is intended as a digital presence indication. The firmware currently assumes **HIGH = presence**; confirm this with the actual module and configuration. If the optional second sensor is not installed, ensure its input cannot float.

## Before first power-up

1. Inspect for solder bridges and incorrect component orientation.
2. With power disconnected, check for shorts between 5 V and GND.
3. Verify connector polarity and the PCB schematic.
4. Power the low-voltage section with current limiting if available.
5. Measure 5 V and 3.3 V rails before connecting the LED strip.
6. Test sensors before enabling the LED output.
