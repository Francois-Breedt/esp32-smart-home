# Hardware overview

## Module purpose

The module is intended to detect room occupancy, measure ambient illuminance, and control an addressable LED strip. The ESP32-C3 handles local sensor reading and LED output; a Raspberry Pi may coordinate multiple modules later.

## Current bill of major parts

| Part | Purpose | Status |
|---|---|---|
| ESP32-C3 Super Mini | Main controller | Selected |
| HLK-LD2410C | Radar presence sensor | Selected |
| Second digital presence sensor | Optional expansion | Connector planned |
| BH1750 | Ambient illuminance sensor over I²C | Selected |
| 5 V addressable LED strip | Lighting | Protocol/model to confirm |
| 5 V logic-level shifter | Translate ESP32 data to LED logic level | Included in PCB design |
| Series resistor on LED data | Signal edge/ringing mitigation | Included in PCB design |
| Bulk capacitor | Local supply energy storage | Included in PCB design |
| Mean Well 5 V, 6 A, 30 W supply | Power source | Selected |
| Custom PCB and 3D-printed enclosure | Integration | In progress |

## Sensor placement

The LD2410C is planned to be mounted on a shelf or piece of furniture, with the goal of detecting people throughout the room. Actual coverage depends on mounting height, orientation, room geometry, and sensor configuration. Test the installed position rather than assuming the nominal range guarantees room-wide coverage.

Keep the BH1750 exposed to representative room light. Avoid positioning it where the LED strip shines directly into it unless that feedback is intentional.

## Items to confirm

- Exact LED strip model, voltage, protocol, and maximum current
- Exact level-shifter part number and circuit
- Final connector pin order and PCB revision
- Whether the second presence input is populated
- How modules will communicate with the Raspberry Pi
- Whether the firmware should remain PlatformIO/Arduino or move to ESP-IDF
