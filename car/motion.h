#include "pins.h"


void l_wheel(int s) {
    digitalWrite(in1,s);
    digitalWrite(in2,!s);
}

void r_wheel(int s) {
    digitalWrite(in3,s);
    digitalWrite(in4,!s);
}

void motion_init() {
    pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
    pinMode(in3,OUTPUT);
    pinMode(in4,OUTPUT);
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
}

void forward(int s) {
    l_wheel(s/256);
    r_wheel(s/256);
}

void stop() {
    l_wheel(0);
    r_wheel(0);
}

void backward() {
    l_wheel(-1);
    r_wheel(-1);
}

void run(int d) {
    if (d==0) {
        l_wheel(1);
        forward();
    }
}





