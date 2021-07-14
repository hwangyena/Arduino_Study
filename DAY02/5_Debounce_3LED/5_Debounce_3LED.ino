int RED = 13; int GREEN = 12; int BLUE = 11;
int BUTTON = 2;
int count = 0; //버튼 눌려져있는지 확인
int flag= 0;

int SW_chk(){
  int key = !digitalRead(BUTTON);
  if(key==0){ //버튼 안눌림 상태
    if(flag==0) return 0; //기존 버튼 안눌림 상태 -> 변화 X
    else{ //기존 버튼 눌림 상태 -> 안눌림(0)으로 변환(flag) 후, key(=0) return
      delay(20);
      flag = 0;
      return key;
    }
  }
  else{ //버튼 눌림 상태
    if(flag==1) return 0; //기존 눌린 상태 -> 변화 X
    else{ //기존 안눌린 상태 -> 눌림(1) 변환(flag) 후, key(=1) return
      delay(50);
      flag = 1;
      return key;
    }
  }
}
void setup() {
  pinMode(RED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  if(SW_chk()==1){
    count++;
    if(count>3){
      count=0;
    }
  }

  if(count==0){
    digitalWrite(RED,LOW);
    digitalWrite(GREEN,LOW);
    digitalWrite(BLUE,LOW);
  }
  else if(count==1) 
    digitalWrite(RED,HIGH);
  else if(count==2)
    digitalWrite(GREEN,HIGH);
  else if(count==3)
    digitalWrite(BLUE,HIGH);
}
