#include <Servo.h>

Servo myservo;  

int potpin = 0;  
int val;   

void setup() {
  myservo.attach(9); 
  Serial.begin(9600);
}

void loop() {
  val = analogRead(potpin);
  Serial.print(val);            
  val = map(val, 0, 1023, 0, 180);
  Serial.print('\t');            
  Serial.println(val);            
       
  myservo.write(val);                  
  delay(15);                           
}
