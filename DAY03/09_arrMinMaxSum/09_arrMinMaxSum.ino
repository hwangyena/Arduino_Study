void setup() {
  Serial.begin(9600);
}

void loop() {
  int arr[5], min_num, max_num, sum;
  Serial.print("정수 다섯 개 입력: ");
  
  for(int i=0; i<5; i++){
      while(!Serial.available());
      
      arr[i] = Serial.parseInt();
      Serial.println(arr[i]);
  }

  min_num = max_num = sum = arr[0];
  for(int i=1; i<5; i++){
    if(min_num>arr[i]) min_num=arr[i];
    if(max_num<arr[i]) max_num=arr[i];
    sum += arr[i];
  }
  Serial.print("최댓값 : "); Serial.println(max_num);
  Serial.print("최솟값 : "); Serial.println(min_num);
  Serial.print("총 합 : "); Serial.println(sum);
}
