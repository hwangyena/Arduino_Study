int L1 = 9;
int L2 = 10;
int L3 = 11;

void setup(){
  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(L3,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  
  if(Serial.available()>0){
    char ser = Serial.read();
    if(ser =='1'){
      digitalWrite(L1, HIGH);    
      digitalWrite(L2, LOW);    
      digitalWrite(L3, LOW);    
    }
    else if(ser == '2'){
      digitalWrite(L1, LOW);    
      digitalWrite(L2, HIGH);    
      digitalWrite(L3, LOW);    
    }
    else if(ser == '3'){
      digitalWrite(L1, LOW);    
      digitalWrite(L2, LOW);    
      digitalWrite(L3, HIGH);    
    }
  }
}
