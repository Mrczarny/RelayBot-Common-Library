#ifndef GRIPPER_H
#define GRIPPER_H

#include "Arduino.h"

class Gripper {
    public:
    Gripper(int ServoPin, int OPENGRIPPER, int CLOSEGRIPPER):
        _ServoPin(ServoPin),
        _OpenGripper(OPENGRIPPER),  //My values were 2
        _CloseGripper(CLOSEGRIPPER) //And 1 for closed
    {
        pinMode(_ServoPin, INPUT);

    }
    void gripper(int position);
    const int _OpenGripper;
    const int _CloseGripper;
    private:
    int _ServoPin;
    
};

#endif