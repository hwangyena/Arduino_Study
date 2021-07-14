void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0/1023.0);
  Serial.print(sensorValue);
  Serial.print("\t");
  Serial.println(voltage);
}
