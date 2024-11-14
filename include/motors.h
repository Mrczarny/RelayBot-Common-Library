#ifndef _motors_h
#define _motors_h

#include "Arduino.h"

class Motors {
  public:
    Motors(int leftMotorPin1, int leftMotorPin2, int rightMotorPin1, int rightMotorPin2, int maxSpeed, int minSpeed):
      _leftMotorPin1(leftMotorPin1),
      _leftMotorPin2(leftMotorPin2),
      _rightMotorPin1(rightMotorPin1),
      _rightMotorPin2(rightMotorPin2),
      _maxSpeed(maxSpeed),
      _minSpeed(minSpeed)
    {
      pinMode(_leftMotorPin1, OUTPUT);
      pinMode(_leftMotorPin2, OUTPUT);
      pinMode(_rightMotorPin1, OUTPUT);
      pinMode(_rightMotorPin2, OUTPUT);
    }
    void forward();
    void backward();
    void zeroLeft();
    void zeroRight();
    void right();
    void left();
    void stop();
  private:
    int _leftMotorPin1;
    int _leftMotorPin2;
    int _rightMotorPin1;
    int _rightMotorPin2;
    int _maxSpeed;
    int _minSpeed;
};




#endif