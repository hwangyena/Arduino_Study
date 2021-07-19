#include <HuemonelabKit.h>

Stepper stepper(11,10,9,8);

void setup() {
  stepper.setDir(1);
  Serial.begin(9600);
}

void loop() {
  int rotation= 0;
  
  if(Serial.available()>0){
    rotation = Serial.parseInt(); 
    Serial.println(rotation);
    for(int i=0; i<rotation; i++){
      stepper.setTimer(5);
    }
  } 
}
