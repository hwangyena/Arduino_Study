void setup() {
  Serial.begin(9600);
}

void loop() {
  /*
  int n, total=0;
  Serial.print("num은? ");
  
  while(!Serial.available()); //데이터가 입력될 때까지 기다린다
  n = Serial.parseInt();
  Serial.println(n);
  for(int i=0; i<n; i++){
    total += i;
  }
    
  Serial.print("덧셈 결과: ");
  Serial.print(total);
  */
  for(int i=0;i<5; i++){
    for(int j=0; j<=i; j++){
      Serial.print('$');
    }Serial.println();
  }

  for(char i='F'; i>='A'; i--){
    for(char j='F'; j>=i; j--){
      Serial.print(j);
    }Serial.println();
  }


  for(;;);
}
