#include "pins.h"


void r_wheel(int s) {
    s = s>255 ? 255 : s;
    s = s<-255 ? -255 : s;
    analogWrite(in1,s);
    analogWrite(in2,0);
}

void l_wheel(int s) {
    s = s>255 ? 255 : s;
    s = s<-255 ? -255 : s;
    analogWrite(in3,s);
    analogWrite(in4,0);
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
    l_wheel(s);
    r_wheel(s);
}

void stop() {
    l_wheel(0);
    r_wheel(0);
}

void backward() {
    l_wheel(-127);
    r_wheel(-127);
}

void run(int d) {
    if (d==0) {
        forward(255);
    }
}

void turn(int d) {
    if (d>=0) {
        l_wheel(255);
        r_wheel(255-d);
    } else {
        l_wheel(255+d);
        r_wheel(255);
    }
}




