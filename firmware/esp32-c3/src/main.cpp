#include <Arduino.h>
#include <Wire.h>
#include <BH1750.h>
#include <Adafruit_NeoPixel.h>

#include "config.h"

BH1750 lightSensor;
Adafruit_NeoPixel leds(LED_COUNT, PIN_LED_DATA, NEO_GRB + NEO_KHZ800);

bool lightSensorReady = false;
uint32_t lastStatusMs = 0;

bool readPresence(uint8_t pin) {
    return digitalRead(pin) == PRESENCE_ACTIVE_LEVEL;
}

void updateLeds(bool occupied) {
    if (LED_COUNT == 0) {
        return; // LED count has not been configured yet.
    }

    // Basic commissioning behaviour only; tune the final lighting policy later.
    const uint32_t colour = occupied
        ? leds.Color(255, 180, 80)
        : leds.Color(0, 0, 0);

    for (uint16_t i = 0; i < LED_COUNT; ++i) {
        leds.setPixelColor(i, colour);
    }
    leds.show();
}

void setup() {
    Serial.begin(115200);
    delay(300);

    pinMode(PIN_PRESENCE_1, INPUT);
    pinMode(PIN_PRESENCE_2, INPUT);

    Wire.begin(PIN_I2C_SDA, PIN_I2C_SCL);

    lightSensorReady = lightSensor.begin(
        BH1750::CONTINUOUS_HIGH_RES_MODE,
        BH1750_I2C_ADDRESS,
        &Wire
    );

    if (LED_COUNT > 0) {
        leds.begin();
        leds.setBrightness(LED_BRIGHTNESS);
        leds.clear();
        leds.show();
    }

    Serial.println();
    Serial.println(F("ESP32-C3 Smart Home module starting"));
    Serial.printf("Presence active level: %s\n",
                  PRESENCE_ACTIVE_LEVEL == HIGH ? "HIGH" : "LOW");
    Serial.printf("BH1750: %s\n", lightSensorReady ? "ready" : "not detected");
    Serial.printf("LED count: %u\n", LED_COUNT);
    Serial.println(F("Status output at 115200 baud."));
}

void loop() {
    const bool presence1 = readPresence(PIN_PRESENCE_1);
    const bool presence2 = readPresence(PIN_PRESENCE_2);
    const bool occupied = presence1 || presence2;

    updateLeds(occupied);

    const uint32_t now = millis();
    if (now - lastStatusMs >= STATUS_INTERVAL_MS) {
        lastStatusMs = now;

        Serial.printf("Presence 1: %s | Presence 2: %s | Occupied: %s",
                      presence1 ? "YES" : "no",
                      presence2 ? "YES" : "no",
                      occupied ? "YES" : "no");

        if (lightSensorReady) {
            const float lux = lightSensor.readLightLevel();
            Serial.printf(" | Ambient light: %.1f lux", lux);
        } else {
            Serial.print(F(" | Ambient light: unavailable"));
        }
        Serial.println();
    }

    delay(20);
}
