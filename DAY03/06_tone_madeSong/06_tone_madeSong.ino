#include "pitches.h"

int buzzer = 8;
int melody[]={NOTE_C4,NOTE_E4,NOTE_G4,
              NOTE_C4,NOTE_E4,NOTE_G4,
              NOTE_A4,NOTE_A4,NOTE_A4,NOTE_G4,
              NOTE_F4,NOTE_F4,NOTE_F4,
              NOTE_E4,NOTE_E4,NOTE_E4,
              NOTE_D4,NOTE_D4,NOTE_D4,NOTE_C4};
int d[] = {4,4,4,4,4,4,4,4,4,1,4,4,4,4,4,4,4,4,4,1};

void setup(){ 
  for(int i=0; i<20; i++){
    int dura = 1000/d[i];
    tone(buzzer, melody[i], dura);
    delay(dura*1.3);
    noTone(buzzer);
  }
}
void loop(){
}
