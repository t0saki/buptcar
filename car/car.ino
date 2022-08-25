// #include "bt_serial.h"
#include "beeper.h"
#include "bluetooth.h"
#include "button.h"
#include "color.h"
#include "commands.h"
#include "navi.h"
#include "pins.h"
#include "rgb_led.h"
#include "ultrasonic.h"

void debug() {
  r_wheel(255);
  l_wheel(255);
}

void setup() {
  // Serial config
  Serial.begin(9600);
  Serial.print("Serial begin 9600");

  // Pinout declarations
  pinout_init_ultrasonic();
  pinout_init_rgb();
  pinout_init_beeper();
  pinout_init_motor();
  pinout_init_navigation();
  pinout_init_button();
  pinout_init_color();

  // Soft serial config
  serial_init_bluetooth();

  // debug();
  pinMode(13, OUTPUT);

  // waiting_for_press();
}

void loop() {
  updateUniversalCommand();

  if (takeControl) {
    full_control(ls, rs);
  } else
    stop();

  Sonar();

  if (digitalRead(BUTTON_IN1) == LOW) {
    stop();
    delay(1000);
    waiting_for_press();
  }

  navi_loop();
  delay(15);
  // forward(255);
}