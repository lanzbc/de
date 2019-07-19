#include<Servo.h>
#define IR_INPUT_PIN A1
#define IR_LED_PIN 12
#define led1 2
#define led2 3
Servo mServo;

void setup(){
 Serial.begin(9600); 
  mServo.attach(11);
 pinMode(IR_INPUT_PIN, INPUT);
 pinMode(IR_LED_PIN, OUTPUT);
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
}

void loop(){
  int ambient = 0;
  int lit = 0;
  int value = 0;
  
  digitalWrite(IR_LED_PIN, LOW);
  delay(50);                            //To give ADC and LED transition time
  ambient = analogRead(IR_INPUT_PIN);
  digitalWrite(IR_LED_PIN, HIGH);
  delay(50);
  lit = analogRead(IR_INPUT_PIN);  
  value = ambient - lit;     
  Serial.println(value);
  if(value>10){
    digitalWrite(led1, HIGH);
  }else digitalWrite(led1, LOW);
  if(value>100){
    digitalWrite(led2, HIGH);
  }else digitalWrite(led2, LOW);
}
