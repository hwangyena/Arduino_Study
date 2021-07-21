#define bitMSB  MSBFIRST
#define bitLSB  LSBFIRST

int CLK = 6;
int LATCH = 5;
int DATA = 4;

void setup(){
  pinMode(CLK,OUTPUT);
  pinMode(LATCH,OUTPUT);
  pinMode(DATA,OUTPUT); 
}

void shift(int state){
  digitalWrite(LATCH,LOW);
  shiftOut(DATA,CLK,bitMSB,state); //왼쪽
  /*shiftOut(DATA,CLK,bitLSB,state); //오른쪽 */
  digitalWrite(LATCH,HIGH);
}

void loop(){
  shift(0b11000000);
  delay(1000);
  shift(0b00110000);
  delay(1000);
}
