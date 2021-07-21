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
  shiftOut(DATA,CLK,bitMSB,state);
  digitalWrite(LATCH,HIGH);
}

void loop(){
  for(int i=0; i<8; i++){
    shift(0b10101010);
    delay(100);
    shift(0b01010101);
    delay(100);
    shift(0);
    delay(100);
  }
  
  int ledL = 0b00000001;
  for(int i=0; i<8;i++){
    shift(ledL<<i);
    delay(100);
  }
  
  int ledR = 0b10000000;
  for(int i=0; i<8;i++){
    shift(ledR>>i);
    delay(100);
  }
}
