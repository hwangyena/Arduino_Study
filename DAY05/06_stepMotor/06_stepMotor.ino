#include <HuemonelabKit.h>

Stepper stepper(11,10,9,8); //연결한 번호

void setup() {
  stepper.setDir(1);
  stepper.setSpeed(10); //이렇게 해야 잘 돌아감
}

void loop() {
  stepper.move(360);
  delay(500);
  stepper.move(-360);
  delay(500);
}
