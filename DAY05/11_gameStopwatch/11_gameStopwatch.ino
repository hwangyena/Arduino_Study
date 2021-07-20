#include <HuemonelabKit.h>
#include "pitches.h"

/*joyStick 값 확인, 20:마진*/
#define RIGHT 512+20
#define LEFT 512-20

int SWITCH =  2;
int BEEP = 7;
int RED = 6;
int GREEN = 5;
int BLUE = 3;

int angle = 0;
int Start = 0;
Stepper stepper(11,10,9,8); //회전센서

int melody1[]={NOTE_C5,NOTE_C5,NOTE_C5,NOTE_C5};
int melody2[]={
              NOTE_E4,NOTE_E4,NOTE_FS4,NOTE_E4,
              NOTE_CS5,NOTE_CS5,NOTE_CS5,
              NOTE_CS5,NOTE_CS5,NOTE_CS5,NOTE_CS5,
              NOTE_CS5,NOTE_FS4,NOTE_FS4,NOTE_FS4,
              
              NOTE_CS5,NOTE_CS5,NOTE_CS5,NOTE_CS5,
              NOTE_B4,NOTE_B4,NOTE_B4,NOTE_CS5,
              NOTE_B4,NOTE_E4,NOTE_E4,NOTE_B4
              };
                           
int d[] ={12,8,4,4,1,16,8,8,8,8,8,8,4,8,1,
          8,4,4,8,1,8,8,8,8,8,8,1
          };    
          
void setup(){
  pinMode(SWITCH,INPUT_PULLUP);  
  pinMode(BEEP,OUTPUT);
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
  Serial.begin(9600);
  colorLED(0,0);
}

void melody(int buzzer){
  if(buzzer==1){ //시작
    for(int i=0; i<4; i++){
      tone(BEEP,melody1[i],100);
      delay(250);
      noTone(BEEP);
    }
  }
  else if(buzzer==2){ //종료
    for(int i=0; i<27; i++){
      int del = 1000 / d[i];
      tone(BEEP,melody2[i],del);
      delay(del*1.2);
      noTone(BEEP);
    }
  }
  buzzer = 0;
}

/*CDS 선택시, 5회전*/
void CDS(){
  int val = analogRead(A0);
  if(val<=500) Start = 1;
  else Start = 0;

}

void colorLED(int c, int pwm){
  digitalWrite(RED,LOW);
  digitalWrite(GREEN,LOW);
  digitalWrite(BLUE,LOW);
 
  if(c==0){
    digitalWrite(BLUE,HIGH);
  }
  else if(c==1){
    analogWrite(GREEN,255-pwm);
  }
  else if(c==2){
    digitalWrite(RED,HIGH);
  }
}
void joyStick(){
  int x = analogRead(A0);
  int y = analogRead(A1);
  int s = digitalRead(SWITCH);

  
  if(x>RIGHT)angle = 1;
  else if(x<LEFT) angle = -1;    
  else angle = 0;
  //Serial.println(x);
}

void loop() {
  CDS();
  //CDS 측정 됨 -> timer 시작 
  if(Start==1){
    stepper.setSpeed(1);
    melody(1);
    colorLED(1,0);
    
    for(int i=1; i<=5; i++){    
      Serial.print(i*5);
      Serial.print("초 경과");
      for(int j=0; j<i;j++){
        Serial.print("♣");
      }
      Serial.println();
      stepper.setTimer(5);
      colorLED(1,50*i);
    }
    
    //종료음 및 빨간색 -> 파란색 LED 변경
    colorLED(2,0);
    melody(2);
    colorLED(0,0); 
  }  
  else{
    joyStick();
    stepper.setSpeed(10);
    stepper.move(angle);
  }
}
