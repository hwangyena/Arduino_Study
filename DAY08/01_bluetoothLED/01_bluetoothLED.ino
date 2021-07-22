#include <SoftwareSerial.h>

int blueTX = 2;   
int blueRX = 3;
int led = 11;
char ser = 0;
char ble = 0;

SoftwareSerial HC06(blueTX, blueRX);

void setup(){
   Serial.begin(9600);
   HC06.begin(9600);
}

void loop(){
  if(Serial.available()>0){
    ser = Serial.read();
    HC06.write(ser);
  }
    
  if(HC06.available()>0){
    ble = HC06.read();
    Serial.write(ble);
  }

  if(ble=='1'){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }
}
  
