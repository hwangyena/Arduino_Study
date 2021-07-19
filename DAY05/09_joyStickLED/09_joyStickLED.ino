#define MIN 100
#define MAX 1000
#define REF 512
#define ON  1
#define OFF 0

int SW = 2; 
int UP = 9;
int DOWN = 10;
int LEFT = 11;
int RIGHT = 8;
int LED = 0;

void ledDisplay(int pin){
  //스위치 선택 -> LED 전체 조종
  if(pin<=1){
    for(int i=8;i<=11;i++){
      digitalWrite(i,pin);
    }
    return;
  }  
  digitalWrite(pin,HIGH);
}

void setup(){
 Serial.begin(9600); 
 pinMode(SW, INPUT_PULLUP); 
 for(int i=8;i<=11;i++){
   pinMode(i,OUTPUT);
 }
}

void loop(){
  int x = analogRead(A0);
  int y = analogRead(A1);
  int s = digitalRead(SW);
  Serial.print(x);
  Serial.print('\t');
  Serial.print(y);
  Serial.print('\t');
  Serial.println(s);

  //현재 조이스틱 값에 따라 LED 상태 확인
  if(x >= MAX) LED = RIGHT;
  else if(x <= MIN) LED = LEFT;
  else if(y >= MAX) LED = DOWN;
  else if(y <= MIN) LED = UP;
  else if(s == 0) LED = ON;
  else LED = OFF;

  ledDisplay(LED);
  delay(100);
}
