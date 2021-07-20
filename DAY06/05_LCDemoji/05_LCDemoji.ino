#include <LiquidCrystal.h>

const int rs = 6, en = 7, d4 = 9, d5 = 10, d6 = 11, d7 = 12;         
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int setDelay = 0;

byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
};

byte smiley[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b10001,
  0b01110,
  0b00000
};

byte frownie[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b10001
};

byte armsDown[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

byte car[] = {
  B00000,
  B01110,
  B01110,
  B11111,
  B11111,
  B01010,
  B00000,
  B00000
};

void setup() {
  lcd.begin(16,2);
  lcd.createChar(0, heart);
  lcd.createChar(1, smiley);
  lcd.createChar(2, frownie);
  lcd.createChar(3, armsDown);
  lcd.createChar(4, armsUp);
  lcd.createChar(5, car);
  
  lcd.setCursor(0,0);
  lcd.write(byte(0));
  lcd.write(" yena ");
  lcd.write(byte(1));
  lcd.write(byte(0));

  lcd.setCursor(0, 12);
  lcd.write(byte(5));
 }

void loop() {
  if(Serial.available()>0){
    //0이 아닌경우에만 display
    int source = Serial.parseInt();
    if(source){
      setDelay = source; 
      Serial.println(setDelay);
    }
  }
  lcd.setCursor(5, 1);
  lcd.write(byte(3));
  delay(setDelay);
  lcd.setCursor(5, 1);
  lcd.write(byte(4));
  delay(setDelay);
}
