#ifndef _motors_h
#define _motors_h

#include "Arduino.h"

class Motors {
  public:
    Motors(int leftMotorSpeedPin, int leftMotorDirectionPin, int rightMotorSpeedPin, int rightMotorDirectionPin):
      _leftMotorSpeedPin(leftMotorSpeedPin),
      _leftMotorDirectionPin(leftMotorDirectionPin),
      _rightMotorSpeedPin(rightMotorSpeedPin),
      _rightMotorDirectionPin(rightMotorDirectionPin)

    {
      pinMode(_leftMotorSpeedPin, OUTPUT);
      pinMode(_leftMotorDirectionPin, OUTPUT);
      pinMode(_rightMotorSpeedPin, OUTPUT);
      pinMode(_rightMotorDirectionPin, OUTPUT);
    }
    void setup(
      int maxLeftForwardSpeed,
      int maxRightForwardSpeed,
      int maxLeftBackwardSpeed,
      int maxRightBackwardSpeed
    );
    void forward();
    void forward(int speed);
    void backward();
    void backward(int speed);
    void zeroLeft();
    void zeroLeft(int speed);
    void zeroRight();
    void zeroRight(int speed);
    void right();
    void left();
    void stop();
    void setLeftMotorSpeed(int speed);
    void setRightMotorSpeed(int speed);
  private:
    int _leftMotorSpeedPin;
    int _leftMotorDirectionPin;
    int _rightMotorSpeedPin;
    int _rightMotorDirectionPin;
    int _maxRightForwardSpeed = 0;
    int _maxLeftForwardSpeed = 0;
    int _maxRightBackwardSpeed = 255;
    int _maxLeftBackwardSpeed = 255;
    byte _left_speed = 127;
    byte _right_speed = 127;
};




#endif