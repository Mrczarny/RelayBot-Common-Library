#include "gripper.h"

unsigned long timeGripper = 0;
void Gripper::gripper(int position){
  if (millis() > timeGripper ){ 
    for (int i = 0; i < 5; i++) {
      digitalWrite(_ServoPin, HIGH); 
      delay(position);
      digitalWrite(_ServoPin, LOW);
      timeGripper += 20;
    }
  }
}
