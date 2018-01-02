//
// Created by Holger on 29.12.2017.
//

#include <Arduino.h>
#include <FastLED.h>
#include "pins.cpp";

const int LED_PIN = DEFAULT_LED_PIN;
int potValue;
int iterations;
int iteration = 0;
int state = LOW;


void setup() {
    Serial.begin(115200);
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    potValue = analogRead(POT_PIN_0);
    iterations = potValue / DELAY_INTERVAL;
    iteration++;
    if (iteration > iterations) {
        if (state == LOW) {
            state = HIGH;
        } else {
            state = LOW;
        }
        iteration = 0;
    }
    Serial.print("Pot: ");
    Serial.print(potValue);
    Serial.print("iteration");
    Serial.print(iteration);
    Serial.print("iterations");
    Serial.println(iterations);
    digitalWrite(LED_PIN, state);
    delay(DELAY_INTERVAL);
}