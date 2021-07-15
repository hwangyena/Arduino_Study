int notes[]={262,294,330,349,392,440,494,523}; 

void setup(){
  for(int i=0;i<8;i++){
    tone(8,notes[i],250); 
    delay(500);
    noTone(10);
  }
}

void loop(){
}
