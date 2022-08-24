#include "pins.h"

#define max_speed 63

void r_wheel(int s) {
    s = s>max_speed ? max_speed : s;
    s = s<0 ? 0 : s;
    analogWrite(MOTOR_IN1,s);
    analogWrite(MOTOR_IN2,0);
}

void l_wheel(int s) {
    s = s>max_speed ? max_speed : s;
    s = s<0 ? 0 : s;
    analogWrite(MOTOR_IN3,s);
    analogWrite(MOTOR_IN4,0);
}

void pinout_init_motor() {
    pinMode(MOTOR_IN1,OUTPUT);
    pinMode(MOTOR_IN2,OUTPUT);
    pinMode(MOTOR_IN3,OUTPUT);
    pinMode(MOTOR_IN4,OUTPUT);
    digitalWrite(MOTOR_IN1,LOW);
    digitalWrite(MOTOR_IN2,LOW);
    digitalWrite(MOTOR_IN3,LOW);
    digitalWrite(MOTOR_IN4,LOW);
}

void forward(int s) {
    l_wheel(s);
    r_wheel(s);
}

void stop() {
    l_wheel(0);
    r_wheel(0);
}

void backward() {
    l_wheel(-max_speed/2);
    r_wheel(-max_speed/2);
}

void run(int d) {
    if (d==0) {
        forward(max_speed);
    }
}

void turn(float d) {
    if (d>=0) {
        l_wheel(max_speed);
        r_wheel(max_speed*(1-d));
    } else {
        l_wheel(max_speed*(1+d));
        r_wheel(max_speed);
    }
}
