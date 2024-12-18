#include "gripper.h"

unsigned long time = 0;
void Gripper::gripper(int position){
  if (millis() > time ){ 
    digitalWrite(_ServoPin, HIGH); 
    delay(position);
    digitalWrite(_ServoPin, LOW);
    time += 20;
  }
}
