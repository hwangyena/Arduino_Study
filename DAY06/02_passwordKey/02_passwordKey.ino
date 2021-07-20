#include <Keypad.h>

int LED = 12;
int buzzer = 13;
int count = 0;
int flag = 0; //비밀번호 누르기 시작 판단 변수

const byte ROWS = 4; 
const byte COLS = 4; 

char password[4] = {
  '4','8','7','5'
};
char user_press[4] = {};

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rPins[ROWS] = {5,4,3,2}; 
byte cPins[COLS] = {8,9,10,11};

Keypad key = Keypad(makeKeymap(hexaKeys), rPins, cPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(buzzer,OUTPUT);
}

void password_check(){
  if(count<4) return; //아직 비밀번호 입력 다 안됨
  int is_correct = 1;
  
  for(int i=0; i<4; i++){
    if(user_press[i] != password[i]){
      is_correct = 0;
      break;    
    }
  }

  //출입허가
  if(is_correct){
    tone(buzzer,523,50);
    delay(100);
    tone(buzzer,392,50);
    delay(100);
    tone(buzzer,330,50);
    delay(100);
    noTone(buzzer);
  }
  //출입불가
  else{
    tone(buzzer,523,200);
    delay(300);
    tone(buzzer,523,200);
    delay(300);
    tone(buzzer,523,200);
    delay(300);
    noTone(buzzer);
  }

  //초기화
  digitalWrite(LED, LOW);
  flag = 0;
  count = 0;
}


void loop(){
  char customKey = key.getKey();

  if (customKey){
    if(!flag){
        flag = 1;
        digitalWrite(LED, HIGH);
      }
      user_press[count++] = customKey;
      Serial.println(customKey);
      tone(buzzer, 392, 50);  //비밀번호 누르면 소리남
      delay(100);
      noTone(buzzer);
  }
  password_check();
}
