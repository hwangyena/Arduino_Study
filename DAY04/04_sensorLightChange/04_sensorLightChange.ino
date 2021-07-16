#define LED 11

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  int PWM = map(sensorValue, 0, 1023, 255, 0);

  if(sensorValue>600){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
  Serial.print(sensorValue);
  Serial.print("\t");
  Serial.println(PWM);
}
