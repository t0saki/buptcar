// #include "bt_serial.h"
#include "beeper.h"
#include "bluetooth.h"
#include "button.h"
#include "commands.h"
#include "navi.h"
#include "pins.h"
#include "rgb_led.h"
#include "ultrasonic.h"
#include "color.h"


void debug() {
    r_wheel(255);
    l_wheel(255);
}

void setup() {
    Serial.begin(9600);

    pinout_init_ultrasonic();
    pinout_init_rgb();
    pinout_init_beeper();
    pinout_init_motor();
    pinout_init_navigation();
    pinin_init_button();
    pinout_init_color();

    // debug();


    waiting_for_press();
    pinMode(13,OUTPUT);

    init_bluetooth();
}


void loop() {
    updateUniversalCommand();

    if (takeControl) {
        stop();
        full_control(ls,rs);
    }

    if (digitalRead(BUTTON_IN1)==LOW) {
        stop();
        delay(1000);
        waiting_for_press();
    }

    navi_loop();

    Sonar();
    delay(15);
    // forward(255);
}