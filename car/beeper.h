#pragma once
#include "pins.h"
#include "pitches.h" //載入音調和頻率的對照檔

// 旋律
int melody[] = { NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4 };

// 每個音的的拍子，4：4分音符，8：8分音符
int noteDurations[] = { 4, 8, 8, 4, 4, 4, 4, 4 };

void beep(float freq) { tone(BEEPER_PIN,freq); }

void beep(float freq,unsigned long duration) { tone(BEEPER_PIN,freq,duration); }

void sing() {
  for (int thisNote = 0; thisNote<8; thisNote++) {
    //計算每個音的長度，4分音符： 1000 / 4，8分音符：1000/8
    int noteDuration = 1000/noteDurations[thisNote];
    beep(melody[thisNote],noteDuration); // tone(PIN腳,音調,拍子)

    // 每個音之間要停一小段時間，範例是建議拍子的長度加30%
    int pauseBetweenNotes = noteDuration*1.30;
    delay(pauseBetweenNotes);
    noTone(BEEPER_PIN); // 停止播放
  }
}
void silent() {
  digitalWrite(BEEPER,LOW);
  noTone(BEEPER_PIN);
}

void pinout_init_beeper() {
  pinMode(BEEPER_PIN,OUTPUT);
  digitalWrite(BEEPER_PIN,LOW);
}