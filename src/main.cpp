//
// Created by Holger on 29.12.2017.
//

#include <Arduino.h>
#include <FastLED.h>
#include "pins.cpp";

int potValue;
int previousPotValue;
int hueValue;

CRGB leds[NUM_LEDS];

void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
    LEDS.addLeds<WS2812, LED_PIN,GRB>(leds,NUM_LEDS);
    LEDS.setBrightness(84);
}

void loop() {
    potValue = analogRead(POT_PIN_0);
    if (previousPotValue != potValue) {
        hueValue = potValue / 4;
        for(int i = 0; i < NUM_LEDS; i++) {
            // Set the i'th led to red
            leds[i] = CHSV(hueValue, 255, 255);
            // Show the leds
            FastLED.show();
        }
        previousPotValue = potValue;
    }
    Serial.print("Pot: ");
    Serial.print(potValue);
    Serial.print("Hue: ");
    Serial.println(hueValue);
    delay(DELAY_INTERVAL);
}