#include "rotation.h"


void leftRotationCheck();
void rightRotationCheck();


void Rotation::setup(
    int _leftCount,
    int _rightCount
) {
    _leftCount = _leftCount;
    _rightCount = _rightCount;
}


void Rotation::leftRotationCheck(){
    static unsigned long timer;
    static bool lastState;
    noInterrupts();
    if (millis() > timer)
    {
        bool state = digitalRead(_leftMotorRotationPin);
            if(state != lastState)
            {
                _leftCount++;
                lastState = state;
            }
        timer = millis() + COUNT_INTERVAL;
    }
    interrupts();
}


void Rotation::rightRotationCheck(){
    static unsigned long timer;
    static bool lastState;
    noInterrupts();
    if (millis() > timer)
    {
        bool state = digitalRead(_rightMotorRotationPin);
            if(state != lastState)
            {
                _leftCount++;
                lastState = state;
            }
        timer = millis() + COUNT_INTERVAL;
    }
    interrupts();
}

