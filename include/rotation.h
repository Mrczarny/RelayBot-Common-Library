#ifndef _rotation_h
#define _rotation_h

#include "Arduino.h"
#include <motors.h>

#define _wheelC (5.4 * PI)
#define RobotC (11 * PI)

static volatile int _leftCount;
static volatile int _rightCount;
static int COUNT_INTERVAL;

class Rotation
{
public:
    Rotation(int leftMotorRotation, int rightMotorRotation);
    void setup(Motors *motors,
               int leftCount = 0,
               int rightCount = 0);
    void moveForwardFor(int distance);
    void moveBackwardFor(int distance);
    void turnDegreesRight(int degrees);
    void turnDegreesLeft(int degrees);
    float calculateSpeed();

private:
    int _leftMotorRotationPin;
    int _rightMotorRotationPin;
    Motors *_motors;
};

#endif