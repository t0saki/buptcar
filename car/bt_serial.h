#include <SoftwareSerial.h> 
SoftwareSerial MyBlue(19,18); // RX, TX

void bt_init() {
    MyBlue.begin(9600);
}