#include <Wire.h>
#include <FaBoLCDmini_AQM0802A.h>
FaBoLCDmini_AQM0802A lcd;
 
int sensorPin = A0;
int sensorValue = 0; 
 
void setup() {
 // set up the LCD:
 lcd.begin();
 lcd.command(0x38);
 lcd.command(0x39);
 lcd.command(0x14);
 lcd.command(0x73);
 lcd.command(0x51);
 lcd.command(0x6c);
 lcd.command(0x38);
 lcd.command(0x01);
 lcd.command(0x0c);
 // Print a message to the LCD.
 lcd.print("hello!");
 delay(10000);
}
 
void loop() {
 lcd.clear();
 sensorValue = analogRead(sensorPin);
 lcd.print(sensorValue);
 lcd.setCursor(0,1);
 lcd.print(sensorValue/1024.0*5.0);
 lcd.print("V"); 
 delay(1000);
}
