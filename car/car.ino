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

char universalCommand = ' ';

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
    pinout_init_ultrasonic();
    pinout_init_rgb();
    pinout_init_beeper();
    pinout_init_motor();
    pinout_init_navigation();
    pinin_init_button();
    pinMode(13,OUTPUT);

    init_bluetooth();
}

int ls = 0;
int rs = 0;
bool takeControl = true;
const int maxControllingSpeed = 255;

// Update the universal command from bt
void updateUniversalCommand() {
    Serial.print(ls);
    Serial.print(" ");
    Serial.print(rs);

    Serial.println();

    universalCommand = command_check();

    switch (universalCommand) {
    case COMMAND_START_LISTEN:
        takeControl = true;
        break;
    case COMMAND_STOP_LISTEN:
        takeControl = false;
        break;

        // Left
    case COMMAND_L_WHEEL_FORWARD:
        ls = maxControllingSpeed;
        break;
    case COMMAND_L_WHEEL_FORWARD_S:
        ls = 0;
        break;
    case COMMAND_L_WHEEL_BACKWARD:
        ls = -maxControllingSpeed;
        break;
    case COMMAND_L_WHEEL_BACKWARD_S:
        ls = 0;
        break;

        // Right
    case COMMAND_R_WHEEL_FORWARD:
        rs = maxControllingSpeed;
        break;
    case COMMAND_R_WHEEL_FORWARD_S:
        rs = 0;
        break;
    case COMMAND_R_WHEEL_BACKWARD:
        rs = -maxControllingSpeed;
        break;
    case COMMAND_R_WHEEL_BACKWARD_S:
        rs = 0;
        break;
    case COMMAND_BOARDLED_ON:
        digitalWrite(13,HIGH);
        break;
    case COMMAND_BOARDLED_OFF:
        digitalWrite(13,LOW);
        break;
    }
}

void Sonar() {
    float sonic_distance = us_distance();
    // Serial.print("Sonic dist (cm): ");
    // Serial.print(sonic_distance);
    // Serial.println();

    if (sonic_distance<32) {
        rgb_setcolor(28,231,234);
        beep(2000);
    } else {
        rgb_setcolor(0,0,0);
        silent();
    }
}

void loop() {
    updateUniversalCommand();

    if (takeControl) {
        stop();
        full_control(ls,rs);
    }

    //   if (digitalRead(BUTTON_IN1) == LOW) {
    //     stop();
    //     delay(1000);
    //     waiting_for_press();
    //   }

    //   navi_loop();

    //Sonar();
    get_color();
    delay(25);
    // forward(255);
}