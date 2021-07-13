int i;
void setup() {
  Serial.begin(9600);

  Serial.print("(1)");
  for(i=0; i<5; i++){
     Serial.print(i); Serial.print("\t");
  }
  Serial.println();
  
  i=0;
  Serial.print("(2)");
  while(i<5){
    Serial.print(i);  Serial.print("\t");
    i++;
  }
  Serial.println();

  i=0;
  Serial.print("(3)");
  do{
    Serial.print(i);  Serial.print("\t");
    i++;
  }while(i<5);
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:

}
