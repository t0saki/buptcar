// #include "bt_serial.h"
#include "beeper.h"
#include "bluetooth.h"
#include "button.h"
#include "navi.h"
#include "pins.h"
#include "rgb_led.h"
#include "ultrasonic.h"

void debug() {
  r_wheel(47);
  l_wheel(47);
}

void setup() {
  Serial.begin(9600);

  pinout_init_ultrasonic();
  pinout_init_rgb();
  pinout_init_beeper();
  pinout_init_motor();
  pinout_init_navigation();
  pinin_init_button();

  // debug();

  waiting_for_press();

  init_bluetooth();
}

void loop() {
  doubleside_bluetooth_check();

  float sonic_distance = us_distance();
  // Serial.print("Sonic dist (cm): ");
  // Serial.print(sonic_distance);
  // Serial.println();

  if (digitalRead(BUTTON_IN1) == LOW) {
    stop();
    delay(1000);
    waiting_for_press();
  }

  navi_loop();

  if (sonic_distance < 32) {
    rgb_setcolor(28, 231, 234);
    beep(2000);
    // stop();
  } else {
    rgb_setcolor(0, 0, 0);
    silent();
  }
  // forward(255);
  // if (sonic_distance < 32)
  // {
  //     stop();
  //     turn(255);
  // }
  delay(25);
  // forward(255);
}