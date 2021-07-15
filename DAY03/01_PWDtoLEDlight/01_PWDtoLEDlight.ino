int LED = 11;
void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  float PWM = sensorValue*(255.0/1023.0);
  float voltage = PWM*(5.0/255.);

  analogWrite(LED, PWM);

  Serial.print(sensorValue); Serial.print("\t");
  Serial.print(PWM); Serial.print("\t");
  Serial.print(voltage); Serial.print("\n");
}
