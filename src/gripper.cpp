#include "gripper.h"

unsigned long time2 = 0;
void Gripper::gripper(int position){
  if (millis() > time2){ 
    digitalWrite(_ServoPin, HIGH); 
    delay(position);
    digitalWrite(_ServoPin, LOW);
    delay(20);
  }
}
