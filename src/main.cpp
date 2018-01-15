//
// Created by Holger on 29.12.2017.
//

#include <Arduino.h>
#include <FastLED.h>

const int LED_PIN = 12;
const int NUM_LEDS = 12;

const uint8_t POT_PIN_0 = A0;
const uint8_t POT_PIN_1 = A1;
const uint8_t POT_PIN_2 = A2;

int potValue0;
int potValue1;
int potValue2;
int previousPotValue0;
int previousPotValue1;
int previousPotValue2;
byte hueValue = 0;
byte saturationValue = 0;

CRGB leds[NUM_LEDS];

byte normalizeValue(int value) {
    return (byte) map(value, 0, 1023, 0, 255);
}

void handlePotChange0(int value) {
    previousPotValue0 = value;
    hueValue = normalizeValue(value);
}

void handlePotChange1(int value) {
    previousPotValue1 = value;
    saturationValue = (byte) map(value, 0, 1023, 100, 255);;
}

void updateLedsHsv(uint8_t hueValue, uint8_t saturationValue, uint8_t brightnessValue) {
    for (auto led : leds) {
        led = CHSV(hueValue, saturationValue, brightnessValue);
    }

    fadeToBlackBy(leds, NUM_LEDS, 20);
    // Show the leds
    FastLED.show();
}


void setup() {
    Serial.begin(115200);
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(84);
    potValue0 = 0;
    potValue1 = 0;
    potValue2 = 0;
    previousPotValue0 = 1;
    previousPotValue1 = 1;
    previousPotValue2 = 1;
    updateLedsHsv(55, 200, 90);
}

int angle = 0;
uint8_t speed = 15;

void loop() {
    potValue0 = analogRead(POT_PIN_0);
    potValue1 = analogRead(POT_PIN_1);
    potValue2 = analogRead(POT_PIN_2);

    if (previousPotValue0 != potValue0) {
        handlePotChange0(potValue0);
    }

    if (previousPotValue1 != potValue1) {
        handlePotChange1(potValue1);
    }

    if (previousPotValue2 != potValue2) {
        speed = (uint8_t) map(potValue2, 0, 1024, 3, 30);
    }

    EVERY_N_MILLIS_I(thistimer, speed) { // initial period = 100ms
        thistimer.setPeriod(speed); // random period 10..200ms
        auto lead_dot = (uint8_t) map(sin8(angle), 0, 255, 0, NUM_LEDS - 1);
        angle = angle + 1;
        leds[lead_dot] = CHSV(hueValue, saturationValue, 96);;

        fadeToBlackBy(leds, NUM_LEDS, 32);
    }
    FastLED.show();
}