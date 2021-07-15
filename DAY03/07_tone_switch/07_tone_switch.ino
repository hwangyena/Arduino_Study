int SW1 = 5;
int SW2 = 4;
int SW3 = 3;
int SW4 = 2;
int LED = 10;
int buzzer = 8;

int flag = 0;
int count = 0;

void setup() {
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

/*
0 반환 -> 기존 상태 유지
key 반환 -> 새롭게 누르거나 뗌
*/
int buttonStatus()                //4개의 버튼상태 읽는다
{
  int key   = ((!digitalRead(SW1))// 눌렸을때 0이되므로 상태를 1로 반전("!")
              |(!digitalRead(SW2)*2)
              |(!digitalRead(SW3)*3)
              |(!digitalRead(SW4)*4)
              );
  if(!key){//버튼 안누름
    if(flag==0) return 0 ; //이전에 안누름 -> 유지
    else{//이전에 누르고 있었음
      delay(20);
      flag = 0; //안누른 상태로 변경
      digitalWrite(LED,LOW); //LED 끄기
      return key;
    }
  }  
  else{//버튼 누름
    if(flag != 0)  return 0; //이전에 누름 -> 유지
    else{
      flag = 1; //누른 상태로 변경
      digitalWrite(LED,HIGH);    //키를 누를 때 마다 LED깜빡
      return key;
    }    
  }
}

void loop() {
  int button = buttonStatus(); //0: 변화X, key: 변화O

   if(button == 1) tone(buzzer, 262);
   else if(button == 2) tone(buzzer, 294);
   else if(button == 3) tone(buzzer, 330);
   else if(button == 4) tone(buzzer, 349);

   delay(100);
   noTone(buzzer);
}
