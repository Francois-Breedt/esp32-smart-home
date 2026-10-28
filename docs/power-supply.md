# Power supply and distribution

## Selected supply

Current design notes specify a Mean Well 5 V, 6 A, 30 W open-frame supply.

Nominal output power is 30 W (5 V × 6 A). That rating does not mean every connector, trace, or wire on the PCB can safely carry 6 A.

## Distribution principles

- Feed the LED strip from the power distribution designed for its current, not through the ESP32 board.
- Keep high-current LED paths short and appropriately wide.
- Join grounds so the LED data signal has a common reference.
- Keep sensor and logic power clean; local decoupling is included in the PCB design.
- Check connector current ratings, wire gauge, copper thickness, trace geometry, temperature rise, and protection.
- Select fuse or other over-current protection based on the wiring, connectors, supply, and expected load.

The PCB notes mention 35 µm copper and LED power traces no longer than about 40 mm. These facts alone do not establish a safe current rating; verify the actual geometry and thermal conditions.

## Mains safety

The supply accepts hazardous mains voltage. Keep mains wiring physically separated from low-voltage wiring, use a suitable enclosure and strain relief, and ensure exposed mains terminals cannot be touched. Have mains wiring inspected or completed by a qualified person.

## Commissioning checklist

- [ ] Supply output polarity verified
- [ ] 5 V rail measured under load
- [ ] 3.3 V rail measured
- [ ] LED current estimate checked against supply and connector ratings
- [ ] Temperature checked during a representative maximum-load test
- [ ] Enclosure strain relief and mains/low-voltage separation inspected
