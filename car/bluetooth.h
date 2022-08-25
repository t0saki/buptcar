#include "pins.h"
#include <SoftwareSerial.h>

// 设置软串口使用的针脚
SoftwareSerial softSerial(RX, TX);

void init_bluetooth() {
  softSerial.begin(9600); //设定软串口波特率
  Serial.println("Bluetooth is ready");
}

void doubleside_bluetooth_check() {
  if (softSerial.available()) { //如果HC-06发来数据
    int k = softSerial.read();
    //读取1个字节的数据
    Serial.write(k); //通过硬串口打印输出
  }
  if (Serial.available()) //检测：【串口】如果数据写入，则执行
  {
    digitalWrite(13, !digitalRead(13));
    int x = Serial.read(); //把写入的数据给到自定义变量x
    softSerial.write(x);
  }
}

char command_check() {
  char command = ' ';

  if (softSerial.available()) // 检测：【蓝牙】如果数据写入，则执行
  {
    command = softSerial.read();
    if ((int)command == 13 || (int)command == 10) { // 排除干扰（换行符）
      command = ' ';
    }
  }

  if (command != ' ') {
    Serial.println((int)command); // 打印
  }
  return command;
}
