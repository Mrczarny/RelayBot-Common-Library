#ifndef _rotation_h
#define _rotation_h

#include "Arduino.h"

static int _leftCount;
static int _rightCount;
static int COUNT_INTERVAL;

class Rotation
{
public:
    Rotation(int leftMotorRotation, int rightMotorRotation)
    {
        _leftMotorRotationPin = leftMotorRotation;
        _rightMotorRotationPin = rightMotorRotation;
        _leftCount = 0;
        _rightCount = 0;
        COUNT_INTERVAL = 10;
        pinMode(_leftMotorRotationPin, INPUT_PULLUP);
        pinMode(_rightMotorRotationPin, INPUT_PULLUP);
    }
    void setup(
        int leftCount,
        int rightCount, 
        int leftMotorRotationPin,
        int rightMotorRotationPin);
    void moveForwardFor(int distance);

private:
    int _leftMotorRotationPin;
    int _rightMotorRotationPin;
};

#endif