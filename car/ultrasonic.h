#include "pins.h"

void us_init()
{
    // Ultra sonic pinout init
    pinMode(ULTRA_SONIC_TRIGGER, OUTPUT);
    pinMode(ULTRA_SONIC_ECHO, INPUT);
    pinMode(BEEPER, OUTPUT);
    digitalWrite(ULTRA_SONIC_TRIGGER, LOW);
}

int us_distance()
{
    digitalWrite(ULTRA_SONIC_TRIGGER, LOW);
    delayMicroseconds(2);
    digitalWrite(ULTRA_SONIC_TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(ULTRA_SONIC_TRIGGER, LOW);
    delayMicroseconds(2);
    long duration = pulseIn(ULTRA_SONIC_ECHO, HIGH);
    float distance = duration / 58.2f;
    return distance;
}