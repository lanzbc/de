#include<Servo.h>
int trig = 13;    
int echo = 12;
int servoPin = 10;
int value = 0;
Servo servo;

void setup(){
 Serial.begin(9600); 
 servo.attach(servoPin);
 pinMode(trig, OUTPUT);  
 pinMode(echo, INPUT); 
}

void loop(){    
    Serial.print(distance());
    Serial.println("cm");
    delay(200);
  
  while(distance()<20)
  {
    Open();
    while(distance()<20);
    delay(5000);
  } 
  
 }    
int distance(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig,LOW);
  int timer = pulseIn(echo, HIGH);
  return int(timer/58.3); 
}
void Close()
{
  for(int i=120;i>0;i--)
    {
      servo.write(i);
      delay(20);
    }
}
void Close_cpl()
{
  servo.write(0);
}
void Open()
{
  servo.write(120);
}
