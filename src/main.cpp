//
// Created by Holger on 29.12.2017.
//

#include <Arduino.h>
#include <FastLED.h>
// #include "pins.cpp"

const int LED_PIN = 12;
const int DELAY_WAIT = 20;
const int DELAY_INTERVAL = 20;
const int NUM_LEDS = 12;

const int POT_PIN_0 = A0;
const int POT_PIN_1 = A1;
const int POT_PIN_2 = A2;


struct CircleAnmiationHolder {
    int speed;
    int frame;
};

int potValue0;
int potValue1;
int potValue2;
int previousPotValue0;
int previousPotValue1;
int previousPotValue2;
byte hueValue = 0;
byte saturationValue = 0;
byte brightnessValue = 100;
boolean changed;

CRGB leds[NUM_LEDS];

byte normalizeValue(int value) {
    return map(value, 0, 1023, 0, 255);
}

void handlePotChange0(int value) {
    previousPotValue0 = value;
    hueValue = normalizeValue(value);
}

void handlePotChange1(int value) {
    previousPotValue1 = value;
    saturationValue = normalizeValue(value);
}

void handlePotChange2(int value) {
    previousPotValue2 = value;
    brightnessValue = normalizeValue(value);
}

void updateLedsHsv(int hueValue, int saturationValue, int brightnessValue) {
    for(int i = 0; i < NUM_LEDS; i++) {
        // Set the i'th led to red
        leds[i] = CHSV(hueValue, saturationValue, brightnessValue);
    }
    fadeToBlackBy( leds, NUM_LEDS, 20);
    // Show the leds
    FastLED.show();
}

void fillColor(byte hue, byte sat, byte val) {
    CHSV color = CHSV(hue, sat, val);
    fill_solid(leds, NUM_LEDS, color);
    fadeToBlackBy( leds, NUM_LEDS, 20);
}


void circleAnimation(CircleAnmiationHolder holder) {
}

void setup() {
    Serial.begin(115200);
    // pinMode(LED_PIN, OUTPUT);
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
int speed = 15;

void loop() {
    potValue0 = analogRead(POT_PIN_0);
    potValue1 = analogRead(POT_PIN_1);
    potValue2 = analogRead(POT_PIN_2);

    if (previousPotValue0 != potValue0) {
        handlePotChange0(potValue0);
        changed=true;
    }

    if (previousPotValue1 != potValue1) {
        handlePotChange1(potValue1);
        changed=true;
    }

    if (previousPotValue2 != potValue2) {
        speed = map(potValue2, 0, 1024, 3, 30);
        changed=true;
    }

    Serial.print("PotValue");
    Serial.print(potValue2);
    Serial.print(", speed: ");
    Serial.println(speed);

    EVERY_N_MILLIS_I( thistimer, speed ) { // initial period = 100ms
        thistimer.setPeriod( speed ); // random period 10..200ms
        uint8_t lead_dot = map(sin8(angle), 0, 255, 0, NUM_LEDS - 1);
        angle = angle + 1;
        leds[lead_dot] = CHSV( hueValue, saturationValue, 96);;

        fadeToBlackBy(leds, NUM_LEDS, 32);
    }
    FastLED.show();

/*
    if (previousPotValue2 != potValue2) {
        handlePotChange2(potValue2);
        changed=true;
    }

    if(changed) {
//        updateLedsHsv(hueValue, saturationValue, brightnessValue);
//        updateLedsHsv(hueValue, saturationValue, brightnessValue);
        changed=false;
    }
    fadeToBlackBy( leds, NUM_LEDS, 20);
    Serial.print("hue: ");
    Serial.print(hueValue);
    Serial.print("saturation: ");
    Serial.print(saturationValue);
    Serial.print("brightness: ");
    Serial.println(brightnessValue);
    // updateLedsHsv(hueValue, saturationValue, brightnessValue);
    fillColor(200, 20, 20);
    FastLED.show();
*/
//     delay(DELAY_INTERVAL);
}