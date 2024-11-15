#ifndef _motors_h
#define _motors_h

#include "Arduino.h"

class Motors {
  public:
    Motors(int leftMotorPin1, int leftMotorPin2, int rightMotorPin1, int rightMotorPin2):
      _leftMotorForwardPin(leftMotorPin1),
      _leftMotorBackwardPin(leftMotorPin2),
      _rightMotorForwardPin(rightMotorPin1),
      _rightMotorBackwardPin(rightMotorPin2)

    {
      pinMode(_leftMotorForwardPin, OUTPUT);
      pinMode(_leftMotorBackwardPin, OUTPUT);
      pinMode(_rightMotorForwardPin, OUTPUT);
      pinMode(_rightMotorBackwardPin, OUTPUT);
    }
    void setup(
      int maxLeftForwardSpeed,
      int maxRightForwardSpeed,
      int maxLeftBackwardSpeed,
      int maxRightBackwardSpeed
    );
    void forward();
    void backward();
    void zeroLeft();
    void zeroRight();
    void right();
    void left();
    void stop();
  private:
    int _leftMotorForwardPin;
    int _leftMotorBackwardPin;
    int _rightMotorForwardPin;
    int _rightMotorBackwardPin;
    int _maxRightForwardSpeed = 255;
    int _maxLeftForwardSpeed = 255;
    int _maxRightBackwardSpeed = 255;
    int _maxLeftBackwardSpeed = 255;
};




#endif