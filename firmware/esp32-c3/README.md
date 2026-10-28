# ESP32-C3 firmware

Starter firmware for the ESP32-C3 smart-home module.

## Toolchain

This project uses PlatformIO with the Arduino framework as a starting point. If the final project uses ESP-IDF instead, the project can be migrated without changing the repository's documentation structure.

## Build and upload

1. Install VS Code and the PlatformIO IDE extension, or install the PlatformIO CLI.
2. Open this directory as the project.
3. Connect the ESP32-C3 Super Mini over USB.
4. Build and upload.
5. Open the serial monitor at 115200 baud.

## What it currently does

- Initializes the BH1750 over I²C and reports illuminance when available.
- Reads the two digital presence inputs.
- Initializes an addressable LED strip using the Adafruit NeoPixel library.
- Provides a conservative LED response when presence is detected, subject to the configured LED count and brightness.

Confirm the strip's protocol and model before using this firmware in a permanent installation. The initial LED library is a starting point, not a claim that every addressable strip is compatible.
