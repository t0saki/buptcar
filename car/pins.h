#pragma once


// #define max_speed 63
#define max_speed 74

#define ULTRA_SONIC_TRIGGER 52 // Sonic trigger
#define ULTRA_SONIC_ECHO 53    // Sonic echo

#define RX 10 // Bluetooth Serial
#define TX 9

#define RGB_B 42 // RGB - Blue
#define RGB_R 43 // RGB - Red
#define RGB_G 44 // RGB - Green

#define S0 36 // Color sensor
#define S1 37
#define S2 38
#define S3 39
#define sensorOut 40

#define DEBUG_BOARD_LED 13 // On board LED

#define BEEPER 45 // Beeper LOW ACTIVE

#define MOTOR_IN1 2 // Motor
#define MOTOR_IN2 3
#define MOTOR_IN3 4
#define MOTOR_IN4 5

#define BEEPER_PIN 46 // Beeper

#define BUTTON_IN1 34 // Button

extern int hw[5];

int location = 0;