#pragma once
#include "motion.h"
#include "pins.h"

const int n_navi = 5;
int hw[n_navi] = { 24, 25, 26, 27, 28 };
const float errorpins[n_navi]{ -3, -0.75, 0, 0.75, 3 };

void pinout_init_navigation() {
  for (auto i = 0; i<n_navi; i++) {
    pinMode(hw[i],INPUT);
  }
}

int sensor[n_navi];

float Kp = 26,Ki = 2,Kd = 4;
float P = 0,I = 0,D = 0,PID_value = 0,error = 0;
float previous_error = 0,previous_I = 0;
int decide = 0;

float s1 = 1.5,s2 = 2.2,s3 = 3.6,sh = 0.5;

float sigmoid(float x) { return (1/(1+exp(-x))-0.5)*2; }

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
/**
    if ((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[3
    ]==1)&&(sensor[4]==1)) {
        decide = 1;//十字路口 1 1 1 1 1   直行
    } else if ((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(
        sensor[3]==1)&&(sensor[4]==0)) {
        decide = 1;//十字路口 0 1 1 1 0   直行
    } else if ((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(
        sensor[3]==1)&&(sensor[4]==1)) {
        decide = 2;//90度路口 0 0 1 1 1    右转90度
        error = s2;
    } else if ((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(
        sensor[3]==1)&&(sensor[4]==0)) {
        decide = 2;//90度路口 0 0 1 1 0    右转90度
        error = s1;
    } else if ((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==1)&&(
        sensor[3]==0)&&(sensor[4]==0)) {
        decide = 3;//90度路口 1 1 1 0 0    左转90度
        error = -s2;
    } else if ((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(
        sensor[3]==0)&&(sensor[4]==0)) {
        decide = 3;//90度路口 0 1 1 0 0    左转90度
        error = -s1;
    } else if ((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(
        sensor[3]==0)&&(sensor[4]==0)) {
        decide = 3;//向上锐角 0 1 1 0 0    向上锐角
        error = -s1;
    } else if ((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(
        sensor[3]==0)&&(sensor[4]==1)) {
        error = s2;//          0 0 0 0 1
    } else if ((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(
        sensor[3]==1)&&(sensor[4]==0)) {
        error = s1;//          0 0 0 1 0
    } else if ((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(
        sensor[3]==0)&&(sensor[4]==0)) {
        error = 0;//          0 0 1 0 0
    } else if ((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==0)&&(
        sensor[3]==0)&&(sensor[4]==0)) {
        error = -s1;//         0 1 0 0 0
    } else if ((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(
        sensor[3]==0)&&(sensor[4]==0)) {
        error = -s2;//         1 0 0 0 0
    } else if ((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(
        sensor[3]==0)&&(sensor[4]==0)) {
        if (error==-2) {//  0 0 0 0 0
            error = -s3;
        } else {
            error = s3;
        }
    }
**/

  if (!sensor[0]) {
    error = -s2;
  } else if (!sensor[4]) {
    error = s2;
  } else if (!sensor[1]) {
    error = -s1;
  } else if (!sensor[3]) {
    error = s1;
  } else if (!sensor[2]) {
    if (error<0) {
      error = sh;
    } else {
      error = -sh;
    }
  } else {
    if (error==-s2) {
      error = -s3;
    } else if (error==s2) {
      error = s3;
    } else {
      error = error;
    }
  }

  // for (auto i = 0; i<n_navi; i++) {
  //     error -= sensor[i]*errorpins[i];
  //     // Serial.print(sensor[i]);
  // }
  P = error;
  I = I+previous_I;
  D = error-previous_error;
  PID_value = (Kp*P)+(Ki*I)+(Kd*D);
  previous_I = I;
  previous_error = error;
  turn(PID_value/64);
  // Serial.print("");
  // Serial.println(PID_value);
  // Serial.print(" ");
  // Serial.println(sigmoid(PID_value/60));
  // Serial.print(" ");
  // Serial.println(error);

  return PID_value;
}