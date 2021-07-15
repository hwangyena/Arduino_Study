int RED = 11;
int GREEN = 10;
int BUTTON = 2;
long oldTime = 0;

void setup(){
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BUTTON,INPUT_PULLUP);
  attachInterrupt(INT0,event,LOW);
}
void event(){
  digitalWrite(GREEN,HIGH);
  oldTime = millis();
}

void loop(){
  digitalWrite(RED,HIGH);
  delay(500);
  digitalWrite(RED,LOW);
  delay(500);
  if(millis()-oldTime>1000)
    digitalWrite(GREEN,LOW);
}  
