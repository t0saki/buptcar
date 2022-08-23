// #include "bt_serial.h"
#include "pins.h"
#include "ultrasonic.h"
#include "navi.h"
#include "rgb_led.h"

void setup()
{
    Serial.begin(9600);

    us_init();
    rgb_pinout_init();
    navi_init();
    motion_init();
}

void loop()
{
    // float sonic_distance = us_distance();
    // Serial.println(sonic_distance);

    // if (sonic_distance < 24)
    // {
    //     rgb_setcolor(239, 170, 144);
    //     digitalWrite(BEEPER, LOW);
    // }
    // else
    // {
    //     rgb_setcolor(28, 231, 234);
    //     digitalWrite(BEEPER, HIGH);
    // }

    // // navi_loop();
    // forward(255);
    // if (sonic_distance < 32)
    // {
    //     stop();
    //     turn(255);
    // }

    // delay(50);

    forward(255);
}