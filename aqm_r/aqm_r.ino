#include <Wire.h>
#define LCD_ADRS 0x3E
char character[]= "XINCHAOCACBAN456";

void setup(){
 Wire.begin();
 init_LCD();
}

void loop(){
  for(int i=0;i<16; i++){
    writeData(character[i]);
  }
  writeCommand(0x40+0x80);
  for(int i=0; i<16;i++){
    writeData(i+0xb1);
  }

  while(1){  }
}

void writeData(byte t_data) {
  Wire.beginTransmission(LCD_ADRS);
  Wire.write(0x40);
  Wire.write(t_data);
  Wire.endTransmission();
  delay(1);
}

void writeCommand(byte t_command)
{
  Wire.beginTransmission(LCD_ADRS);
  Wire.write(0x00);
  Wire.write(t_command);
  Wire.endTransmission();
  delay(100);
}

void init_LCD(){
  delay (100);
  writeCommand(0x38);
  delay (20);
  writeCommand(0x39);
  delay (20);
  writeCommand(0x14);
  delay (20);
  writeCommand(0x73);
  delay (20);
  writeCommand(0x56);
  delay (20);
  writeCommand(0x6C);
  delay (20);
  writeCommand(0x38);
  delay (20);
  writeCommand(0x01);
  delay (20);
  writeCommand(0x0C);
  delay (20); 
}
