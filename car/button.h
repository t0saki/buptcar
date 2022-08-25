#include "pins.h"

void pinin_init_button() {
    pinMode(BUTTON_IN1,INPUT);
}

void waiting_for_press() {
    while (digitalRead(BUTTON_IN1)==HIGH) {
        delay(10);
    }
    delay(500);
}