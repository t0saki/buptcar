#include "pins.h"

void us_init() {
    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);
    pinMode(red,OUTPUT);
    digitalWrite(trig,LOW);
    digitalWrite(red,LOW);
}

void us_loop() {
    digitalWrite(trig,HIGH);
    delayMicroseconds(4);
    digitalWrite(trig,LOW);
    long duration = pulseIn(echo,HIGH);
    float distance = duration/58.2;
    delay(1000);
}

int us_distance() {
    digitalWrite(trig,HIGH);
    delayMicroseconds(4);
    digitalWrite(trig,LOW);
    long duration = pulseIn(echo,HIGH);
    float distance = duration/58.2;
    return distance;
}