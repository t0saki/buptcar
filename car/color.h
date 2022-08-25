#include "pins.h"

int frequency = 0;
const static String colorName[3] = { "Red", "Green", "Blue" };

void pinout_init_color() {
  Serial.begin(9600);
  pinout_init_color();
}

void pinout_init_color() {
  pinMode(S0,OUTPUT);
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);
  pinMode(sensorOut,INPUT);

  // Frequency scale is 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
}

int get_color() {
  // RED
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  frequency = pulseIn(sensorOut,LOW);
  float r = frequency;

  // GREEN
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  frequency = pulseIn(sensorOut,LOW);
  float g = frequency;

  // BLUE
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  frequency = pulseIn(sensorOut,LOW);
  float b = frequency;

  float sum = r+g+b;

  r /= sum;
  g /= sum;
  b /= sum;

  Serial.print(r);
  Serial.print(" ");
  Serial.print(g);
  Serial.print(" ");
  Serial.print(b);
  Serial.println();

  int colorId = 0;

  if (r<g) {
    if (r<b) {
      colorId = 0;
    } else {
      colorId = 2;
    }
  } else {
    if (g<b) {
      colorId = 1;
    } else {
      colorId = 2;
    }
  }
  //   Serial.print("The current color is ");
  //   Serial.print(colorName[colorId]);
  float ratio = g/b;

  Serial.println(ratio);

  return colorId;
}
