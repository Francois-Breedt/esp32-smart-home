# Pinout reference

Current intended assignment for the ESP32-C3 Super Mini:

| GPIO | Function | Direction | Notes |
|---|---|---|---|
| GPIO0 | BH1750 SDA | Bidirectional | I²C data |
| GPIO1 | BH1750 SCL | Output/open-drain via I²C | I²C clock |
| GPIO3 | LD2410C OUT / presence 1 | Input | Digital presence state |
| GPIO4 | Optional presence sensor 2 OUT | Input | May remain unused |
| GPIO10 | LED data | Output | Goes to level-shifter input, not directly to a 5 V LED data input unless the strip explicitly supports 3.3 V logic |

## Connector labels

Document the actual PCB connector pin order here once the layout is final. Do not rely on wire colour alone; label both ends and verify polarity with a meter before powering the board.

## Validation checklist

- [ ] Check GPIO labels against the exact ESP32-C3 Super Mini board
- [ ] Confirm SDA/SCL mapping in firmware
- [ ] Confirm presence outputs share a common ground with the ESP32
- [ ] Confirm LED data passes through the level shifter
- [ ] Confirm GPIO4 input has a defined state when no second sensor is connected
