/*
void setup() {
  // put your setup code here, to run once:
  //1회만 실행, 속성 정의
}

void loop() {
  // put your main code here, to run repeatedly:
  //무한 반복, 전원이 공급되는 한 계속 실행할 내용
}
*/
void setup() {
  Serial.begin(9600);
}

void loop(){
  int a=0, b=0;
  a++; ++b;
  int a_r = a++;
  int b_r = ++b;

  Serial.print("n1="); Serial.print(a); Serial.print("\t");
  Serial.print("n2="); Serial.print(b); Serial.print("\t");
  Serial.print("n1_result="); Serial.print(a_r); Serial.print("\t");
  Serial.print("n2_result="); Serial.print(b_r); Serial.print("\t");
  
  while(1);
}
