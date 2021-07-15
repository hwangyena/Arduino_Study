int count = 6;
int ledPin[]={2,3,4,5,6,7};

void setup(){
  for(int i=0; i<count; i++){
    pinMode(ledPin[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop(){
  int sensorValue = analogRead(A0);
  int level = map(sensorValue, 0, 1023, 0, count);
 
  for(int i=0; i<count; i++){
    if(i<level){
      digitalWrite(ledPin[i],HIGH);
    }
    else{
      digitalWrite(ledPin[i],LOW);
    }
  }
  Serial.print(sensorValue);
  Serial.print('\t');
  Serial.println(level);
}
