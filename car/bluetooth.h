#pragma once
#include "commands.h"
#include "motion.h"
#include "pins.h"
#include <SoftwareSerial.h>

// 设置软串口使用的针脚
SoftwareSerial softSerial(RX, TX);

char universalCommand     = ' ';
char universalCommandPrev = ' ';

void serial_init_bluetooth() {
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

  return command;
}

int ls                        = 0;
int rs                        = 0;
bool takeControl              = true;
bool takeControlPrev          = false;
const int maxControllingSpeed = max_speed;

// Update the universal command from bt
void updateUniversalCommand() {
  // Serial.print(ls);
  // Serial.print(" ");
  // Serial.print(rs);

  // Serial.println();

  universalCommand = command_check();
  if (universalCommand != universalCommandPrev) {
    universalCommandPrev = universalCommand;
    if (universalCommand != ' ') {
      Serial.print("Received command: ");
      Serial.print(universalCommand);

      Serial.println();
    }
  }

  switch (universalCommand) {
  case COMMAND_START_LISTEN:
    takeControl = true;
    if (takeControl != takeControlPrev) {
      takeControlPrev = takeControl;
      Serial.println("Changed control mode to manual");
    }
    break;
  case COMMAND_STOP_LISTEN:
    takeControl = false;
    if (takeControl != takeControlPrev) {
      takeControlPrev = takeControl;
      Serial.println("Changed control mode to auto route");
    }
    break;

    // Left
  case COMMAND_L_WHEEL_FORWARD:
    ls = maxControllingSpeed;
    break;
  case COMMAND_L_WHEEL_FORWARD_S:
    ls = 0;
    break;
  case COMMAND_L_WHEEL_BACKWARD:
    ls = -maxControllingSpeed;
    break;
  case COMMAND_L_WHEEL_BACKWARD_S:
    ls = 0;
    break;

    // Right
  case COMMAND_R_WHEEL_FORWARD:
    rs = maxControllingSpeed;
    break;
  case COMMAND_R_WHEEL_FORWARD_S:
    rs = 0;
    break;
  case COMMAND_R_WHEEL_BACKWARD:
    rs = -maxControllingSpeed;
    break;
  case COMMAND_R_WHEEL_BACKWARD_S:
    rs = 0;
    break;
  case COMMAND_BOARDLED_ON:
    digitalWrite(13, HIGH);
    break;
  case COMMAND_BOARDLED_OFF:
    digitalWrite(13, LOW);
    break;
  }
}
