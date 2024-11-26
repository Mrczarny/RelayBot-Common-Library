#ifndef GRIPPER_H
#define GRIPPER_H

#include "Arduino.h"

class Gripper {
    public:
    Gripper(int ServoPin):
        _ServoPin(ServoPin)
    
    {
        pinMode(_ServoPin, INPUT);

    }
    void gripper(int position);
    private:
    int _ServoPin;
};

#endif