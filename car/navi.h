#include "pins.h"
#include "motion.h"

const int n_navi = 5;
int hw[5] = { 24,25,26,27,28 };

void navi_init() {
    for (auto i = 0;i<n_navi;i++) {
        pinMode(hw[i],INPUT);
    }
}

int sensor[5];

void navi_loop() {
    for (auto i = 0;i<n_navi;i++) {
        sensor[i] = digitalRead(hw[i]);
        //Serial.print(' ');
    }
    if (!sensor[0]) {
        turn(-255);
    } else if (!sensor[1]) {
        turn(-127);
    } else if (!sensor[3]) {
        turn(127);
    } else if (!sensor[4]) {
        turn(255);
    } else {
        forward(255);
    }
}