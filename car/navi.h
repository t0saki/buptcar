#include "pins.h"
#include "motion.h"

const int n_navi = 5;
int hw[n_navi] = { 24, 25, 26, 27, 28 };
const int errorpins[n_navi]{ -3,-0.75,0,0.75,3 };

void pinout_init_navigation() {
    for (auto i = 0; i<n_navi; i++) {
        pinMode(hw[i],INPUT);
    }
}

int sensor[n_navi];

float Kp = 32,Ki = 16,Kd = 16;
float error = 0,P = 0,I = 0,D = 0,PID_value = 0;
float previous_error = 0,previous_I = 0;

void get_sensor() {
    for (auto i = 0; i<n_navi; i++) {
        sensor[i] = digitalRead(hw[i]);
    }
}

float navi_loop() {
    get_sensor();
    /**
    if (sensor[0]==0&&sensor[1]!=0&&sensor[2]!=0&&sensor[3]!=0&&sensor[4]!=0) {
        error = -2;
    } else if (sensor[0]==0&&sensor[1]==0&&sensor[2]!=0&&sensor[3]!=0&&sensor[4]!=0) {
        error = -2;
    } else if (sensor[1]==0&&sensor[0]!=0&&sensor[2]!=0&&sensor[3]!=0&&sensor[4]!=0) {
        error = -1;
    } else if (sensor[1]==0&&sensor[0]!=0&&sensor[2]==0&&sensor[3]!=0&&sensor[4]!=0) {
        error = -1;
    } else if (sensor[2]==0&&sensor[1]!=0&&sensor[0]!=0&&sensor[3]!=0&&sensor[4]!=0) {
        error = 0;
    } else if (sensor[2]==0&&sensor[1]==0&&sensor[0]!=0&&sensor[3]==0&&sensor[4]!=0) {
        error = 0;
    } else if (sensor[3]==0&&sensor[1]!=0&&sensor[2]!=0&&sensor[0]!=0&&sensor[4]!=0) {
        error = 1;
    } else if (sensor[3]==0&&sensor[1]!=0&&sensor[2]==0&&sensor[0]!=0&&sensor[4]!=0) {
        error = 1;
    } else if (sensor[4]==0&&sensor[1]!=0&&sensor[2]!=0&&sensor[3]==0&&sensor[0]!=0) {
        error = 2;
    } else if (sensor[4]==0&&sensor[1]!=0&&sensor[2]!=0&&sensor[3]!=0&&sensor[0]!=0) {
        error = 2;
    } else {
        error = 0;
    }
**/
    error = 0;
    for (auto i = 0; i<n_navi; i++) {
        error -= sensor[i]*errorpins[i];
        Serial.print(sensor[i]);
    }
    P = error;
    I = I+previous_I;
    D = error-previous_error;
    PID_value = (Kp*P)+(Ki*I)+(Kd*D);
    previous_I = I;
    previous_error = error;
    turn(PID_value/90);
    Serial.print("");
    Serial.print(PID_value);
    Serial.print(" ");
    Serial.println(error);

    return PID_value;

}