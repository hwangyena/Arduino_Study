void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){     //데이터 들어왔는지 확인
    char cmd = Serial.read();   //데이터 읽기
    Serial.println(cmd);
    
    if(cmd=='a'){
      //대문자로 변경
      Serial.println(cmd-32); 
      Serial.write(cmd-32); 
    }
  }
}
