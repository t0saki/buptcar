// #include "bt_serial.h"
#include "pins.h"
#include "ultrasonic.h"
#include "navi.h"

void setup() {
    Serial.begin(9600);
    us_init();
    navi_init();
    motion_init();
}

void loop() {
    if (us_distance()<24) {
        digitalWrite(red,HIGH);
    } else {
        digitalWrite(red,LOW);
    }
    //navi_loop();
    forward(255);
    if (us_distance()<32) {
        stop();
        turn(255);
    }
    delay(50);
}