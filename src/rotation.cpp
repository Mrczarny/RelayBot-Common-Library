#include "rotation.h"
#include <motors.h>

int _leftRotationPinInternal;
int _rightRotationPinInternal;

static void leftRotationCheck()
{
    //Serial.println("left");
    static unsigned long timer;
    static bool lastState;
    noInterrupts();
    if (millis() > timer)
    {
        bool state = digitalRead(_leftRotationPinInternal);
        if (state != lastState)
        {
            _leftCount++;
            // Serial.print("l");
            // Serial.print(_leftCount);
            // Serial.print("\n");
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
            // Serial.print("r");
            // Serial.print(_rightCount);
            // Serial.print("\n");
            lastState = state;
        }
        timer = millis() + COUNT_INTERVAL;
    }
    interrupts();
}

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

void Rotation::setup(
    int leftCount,
    int rightCount,
    Motors* motors)
{
    attachInterrupt(digitalPinToInterrupt(_leftMotorRotationPin), leftRotationCheck, CHANGE);
    attachInterrupt(digitalPinToInterrupt(_rightMotorRotationPin), rightRotationCheck, CHANGE);
    _motors = motors;
    _leftCount = leftCount;
    _rightCount = rightCount;
    _leftRotationPinInternal = _leftMotorRotationPin;
    _rightRotationPinInternal = _rightMotorRotationPin;
}

void Rotation::moveForwardFor( int distance)
{
    int steps = (distance / _wheelC) * 40;
    int leftSteps = _leftCount + steps;
    int rightSteps = _rightCount + steps;
    // Serial.println(steps);
    // Serial.println(leftEnd);
    // Serial.println(rightEnd);
    // Serial.println(leftSteps);
    // Serial.println(rightSteps);

    while ((_leftCount < leftSteps) && (_rightCount < rightSteps))
    {
        // Somehow it's bugged without this 
        Serial.println(_leftCount);
        // Serial.println(_rightCount);
        _motors->forward();
    }
    _motors->stop();
    // Serial.println("done");
}

void Rotation::moveBackwardFor(int distance)
{
    int steps = (distance / _wheelC) * 40;
    int leftSteps = _leftCount + steps;
    int rightSteps = _rightCount + steps;

    //Serial.println(steps);

    while ((_leftCount < leftSteps) && (_rightCount < rightSteps))
    {
        // Somehow it's bugged without this 
        Serial.println(_leftCount);
        //Serial.println(_rightCount);
        _motors->backward();
    }
    //Serial.println("done");
    _motors->stop();
}

void Rotation::turnDegreesRight(int degrees)
{
    int steps = ((float)degrees / 360 * RobotC) / _wheelC * 40;
    int leftSteps = _leftCount + steps;
    int rightSteps = _rightCount + steps;

    //Serial.println(steps);

    while ((_leftCount < leftSteps) && (_rightCount < rightSteps))
    {
        // Somehow it's bugged without this 
        Serial.println(_leftCount);
        //Serial.println(_rightCount);
        _motors->zeroRight();
    }
    //Serial.println("done");
    _motors->stop();
}

void Rotation::turnDegreesLeft(int degrees)
{
    int steps = ((float)degrees / 360 * RobotC) / _wheelC * 40;
    int leftSteps = _leftCount + steps;
    int rightSteps = _rightCount + steps;

    //Serial.println(steps);

    while ((_leftCount < leftSteps) && (_rightCount < rightSteps))
    {
        // Somehow it's bugged without this 
        Serial.println(_leftCount);
        //Serial.println(_rightCount);
        _motors->zeroLeft();
    }
    //Serial.println("done");
    _motors->stop();
}


