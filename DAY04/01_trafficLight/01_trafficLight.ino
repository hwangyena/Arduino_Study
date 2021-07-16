int GREEN = 9;
int YELLOW = 10;
int RED = 11;
int RGB_R = 4;
int RGB_G = 5;
int RGB_B = 6;
int BUTTON = 2;
int BEEP = 12;

int flag = 0;
int wait = 0;
int mode = 0;

void setup(){ 
  pinMode(GREEN,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  pinMode(RED,OUTPUT);
  pinMode(RGB_R,OUTPUT);
  pinMode(RGB_G,OUTPUT);
  pinMode(RGB_B,OUTPUT);
  pinMode(BEEP,OUTPUT); 
  pinMode(BUTTON,INPUT_PULLUP);
  Serial.begin(9600);      
  attachInterrupt(INT0,event,CHANGE);
}

//RGB color() 만들기
void color(int g, int y, int r, int rgb_r, int rbg_g){
  //운전자
  if(g==1)  digitalWrite(GREEN, HIGH);
  else digitalWrite(GREEN, LOW);
  if(y==1)  digitalWrite(YELLOW, HIGH);
  else digitalWrite(YELLOW, LOW);
  if(r==1)  digitalWrite(RED, HIGH);
  else digitalWrite(RED, LOW);

  //보행자
  if(rgb_r==1)  digitalWrite(RGB_R, HIGH);
  else digitalWrite(RGB_R, LOW);
  if(rbg_g==1)  digitalWrite(RGB_G, HIGH);
  else digitalWrite(RGB_G, LOW);
}

void event(){
  flag = 1;
  mode = 3;
  digitalWrite(BEEP,HIGH);
  delay(300);
  digitalWrite(BEEP,LOW);
}

void waiting(){
  for(int i=0; i<wait; i++){
    if(flag){
      flag = 0;
      return;
    }
    delay(1);
  }
}
void loop(){ 

  switch(mode){
    case 1: 
        color(1,0,0,1,0);
        wait = 2000;
        break;
        
    case 2:
        color(0,1,0,1,0);
        wait = 1000;
        break;
               
    case 3:
        color(0,0,1,0,1);
        wait = 2000;
        break;

    default :
        wait = 0;
        mode = 0;  
  }
  mode++;
  waiting();
}
