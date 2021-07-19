int SW = 7; 

void setup(){
 Serial.begin(9600); 
 pinMode(SW, INPUT_PULLUP); 
}

void loop(){
  int x = analogRead(A0);
  int y = analogRead(A1);
  int s = digitalRead(SW);
  
  Serial.print("X축: ");
  Serial.print(x); 
  Serial.print('\t');  
  Serial.print("Y축: ");        
  Serial.print(y); 
  Serial.print('\t');         
  Serial.print("스위치: ");
  Serial.println(s);
  delay(100);       
}
