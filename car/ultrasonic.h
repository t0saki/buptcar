#pragma once
#include "pins.h"
#include "color.h"

void pinout_init_ultrasonic() {
    // Ultra sonic pinout init
    pinMode(ULTRA_SONIC_TRIGGER,OUTPUT);
    pinMode(ULTRA_SONIC_ECHO,INPUT);
    pinMode(BEEPER,OUTPUT);
    digitalWrite(ULTRA_SONIC_TRIGGER,LOW);
}

int us_distance() {
    digitalWrite(ULTRA_SONIC_TRIGGER,LOW);
    delayMicroseconds(2);
    digitalWrite(ULTRA_SONIC_TRIGGER,HIGH);
    delayMicroseconds(10);
    digitalWrite(ULTRA_SONIC_TRIGGER,LOW);
    delayMicroseconds(2);
    long duration = pulseIn(ULTRA_SONIC_ECHO,HIGH);
    float distance = duration/58.2f;
    return distance;
}

void Sonar() {
    float sonic_distance = us_distance();
    // Serial.print("Sonic dist (cm): ");
    // Serial.print(sonic_distance);
    // Serial.println();

    if (sonic_distance<10) {
        stop();
        rgb_setcolor(102,204,255);
        beep(2000);
        delay(200);
        silent();
        location = 0;
        lcd.clear();
        set_string(0,"Block detected!");
        waiting_for_press();
    }
}