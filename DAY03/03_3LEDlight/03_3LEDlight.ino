int count = 6;
int ledPin[]={3,5,6,9,10,11};
int digit = 0;

void setup(){
  for(int i=0; i<count; i++){
    pinMode(ledPin[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop(){
  int sensorValue = analogRead(A0);
  int PWM = map(sensorValue,0,1023,0,255);
  if(Serial.available()){
    digit = Serial.parseInt();
  }

  for(int i=0; i<count; i++){
    if(i<digit){
      analogWrite(ledPin[i],PWM);
    }
    else{
      analogWrite(ledPin[i],0);
    }
  }
  Serial.print(PWM);
  Serial.print('\t');
  Serial.println(digit);
  
}
