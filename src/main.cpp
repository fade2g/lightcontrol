//
// Created by Holger on 29.12.2017.
//

#include <Arduino.h>

const int LED_PIN = 0;

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_PIN, HIGH);
    delay(200);
    digitalWrite(LED_PIN, LOW);
    delay(200);
}