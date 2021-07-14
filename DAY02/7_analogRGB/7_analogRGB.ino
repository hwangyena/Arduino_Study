int RED = 11;
int GREEN = 10;
int BLUE = 9;

//rgb 자리를 찾아서 analogWrite 순서대로
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
}

void loop(){
  color(255,0,0);
  color(0,255,0);
  color(0,0,255);
  color(255,255,0);
  color(255,0,255);
  color(0,255,255);
  color(255,255,255);
} 
