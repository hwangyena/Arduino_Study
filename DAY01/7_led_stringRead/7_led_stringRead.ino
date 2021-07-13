int RED = 12;
int GREEN = 11;

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  if(Serial.available()>0){
    String color = Serial.readStringUntil("\n");
    Serial.print("color= "); Serial.println(color);
    
    if(color=="RED" || color=="red"){
      digitalWrite(RED, HIGH);
    }
    else if(color == "GREEN"){
      digitalWrite(GREEN, HIGH);
    }
    delay(1000);
    digitalWrite(RED, LOW); digitalWrite(GREEN, LOW);
  }
}
