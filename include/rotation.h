#ifndef _rotation_h
#define _rotation_h

#include "Arduino.h"

class Rotation {
    public:
        Rotation(int leftMotorRotation, int rightMotorRotation):
            _leftMotorRotationPin(leftMotorRotation),
            _rightMotorRotationPin(rightMotorRotation)

            {
                pinMode(_leftMotorRotationPin, INPUT_PULLUP);
                pinMode(_rightMotorRotationPin, INPUT_PULLUP);
                attachInterrupt(digitalPinToInterrupt(_leftMotorRotationPin), leftRotationCheck, CHANGE);
                attachInterrupt(digitalPinToInterrupt(_rightMotorRotationPin), rightRotationCheck, CHANGE);
            }
            void setup(
                int _leftCount,
                int _rightCount            
            );
            static void leftRotationCheck();
            static void rightRotationCheck();
        private:
            int _leftMotorRotationPin;
            int _rightMotorRotationPin;
            int _leftCount = 0;
            int _rightCount = 0;
            const int COUNT_INTERVAL = 10;
};





#endif