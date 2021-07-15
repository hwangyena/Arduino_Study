int RED = 11;
int GREEN = 10;
int BUTTON = 2;
int oldTime = 0;
int delayTime = 30;

void setup(){
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BUTTON,INPUT_PULLUP);
  attachInterrupt(INT0,event,FALLING);
  Serial.begin(9600);
}
void event(){
  if(millis()-oldTime>1000){
    oldTime = millis();
    delayTime = delayTime + 200;  
    if(delayTime>2000)delayTime = 30;
    Serial.println(delayTime);
  }
}

void loop(){
  digitalWrite(RED,HIGH);
  delay(delayTime);
  digitalWrite(RED,LOW);
  delay(delayTime);
}  
