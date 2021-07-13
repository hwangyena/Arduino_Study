char a = 'A';
String b = "개발자";

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(a);
  Serial.print("급 ");
  Serial.print(b);
  Serial.print("입니다.");
  while(1);
}
