int RED = 12;
int BLUE = 11;
int GREEN = 10;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  digitalWrite(RED,HIGH);
  delay(1000);
  digitalWrite(RED,LOW);
  delay(1000);
  
  digitalWrite(BLUE,HIGH);
  delay(1000);
  digitalWrite(BLUE,LOW);
  delay(1000);

  digitalWrite(GREEN,HIGH);
  delay(1000);
  digitalWrite(GREEN,LOW);
  delay(1000);
  
}
