/*
[색깔, 점등시간]을 입력으로 받아 LED가 지정한 시간만큼만 작동
*/

int RED = 12;
int GREEN = 11;
int BLUE = 10;

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  if(Serial.available()){
    String color = Serial.readStringUntil(',');
    int delay_time = Serial.parseInt();

    Serial.print("color: "); Serial.println(color);
    Serial.print("time: "); Serial.println(delay_time);

    if(color=="RED"){
      digitalWrite(RED, HIGH);
    }
    else if(color=="GREEN"){
      digitalWrite(GREEN, HIGH);
    }
    else if(color=="BLUE"){
      digitalWrite(BLUE, HIGH);
    }

    delay(delay_time);
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
  }
}
