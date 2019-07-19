#include <Wire.h>;
#include <LiquidCrystal_I2C.h>;
LiquidCrystal_I2C lcd(0x27,16,2);//0x27 là địa chỉ màn hình trong bus I2C, hang, cot
byte traitim[8]={
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
  B00000
};
void setup(){
lcd.init();       //Khởi động màn hình.
lcd.backlight();   //Bật đèn nền
}
void loop()
{
  lcd.setCursor(2,0);
  lcd.print("Hello World!");
  int i;
  for (i=0;i<=10;i++){
  lcd.setCursor(i,1);
  delay(200);  
  }
  delay(2000);
  lcd.clear();//Xóa màn hình
  delay(300);
}
