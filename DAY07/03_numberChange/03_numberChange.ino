int seg[]={2,3,4,5,6,7,8,9}; //D2(a)

byte digits[10][8]={   
  { 1,1,1,1,1,1,0,0 }, // 0
  { 0,1,1,0,0,0,0,0 }, // 1
  { 1,1,0,1,1,0,1,0 }, // 2
  { 1,1,1,1,0,0,1,0 }, // 3
  { 0,1,1,0,0,1,1,0 }, // 4
  { 1,0,1,1,0,1,1,0 }, // 5
  { 1,0,1,1,1,1,1,0 }, // 6
  { 1,1,1,0,0,0,0,0 }, // 7
  { 1,1,1,1,1,1,1,0 }, // 8
  { 1,1,1,0,0,1,1,0 }, // 9
};

void display(int number){
  for(int i=0;i<8;i++){
    digitalWrite(seg[i],digits[number][i]);
  }  
}

void setup(){
 for (int i = 0; i < 8; i++){ 
  pinMode(seg[i], OUTPUT);
 }
}

void loop(){
  int val = analogRead(A0);
  int level = map(val,0,1023,0,9);
  display(level);
}
