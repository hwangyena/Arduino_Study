#include <MsTimer2.h>
int RED = 11;
int GREEN = 10;
int count = 200;
void setup() {
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  MsTimer2::set(10,Command);  //10msec
  MsTimer2::start();
}
void Command(){
  if(!count) count = 200;
  count -= 1;
}

void loop() {
  if(count >= 100){
    digitalWrite(RED,HIGH);
    digitalWrite(GREEN,LOW);
  }
  else{
    digitalWrite(RED,LOW);
    digitalWrite(GREEN,HIGH);
  }
}
