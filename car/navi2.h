#include "motion.h"
#include "pins.h"

const int n_navi = 5;
int hw[n_navi]   = {24, 25, 26, 27, 28};
const int errorpins[n_navi]{-3, -1, 0, 1, 3};

void pinout_init_navigation() {
  for (auto i = 0; i < n_navi; i++) {
    pinMode(hw[i], INPUT);
  }
}

int sensor[n_navi], turn_rate = 0;

void navi_loop() {
  turn_rate = 0;

  for (auto i = 0; i < n_navi; i++) {
    sensor[i] = digitalRead(hw[i]);
    turn_rate += -85 * sensor[i] * (i - 2);

    // Serial.print(sensor[i]);
    // Serial.print(" ");
  }
  // Serial.println(turn_rate);
  turn(turn_rate);
}