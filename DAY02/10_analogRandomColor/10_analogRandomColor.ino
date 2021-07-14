int RED = 11;
int GREEN = 10;
int BLUE = 9;

void color(int r, int g, int b){
  analogWrite(RED,r);
  analogWrite(GREEN,g);
  analogWrite(BLUE,b);
  delay(1000);
}

void setup(){
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
  randomSeed(analogRead(0)); 
  Serial.begin(9600);
}

void loop() {
  int digit = random(1,8);
 
  switch(digit){
    case 1:
      color(255,0,0);
      break;
    case 2:
      color(0,255,0);
      break;
    case 3:
      color(0,0,255);
      break;
    case 4:
      color(255,255,0);
      break;
    case 5:
      color(255,0,255);
      break;
    case 6:
      color(0,255,255);
      break;
    case 7:
      color(255,255,255);
      break;
  }
  delay(1000);
}
