#define bitMSB  MSBFIRST
#define bitLSB  LSBFIRST

int CLK = 6;
int LATCH = 5;
int DATA = 4;

void setup(){
  pinMode(CLK,OUTPUT);
  pinMode(LATCH,OUTPUT);
  pinMode(DATA,OUTPUT); 
  Serial.begin(9600);
  shift(0);
}

void shift(int state){
  digitalWrite(LATCH,LOW);
  shiftOut(DATA,CLK,bitMSB,state);
  digitalWrite(LATCH,HIGH);
}

void loop(){
  if(Serial.available()>0){
    int data = Serial.parseInt();    
    shift(data);
  }
}
