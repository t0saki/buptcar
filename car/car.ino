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
#include "lcd_display.h"

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
    lcd_init();
    set_string(1,"Initializing...");

    // Soft serial config
    serial_init_bluetooth();

    // debug();
    pinMode(13,OUTPUT);
}

void loop() {
    updateUniversalCommand();

    if (takeControl) {
        full_control(ls,rs);
        set_string(0,"Controlled by bluetooth");
        set_string(1,"Please check the host");
    } else {
        // if (digitalRead(BUTTON_IN1) == LOW) {
        //   stop();
        //   delay(1000);
        //   waiting_for_press();
        // }

        navi_loop();
        Sonar();

        lcd.clear();
        set_string(0,"Current Location:");
        set_string(1,String(location));

        delay(15);
        // forward(255);
    }
}