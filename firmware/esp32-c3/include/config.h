#pragma once

#include <Arduino.h>

// Pin assignment from the current PCB design notes.
// Verify these against the exact ESP32-C3 Super Mini board revision.
constexpr uint8_t PIN_I2C_SDA = 0;
constexpr uint8_t PIN_I2C_SCL = 1;
constexpr uint8_t PIN_PRESENCE_1 = 3;
constexpr uint8_t PIN_PRESENCE_2 = 4;
constexpr uint8_t PIN_LED_DATA = 10;

// Sensor assumptions: verify presence output polarity on the actual module.
constexpr uint8_t PRESENCE_ACTIVE_LEVEL = HIGH;

// BH1750 commonly uses 0x23; some breakouts can be configured for 0x5C.
constexpr uint8_t BH1750_I2C_ADDRESS = 0x23;

// Set this to the number of LEDs in the installed strip.
// Keep at 0 until the strip model and count are confirmed.
constexpr uint16_t LED_COUNT = 0;

// Keep brightness conservative during initial tests (0-255).
constexpr uint8_t LED_BRIGHTNESS = 20;

// How often to print sensor status.
constexpr uint32_t STATUS_INTERVAL_MS = 1000;
