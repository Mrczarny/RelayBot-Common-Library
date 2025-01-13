#ifndef _rotation_h
#define _rotation_h

#include "Arduino.h"
#include <motors.h>

#define _wheelC (5.4 * PI)
#define RobotC (11 * PI)
#define _PULSES_PER_ROTATION 40  // Pulses per full rotation
#define _DISTANCE_PER_PULSE (_wheelC / _PULSES_PER_ROTATION)  // Distance per pulse in centimeters


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
    void leftTurnFor(int distance);
    void rightTurnFor(int distance);
    float getTotalDistance();

private:
    int _leftMotorRotationPin;
    int _rightMotorRotationPin;
    Motors *_motors;
};

#endif