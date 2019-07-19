#include <Wire.h>
#include <FaBoLCDmini_AQM0802A.h>
#include "Adafruit_MCP9808.h"
FaBoLCDmini_AQM0802A lcd;
Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();
 
int sensorPin = A0;
int sensorValue = 0; 
 
void setup() {
 Serial.begin(9600);
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
 lcd.print("  Hello World!");  
 lcd.setCursor(0, 1);
 lcd.print("Diamond Electric");
 delay (5000);
 lcd.clear();
 if (!tempsensor.begin(0x18)) {
    Serial.println("khong tim thay thiet bi");
    while (1);
  }
    
   Serial.println("da ket noi voi MCP9808");

  tempsensor.setResolution(3);
}
 
void loop() {
  tempsensor.wake();
  Serial.print("Resolution in mode: ");
  Serial.println (tempsensor.getResolution());
  float c = tempsensor.readTempC();
  float f = tempsensor.readTempF();
  Serial.print("Temp: "); 
  Serial.print(c, 4); Serial.print("*C\t and ");
  Serial.print(f, 4); Serial.println("*F.");
  lcd.setCursor(0,0);
  lcd.print(c,4);
  lcd.print("*C");
  lcd.setCursor(0,1);
  lcd.print(f,4);
  lcd.print("*F");
  delay(1000);
  tempsensor.shutdown_wake(1); // shutdown MSP9808
}
