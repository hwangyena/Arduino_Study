int maxFunction(int a, int b, int c);
int minFunction(int a, int b, int c);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("세 개의 정수 입력 : ");
  while(!Serial.available());
  int a = Serial.parseInt();
  int b = Serial.parseInt();
  int c = Serial.parseInt();
  int max = maxFunction(a,b,c);
  int min = minFunction(a,b,c);

  Serial.print(a); Serial.print(",");
  Serial.print(b); Serial.print(",");
  Serial.print(c); Serial.println();
      
  Serial.print("가장 큰 수 :");
  Serial.print(max); Serial.println();
  Serial.print("가장 작은 수 :");
  Serial.print(min); Serial.println();
  
}

int maxFunction(int a, int b, int c){
  if(a>b && a>c) return a;
  else if (b>a && b>c) return b;
  else return c;
}

int minFunction(int a, int b, int c){
  if(a<b && a<c) return a;
  else if (b<a && b<c) return b;
  else return c;
}
