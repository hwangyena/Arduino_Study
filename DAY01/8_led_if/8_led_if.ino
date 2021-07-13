int RED = 12;
int GREEN = 11;

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  if(Serial.available()>0){
    int a = Serial.parseInt();
    int b = Serial.parseInt();
    int result = a+b;
    Serial.print("a: "); Serial.print(a); Serial.println();
    Serial.print("b: "); Serial.print(b); Serial.println();
    Serial.print("result: "); Serial.print(result); Serial.println();
    
    if(result>=100){
      digitalWrite(RED,HIGH);
      digitalWrite(GREEN, LOW);
    }
    else if(result>=50 && result<100){
      digitalWrite(GREEN,HIGH);
      digitalWrite(RED, LOW);
    }
    else{
      digitalWrite(RED,LOW);
      digitalWrite(GREEN, LOW);
    }
  }
}
