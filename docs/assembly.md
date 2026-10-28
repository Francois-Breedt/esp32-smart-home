# Assembly and installation

## Suggested assembly sequence

1. Inspect the PCB and components against the bill of materials.
2. Solder low-profile components first, checking polarity and orientation.
3. Inspect solder joints and check for shorts between power rails.
4. Install the ESP32-C3 Super Mini, level shifter, connectors, and capacitors.
5. Test the board without the LED strip attached.
6. Verify the sensor readings over serial.
7. Connect the LED strip only after verifying power, ground, and data direction.
8. Test at low LED brightness before increasing the load.
9. Fit the PCB and power supply into the enclosure and check strain relief and clearances.
10. Test the complete module under realistic load and temperature conditions.

## Installation considerations

- Place the presence sensor where it has a clear view of the room, then tune and test its configuration.
- Place the BH1750 where it measures useful ambient light rather than direct LED glare.
- Keep the module accessible for firmware updates and troubleshooting.
- Ensure the enclosure allows appropriate thermal management and protects users from electrical hazards.

## Record the build

For each assembled module, record the PCB revision, firmware version, sensor configuration, LED strip model/length, and installation location (avoid publishing a private home address).
