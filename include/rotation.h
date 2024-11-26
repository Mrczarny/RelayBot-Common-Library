#ifndef _rotation_h
#define _rotation_h

#include "Arduino.h"
#include <motors.h>

#define _wheelC (5.4 * PI)
#define RobotC (11 * PI)

static int _leftCount;
static int _rightCount;
static int COUNT_INTERVAL;

class Rotation
{
public:
    Rotation(int leftMotorRotation, int rightMotorRotation);
    void setup(
        int leftCount,
        int rightCount, 
        Motors* motors);
    void moveForwardFor(int distance);
    void moveBackwardFor(int distance);
    void turnDegreesRight(int degrees);
    void turnDegreesLeft(int degrees);

private:
    int _leftMotorRotationPin;
    int _rightMotorRotationPin;
    Motors* _motors;
};

#endif