/*
 * 지진 경보
2초 이상 기울여져 있으면 (흔들리거나 앞쪽으로 기울리면) 랜덤한 빛이 들어온다
*/

#define LED_R  9
#define LED_G  10
#define LED_B  11
#define tilt  2

int LEDstate = LOW; 
int previous = LOW; 
int reading = 0; 
long time = 0; 
long debounce = 2000;
int digit = 0;

void setup(){
  pinMode(tilt, INPUT_PULLUP);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600); 
//  digit = random(9,12); /*랜덤하게 RGB 정하기*/
  Serial.println(digit);
}
void loop(){
  /*사용자에게 입력받기*/
  if(Serial.available()>0){
    char color = Serial.read();
    digitalWrite(LED_R,LOW);
    digitalWrite(LED_G,LOW);
    digitalWrite(LED_B,LOW);
    if(color == 'R') digit = LED_R;
    else if(color == 'G') digit = LED_G;
    else digit = LED_B;
  }
  reading = digitalRead(tilt);

  if (reading != previous){
    time = millis();
  }

  if (((millis() - time) > debounce)){
    if(reading == HIGH)    
      LEDstate = HIGH;
    else
      LEDstate = LOW;
  }
  
  digitalWrite(digit, LEDstate);
  previous = reading;
}
