#include "pitches.h"
int notes[]={NOTE_C4, NOTE_D4, NOTE_E4, 
              NOTE_F4, NOTE_G4,NOTE_A4,
              NOTE_B4,NOTE_C5}; 

void setup() {
  for(int i=0; i<8; i++){
    tone(8, notes[i], 250);
    delay(500);
    noTone(8);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
