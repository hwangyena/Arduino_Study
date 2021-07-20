#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>   
 
const int rs = 6, en = 7, d4 = 9, d5 = 10, d6 = 11, d7 = 12;          
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);  

int DHTPIN = 2;
int DHTTYPE = DHT11;
int LED = 13;
     
DHT dhtSensor(DHTPIN, DHTTYPE);

void setup(){
  Serial.begin(9600);
  dhtSensor.begin();
  pinMode(LED,OUTPUT);
  lcd.begin(16, 2);                       
  lcd.clear();
}

void loop(){
  float t = dhtSensor.readTemperature();
  float h = dhtSensor.readHumidity();   
 
  if (isnan(h) || isnan(t)){
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  lcd.setCursor(0, 0);
  lcd.print("Tem:");
  lcd.print(t);
  lcd.write(223); 
  lcd.print('C'); 

  lcd.setCursor(0, 1);
  lcd.print("Hum:");
  lcd.print(h);
  lcd.print('%'); 

  Serial.print("Tem:");
  Serial.print(t);
  Serial.print(" ℃");
  Serial.print('\t');
  Serial.print("Hum:");
  Serial.print(h);
  Serial.println(" %");

  if(t >= 30.0) digitalWrite(LED,HIGH);
  else digitalWrite(LED,LOW);
}
