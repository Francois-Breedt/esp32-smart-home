# ESP32 Smart Home

A modular smart-home hardware and firmware project built around the **ESP32-C3 Super Mini**. The first module combines room-presence detection, ambient-light measurement, and addressable LED control. A Raspberry Pi is intended to provide central coordination.

> **Project status:** Initial repository scaffold. Hardware choices below reflect the current design notes; some implementation details still need confirmation and testing.

## Current design

- **Controller:** ESP32-C3 Super Mini, powered through its 5 V pin
- **Presence:** HLK-LD2410C radar module, using its digital `OUT` output
- **Optional expansion:** second presence-sensor input
- **Ambient light:** BH1750 I²C illuminance sensor
- **Lighting:** addressable LED strip, driven through a 5 V logic-level shifter
- **Power:** Mean Well 5 V / 6 A / 30 W supply
- **PCB:** custom board with bulk capacitance, local ESP32/level-shifter decoupling, series LED-data resistor, and extra LED power/sensor terminals
- **Enclosure:** planned 3D-printed enclosure
- **Central system:** Raspberry Pi
- **Audio:** intentionally outside the scope of this ESP32-C3 module

## Repository layout

```text
docs/                 Wiring, pinout, power, assembly, and troubleshooting
firmware/esp32-c3/    Starter firmware project (PlatformIO / Arduino framework)
hardware/             PCB, schematic, and bill-of-materials placeholders
raspberry-pi/         Notes for central coordination and integration
images/               Project photos and diagrams
```

## Pin assignment

| Function | ESP32-C3 GPIO | Notes |
|---|---:|---|
| BH1750 SDA | GPIO0 | I²C data |
| BH1750 SCL | GPIO1 | I²C clock |
| Presence sensor 1 OUT | GPIO3 | Digital input |
| Presence sensor 2 OUT | GPIO4 | Optional digital input |
| LED data | GPIO10 | Connect to the level-shifter input |

Verify the exact pin labels on the specific ESP32-C3 Super Mini board revision before wiring. Keep boot-strapping and board-specific pin behaviour in mind when changing the pinout.

## Getting started

1. Read [`docs/hardware-overview.md`](docs/hardware-overview.md) and [`docs/wiring.md`](docs/wiring.md).
2. Install [PlatformIO](https://platformio.org/) in VS Code, or use the PlatformIO CLI.
3. Open `firmware/esp32-c3/` as the PlatformIO project.
4. Build and upload the starter firmware.
5. Open the serial monitor at **115200 baud** to see sensor readings.
6. Confirm sensor polarity and LED-strip type before enabling any lighting automation.

The starter firmware is deliberately conservative: it reports sensor state and illuminance, and provides a basic configurable LED test/response. It is not yet a complete home-automation integration.

## Important electrical notes

- The 5 V / 6 A supply can deliver substantial current. Size wiring, connectors, copper, and protection for the expected load.
- Do **not** route LED-strip current through the ESP32 board.
- Connect the LED strip's power directly to the appropriate 5 V/GND distribution, and connect grounds together so the data signal has a reference.
- Confirm that the level shifter is suitable for the LED protocol and that its supply and enable pins are wired correctly.
- Mains wiring is hazardous. Enclose and strain-relieve it properly, maintain separation between mains and low-voltage circuits, and have the mains side assembled/checked by a qualified person.
- The exact LED model, strip length, current draw, connector ratings, fuse strategy, and final PCB layout must be verified before installation.

## Documentation

- [Hardware overview](docs/hardware-overview.md)
- [Pinout](docs/pinout.md)
- [Wiring](docs/wiring.md)
- [Power supply](docs/power-supply.md)
- [PCB design notes](docs/pcb-design.md)
- [Assembly](docs/assembly.md)
- [Firmware configuration](docs/configuration.md)
- [Troubleshooting](docs/troubleshooting.md)
- [Raspberry Pi integration](raspberry-pi/README.md)

## Contributing / revisions

Track hardware changes with PCB revision identifiers and update the wiring/pinout documents whenever a connector, component, or GPIO assignment changes. Avoid committing Wi-Fi passwords, API tokens, private network credentials, or other secrets.

## License

This repository currently uses the MIT License; see [`LICENSE`](LICENSE). Change it before publishing if you prefer another license.
