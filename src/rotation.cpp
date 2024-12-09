#include "rotation.h"
#include <motors.h>

int _leftRotationPinInternal;
int _rightRotationPinInternal;

static void leftRotationCheck()
{
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

/// @brief Construct a new Rotation:: Rotation object
/// @param leftMotorRotation left motor rotation pin
/// @param rightMotorRotation right motor rotation pin
Rotation::Rotation(int leftMotorRotation, int rightMotorRotation)
{
    _leftMotorRotationPin = leftMotorRotation;
    _rightMotorRotationPin = rightMotorRotation;
    _leftCount = 0;
    _rightCount = 0;
    COUNT_INTERVAL = 10;
    pinMode(_leftMotorRotationPin, INPUT_PULLUP);
    pinMode(_rightMotorRotationPin, INPUT_PULLUP);
}


/// @brief Setup the rotation object, needs to be called before any other function
/// @param leftCount start number of left count
/// @param rightCount start number of right count
/// @param motors pointer to the motors object to be used
void Rotation::setup(
    Motors* motors,
    int leftCount = 0,
    int rightCount = 0)
{
    attachInterrupt(digitalPinToInterrupt(_leftMotorRotationPin), leftRotationCheck, CHANGE);
    attachInterrupt(digitalPinToInterrupt(_rightMotorRotationPin), rightRotationCheck, CHANGE);
    _motors = motors;
    _leftCount = leftCount;
    _rightCount = rightCount;
    _leftRotationPinInternal = _leftMotorRotationPin;
    _rightRotationPinInternal = _rightMotorRotationPin;
}

/// @brief Just moves forward for a certain distance
/// @param distance distance in cm to move forward
void Rotation::moveForwardFor(int distance)
{
    int steps = (distance / _wheelC) * 40;
    int leftSteps = _leftCount + steps;
    int rightSteps = _rightCount + steps;

    while ((_leftCount < leftSteps) && (_rightCount < rightSteps))
    {
        _motors->forward();
    }
    _motors->stop();
}

/// @brief Just moves backward for a certain distance
/// @param distance distance in cm to move backward
void Rotation::moveBackwardFor(int distance)
{
    int steps = (distance / _wheelC) * 40;
    int leftSteps = _leftCount + steps;
    int rightSteps = _rightCount + steps;

    while ((_leftCount < leftSteps) && (_rightCount < rightSteps))
    {
        _motors->backward();
    }
    _motors->stop();
}


/// @brief turns the robot right by a certain number of degrees
/// @details accurancy is right now around 10 degrees
/// @param degrees number of degrees to turn right
void Rotation::turnDegreesRight(int degrees)
{
    int steps = ((float)degrees / 360 * RobotC) / _wheelC * 40;
    int leftSteps = _leftCount + steps;
    int rightSteps = _rightCount + steps;

    while ((_leftCount < leftSteps) && (_rightCount < rightSteps))
    {
        _motors->zeroRight();
    }
    _motors->stop();
}


/// @brief turns the robot left by a certain number of degrees
/// @param degrees amount of degrees to turn left
/// @details accurancy is right now around 10 degrees
void Rotation::turnDegreesLeft(int degrees)
{
    int steps = ((float)degrees / 360 * RobotC) / _wheelC * 40;
    int leftSteps = _leftCount + steps;
    int rightSteps = _rightCount + steps;

    while ((_leftCount < leftSteps) && (_rightCount < rightSteps))
    {
        _motors->zeroLeft();
    }
    _motors->stop();
}


