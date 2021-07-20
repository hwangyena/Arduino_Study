#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int count = 0;
int old_vol = 0;

void setup(){
  lcd.begin();
  lcd.backlight();
  lcd.print("volume!!!");
  Serial.begin(9600);
}

void loop(){
  int value = analogRead(A0);
  int volume = map(value,0,1023,0,16);
  Serial.println(volume);
  if(volume != old_vol){
    lcd.setCursor(0,1);
    for(int i=0; i<=volume; i++){
     lcd.write(0xFF);
    }
    for(int i=volume; i<16; i++){
     lcd.write(' ');
    }
  }
  old_vol=volume;
}
