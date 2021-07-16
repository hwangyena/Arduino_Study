#define Smin  0
#define Smax  1023

void setup(){
  Serial.begin(9600);
}

void loop(){
  int sensorValue = analogRead(A0);
  int range = map(sensorValue, Smin, Smax, 0, 3);

  Serial.print(sensorValue);
  Serial.print('\t');
  
  Serial.print(range);
  Serial.print('\t');
 
 
  switch(range){
    case 0:
      Serial.println("어둡다");
      break;
      
    case 1:
      Serial.println("조금밝다");  
      break;

    case 2:
      Serial.println("밝다");  
      break;

    case 3:
      Serial.println("아주밝다");  
      break;
  }
}
