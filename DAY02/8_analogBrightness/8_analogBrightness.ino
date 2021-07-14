int RED = 11;
int GREEN = 10;
int BLUE = 9;

void setup(){
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
}

void loop(){
  for(int i=0; i<=255; i++){
    analogWrite(BLUE,i);
    delay(50); 
  }
  for(int i=255; i>=0; i--){
    analogWrite(BLUE,i);
    delay(50); 
  }
} 
