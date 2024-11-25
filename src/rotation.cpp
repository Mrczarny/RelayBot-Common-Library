#include "rotation.h"
#include <motors.h>



int _leftRotationPinInternal;
int _rightRotationPinInternal;

void leftRotationCheck();
void rightRotationCheck();

void Rotation::setup(
    int leftCount,
    int rightCount, int leftMotorRotationPin, int rightMotorRotationPin)
{
    attachInterrupt(digitalPinToInterrupt(leftMotorRotationPin), leftRotationCheck, CHANGE);
    attachInterrupt(digitalPinToInterrupt(rightMotorRotationPin), rightRotationCheck, CHANGE);
    _leftCount = leftCount;
    _rightCount = rightCount;
    _leftRotationPinInternal = _leftMotorRotationPin;
    _rightRotationPinInternal = _rightMotorRotationPin;
    
}



static void leftRotationCheck()
{
    Serial.println("leftRotationCheck");
    static unsigned long timer;
    static bool lastState;
    noInterrupts();
    if (millis() > timer)
    {
        bool state = digitalRead(_leftRotationPinInternal);
        if (state != lastState)
        {
            _leftCount++;
            lastState = state;
        }
        timer = millis() + COUNT_INTERVAL;
    }
    interrupts();
}

static void rightRotationCheck()
{
    static unsigned long timer;
    static bool lastState;
    noInterrupts();
    if (millis() > timer)
    {
        bool state = digitalRead(_rightRotationPinInternal);
        if (state != lastState)
        {
            _rightCount++;

            lastState = state;
        }
        timer = millis() + COUNT_INTERVAL;
    }
    interrupts();
}
