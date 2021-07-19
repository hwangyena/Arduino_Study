/*
소리사운드 센서가 500이상이면 소음으로 인지하고
5초간 500이하로 유지되면 소음 없음으로 간주

소리가 나면 5초아후에 조용하다고 나옴! 즉, 소리가 한번이라도 나야 조용하다는 걸 판별할 수 있음
*/

int analogPin = A0; 
int analogVal; 
long lastSound = 0;
boolean alarm = false;

void setup(){
  Serial.begin(9600);
}

void loop(){
  analogVal = analogRead(analogPin); 
  //Serial.println(analogVal);
  if(analogVal>100){//100: 내 주변 소음의 값으로 설정!
    lastSound = millis();
    
    if(alarm == false){
      Serial.println("소리난다");
      alarm = true;
    }
  }   
  else{
    if(alarm == true){
        if((millis()-lastSound) > 5000){    
          Serial.println("조용하다");
          alarm = false;
        }
    }
  }
}
