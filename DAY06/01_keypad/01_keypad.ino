#include <Keypad.h>

int LED = 12;

const byte ROWS = 4; 
const byte COLS = 4; 

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
}

void led_blink(int i){
  digitalWrite(i, HIGH);
  delay(100);
  digitalWrite(i, LOW);
  delay(100);
}
void loop(){
  char customKey = key.getKey();
  
  if (customKey){
    led_blink(LED);
    Serial.println(customKey);
  }
}
