#include "pins.h"
#include "motion.h"

const int n_navi = 5;
int hw[5] = { 24,25,26,27,28 };

void navi_init() {
    for (auto i = 0;i<n_navi;i++) {
        pinMode(hw[i],INPUT);
    }
}

void navi_loop() {
    for (auto i = 0;i<n_navi;i++) {
        Serial.print(digitalRead(hw[i]));
        //Serial.print(' ');
    }
    Serial.print('\n');
    run(0);
}