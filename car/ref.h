#pragma once
#define s0 2
#define s1 3
#define s2 4
#define s3 5
#define sensorOut 6
int frequencyR = 0;
int frequencyG = 0;
int frequencyB = 0;

template<class T>
constexpr const T& clamp(const T& v,const T& lo,const T& hi) {
  assert(!(hi<lo));
  return v<lo ? lo : hi<v ? hi : v;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(sensorOut,INPUT);

  // setting frequency-scaling to 20%
  digitalWrite(s0,HIGH);
  digitalWrite(s1,LOW);

  Serial.begin(9600);
}

void loop() {
  // Setting red filtered photodides to be read
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);
  // Reading the output frequency
  frequencyR = pulseIn(sensorOut,LOW);
  // frequencyR = map(frequencyR, 25, 70, 255, 0);
  // frequencyR = clamp(frequencyR, 0, 255);
  // Printing the value on the serial monitor
  Serial.print("R ");
  Serial.print(frequencyR);
  Serial.print(" ");

  digitalWrite(s2,HIGH);
  digitalWrite(s3,HIGH);
  frequencyG = pulseIn(sensorOut,LOW);

  Serial.print("G ");
  Serial.print(frequencyG);
  Serial.print(" ");

  digitalWrite(s2,LOW);
  digitalWrite(s3,HIGH);

  frequencyB = pulseIn(sensorOut,LOW);

  Serial.print("B ");
  Serial.print(frequencyB);
  Serial.println(" ");
  Serial.println();

  // if (frequencyR >= 100 && frequencyG <= 100 && frequencyB <= 100) {
  //   Serial.print("RED");
  //   Serial.println(" ");
  // } else if (frequencyR <= 100 && frequencyG >= 100 && frequencyB <= 100) {
  //   Serial.print("GREEN");
  //   Serial.println(" ");
  // } else if (frequencyR <= 100 && frequencyG <= 100 && frequencyB >= 100) {
  //   Serial.print("BLUE");
  //   Serial.println(" ");
  // } else if (frequencyR >= 220 && frequencyG >= 220 && frequencyB < 220) {
  //   Serial.print("YELLOW");
  //   Serial.println(" ");
  // } else if (frequencyR >= 220 && frequencyG >= 100 && frequencyB >= 100) {
  //   Serial.print("ORANGE");
  //   Serial.println(" ");
  // } else {
  //   Serial.print("NONE");
  //   Serial.println(" ");
  // }
  // delay(300);
}