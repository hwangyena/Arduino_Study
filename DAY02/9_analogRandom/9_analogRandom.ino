int RED = 11;
int GREEN = 10;
int BLUE = 9;

void setup(){
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
  randomSeed(analogRead(0)); 
}

void loop(){
  analogWrite(RED, random(256));
  analogWrite(GREEN, random(256));
  analogWrite(BLUE, random(256)); 
  delay(1000);
} 
