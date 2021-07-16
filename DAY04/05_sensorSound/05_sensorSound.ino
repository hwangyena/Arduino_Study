void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  int frequency = map(sensorValue, 400, 800, 31, 1500);

  tone(5, frequency, 100);
  delay(100);
  noTone(5);

  Serial.print("tone : ");
  Serial.print(sensorValue);
  Serial.println("[Hz]");
}
