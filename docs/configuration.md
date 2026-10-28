# Firmware configuration

The starter firmware configuration lives in `firmware/esp32-c3/include/config.h`.

Current defaults:

- SDA: GPIO0
- SCL: GPIO1
- Presence 1: GPIO3
- Presence 2: GPIO4
- LED data: GPIO10
- Serial monitor: 115200 baud
- BH1750 I²C address: 0x23 (common default; some modules may use 0x5C)
- LED count: placeholder value; set it to match the installed strip
- Presence output active level: HIGH by default; verify against the module

Do not assume the LED protocol or strip length. Change the LED library/configuration to match the actual strip before relying on lighting behaviour.

## Local configuration

Keep secrets and personal network details out of source control. If Wi-Fi or API credentials are added later, use an ignored local header or a secrets mechanism and commit only a sanitized example file.
