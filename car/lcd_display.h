#pragma once

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void lcd_init() {
    lcd.init();                      // initialize the lcd
    // Print a message to the LCD.
    lcd.backlight();
}


void set_string(int line,String str) {

    lcd.setCursor(1,line);
    lcd.print(str);
}