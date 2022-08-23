#include "pins.h"

void r_wheel(int s)
{
    s = s > 255 ? 255 : s;
    s = s < -255 ? -255 : s;
    analogWrite(MOTOR_IN1, s);
    analogWrite(MOTOR_IN2, 0);
}

void l_wheel(int s)
{
    s = s > 255 ? 255 : s;
    s = s < -255 ? -255 : s;
    analogWrite(MOTOR_IN3, s);
    analogWrite(MOTOR_IN4, 0);
}

void motion_init()
{
    pinMode(MOTOR_IN1, OUTPUT);
    pinMode(MOTOR_IN2, OUTPUT);
    pinMode(MOTOR_IN3, OUTPUT);
    pinMode(MOTOR_IN4, OUTPUT);
    digitalWrite(MOTOR_IN1, LOW);
    digitalWrite(MOTOR_IN2, LOW);
    digitalWrite(MOTOR_IN3, LOW);
    digitalWrite(MOTOR_IN4, LOW);
}

void forward(int s)
{
    l_wheel(s);
    r_wheel(s);
}

void stop()
{
    l_wheel(0);
    r_wheel(0);
}

void backward()
{
    l_wheel(-127);
    r_wheel(-127);
}

void run(int d)
{
    if (d == 0)
    {
        forward(255);
    }
}

void turn(int d)
{
    if (d >= 0)
    {
        l_wheel(255);
        r_wheel(255 - d);
    }
    else
    {
        l_wheel(255 + d);
        r_wheel(255);
    }
}
