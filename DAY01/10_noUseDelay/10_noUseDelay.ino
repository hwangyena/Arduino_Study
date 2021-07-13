/*
millis() 함수를 사용해 delay없이 지연하기
*/

unsigned long prevMillis = 0;
unsigned long interval = 1000;

int RED = 12;
int flag = 0;

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
}

void loop() {
  unsigned long currMillis = millis();
  Serial.print("curr: "); Serial.println(currMillis);
  
  if(Serial.available()>0){
    interval = Serial.parseInt();
  }

  if(currMillis - prevMillis > interval){
    prevMillis = currMillis;

    if(flag==0) flag = 1;
    else flag = 0;

    digitalWrite(RED, flag);
  }
}
