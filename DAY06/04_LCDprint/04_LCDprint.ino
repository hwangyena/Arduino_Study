#include <LiquidCrystal.h>   
 
const int rs = 6, en = 7, d4 = 9, d5 = 10, d6 = 11, d7 = 12;         
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 

void setup(){
  lcd.begin(16,2);                  
  Serial.begin(9600); 
  lcd.setCursor(0,0);
  lcd.write("name:yena");
}

void loop(){
  if(Serial.available()){    
    //두번째 줄에 있는 내용을 전부 지워줌
    lcd.setCursor(0,1);                     
    lcd.print("                ");     

    //두번째줄에 내용 써주기
    lcd.setCursor(0,1);                     
    lcd.print(Serial.readStringUntil('\n'));  
  }
}
