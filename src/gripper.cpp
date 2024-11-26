#include "gripper.h"

void Gripper::gripper(int position){
  for(int x=0; x < 40; x++){
    Serial.println(x);
    digitalWrite(_ServoPin, HIGH); 
    delay(position);
    digitalWrite(_ServoPin, LOW);
    delay(20);
  }
}