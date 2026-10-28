# Troubleshooting

## BH1750 is not detected

- Check 3.3 V and GND at the sensor.
- Verify SDA/SCL wiring and GPIO assignments.
- Check whether the breakout uses address `0x23` or `0x5C`.
- Check for I²C pull-ups and solder bridges.

## Presence input never changes

- Verify the sensor is powered at the voltage required by its board.
- Confirm OUT and GND wiring.
- Check the OUT signal with a meter or logic analyser.
- Verify whether presence is active HIGH or active LOW.
- Ensure unused digital inputs are not floating.

## LEDs stay off or flicker

- Verify the strip voltage, ground, data direction, and protocol.
- Confirm the level shifter has the correct supply and common ground.
- Check the data resistor and wiring length.
- Confirm LED count and library settings.
- Test with low brightness and a known-good short strip.

## ESP32 resets

- Check for 5 V dips during LED load changes.
- Ensure LED current does not pass through the ESP32 board.
- Inspect the USB/5 V power arrangement and common ground.
- Check serial logs for brownout or watchdog messages.

## Safety

Disconnect mains power before inspecting the enclosure or wiring. Do not probe exposed mains terminals unless qualified and equipped to do so.
