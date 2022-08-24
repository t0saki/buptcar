// #include "bt_serial.h"
#include "pins.h"
#include "ultrasonic.h"
#include "navi.h"
#include "rgb_led.h"
#include "beeper.h"

void setup() {
    Serial.begin(9600);

    pinout_init_ultrasonic();
    pinout_init_rgb();
    pinout_init_beeper();
    pinout_init_motor();
    pinout_init_navigation();
}

void loop() {
    float sonic_distance = us_distance();
    // Serial.print("Sonic dist (cm): ");
    // Serial.print(sonic_distance);
    // Serial.println();

    navi_loop();

    if (sonic_distance<24) {
        rgb_setcolor(28,231,234);
        beep(2000);
        // stop();
    } else {
        rgb_setcolor(0,0,0);
        silent();
    }
    // forward(255);
    // if (sonic_distance < 32)
    // {
    //     stop();
    //     turn(255);
    // }

    delay(50);

    // forward(255);
}