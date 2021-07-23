
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "pitches.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define MAX_PERSON 3;

/*melody*/
int melody[]={
  NOTE_C4, NOTE_E4, NOTE_G4
};

/*LED*/
#define BLUE 9
#define GREEN 10
#define RED 11

/*sensor*/
int PIR = 3; //사람 감지 센서
int BUTTON = 2; //사람 수 초기화 버튼
int buzzer = 8; 

/*variable*/
//사람 감지
int state = 0; 
int sensor = 0;

//버튼 확인
int flag = 0;

int person_num = MAX_PERSON; //수용가능 인원 

    
/*버튼 눌리면 인원수 초기화*/
int Btn_check(){
  int key = !digitalRead(BUTTON);  
  if(key == 0)  {
    if(flag == 0) return 0;
    else{
      delay(20);
      flag = 0;
      return key;
    }
  }
  else{
    if(flag == 1 ) return 0;
    else{
      delay(50);
      flag = 1;
      return key;
    }
  }                                                               
}

/*사람초과 경보음*/
void sound_play(){
  for(int i=0; i<3; i++){
    tone(buzzer, melody[i], 200);
    delay(500);
    noTone(8);
  }
}

/*인원수보다 적으면 초록색, 초과시 빨간색 -> 경보 울림*/
void LED_check(){
  if(person_num>0){
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, LOW);  
  }
  else{
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);

    sound_play();
  }
}

void LCD_check(){
  if(person_num>0){
    lcd.setCursor(0,0);
    lcd.print("  < hello ! >   ");
    lcd.setCursor(0,1);
    lcd.print("acceptable: ");
    lcd.print(person_num);
  }
  else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("    [ERROR]   ");
    lcd.setCursor(0,1);
    lcd.print("limitation over!");
  }
  
}

void setup(){
  pinMode(PIR,INPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  
  lcd.begin();
  lcd.backlight();
  lcd.print("Hello, world!");
  
  Serial.begin(9600);
}



void loop(){
  
  delay(100);
 
  sensor = digitalRead(PIR);
  LED_check(); //사람수 확인
  LCD_check(); //lcd 출력

  if(Btn_check() == 1){
    Serial.println("버튼 눌림!");
    person_num = MAX_PERSON;  ////////////////사람수 초기화
    lcd.clear();
  }
  
  if(sensor == HIGH){
    if(state==0){//사람 들어온 경우
      state = 1;
      Serial.println("사람 들어옴");
    }
  }
  else{
    if(state==1){//나간 경우
      state = 0;
      Serial.println("사람 나감");
      person_num -= 1; //들어와서 나갔을 때, 사람 수 --
      
      Serial.print("남은 수용 인원: "); Serial.println(person_num);
    }
  }
}
