int RED_LED = 11;
int GREEN_LED = 10;
int BLUE_LED = 9;

void setup(){
  pinMode(RED_LED,OUTPUT);
  pinMode(GREEN_LED,OUTPUT);
  pinMode(BLUE_LED,OUTPUT);
}

void loop(){
  analogWrite(RED_LED,255);
  analogWrite(GREEN_LED,0);
  analogWrite(BLUE_LED,0);
  delay(1000);
  analogWrite(RED_LED,0);
  analogWrite(GREEN_LED,255);
  analogWrite(BLUE_LED,0);
  delay(1000);
  analogWrite(RED_LED,0);
  analogWrite(GREEN_LED,0);
  analogWrite(BLUE_LED,255);
  delay(1000);
}
