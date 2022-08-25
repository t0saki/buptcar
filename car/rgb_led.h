#pragma once

#include "pins.h"

void rgb_setcolor(int r, int g, int b) {
  analogWrite(RGB_R, r);
  analogWrite(RGB_G, g);
  analogWrite(RGB_B, b);
}

void pinout_init_rgb() {
  // RGB init
  pinMode(RGB_B, OUTPUT);
  pinMode(RGB_G, OUTPUT);
  pinMode(RGB_R, OUTPUT);

  rgb_setcolor(0, 0, 0);
}