#include "motors.h"


void Motors::setup(
  int maxLeftForwardSpeed,
  int maxRightForwardSpeed,
  int maxLeftBackwardSpeed,
  int maxRightBackwardSpeed
) {
  _maxLeftForwardSpeed = maxLeftForwardSpeed;
  _maxRightForwardSpeed = maxRightForwardSpeed;
  _maxLeftBackwardSpeed = maxLeftBackwardSpeed;
  _maxRightBackwardSpeed = maxRightBackwardSpeed;
}


void Motors::forward() {
  digitalWrite(_leftMotorDirectionPin, HIGH);      // direction of left motor
  analogWrite(_leftMotorSpeedPin, _maxLeftForwardSpeed);   // speed of left motor 
  digitalWrite(_rightMotorDirectionPin, HIGH);      // direction of right motor
  analogWrite(_rightMotorSpeedPin, _maxRightForwardSpeed);  // speed of right motor 
}

void Motors::forward(int speed) {
  digitalWrite(_leftMotorDirectionPin, HIGH);      // direction of left motor
  analogWrite(_leftMotorSpeedPin, _maxLeftForwardSpeed*speed);   // speed of left motor 
  digitalWrite(_rightMotorDirectionPin, HIGH);      // direction of right motor
  analogWrite(_rightMotorSpeedPin, _maxRightForwardSpeed*speed);  // speed of right motor 
}

void Motors::backward() {
  analogWrite(_leftMotorDirectionPin, LOW);
  analogWrite(_leftMotorSpeedPin, _maxLeftBackwardSpeed);
  analogWrite(_rightMotorDirectionPin, LOW);
  analogWrite(_rightMotorDirectionPin, _maxRightBackwardSpeed);
}

void Motors::zeroLeft() {
  analogWrite(_leftMotorDirectionPin, LOW);
  analogWrite(_leftMotorSpeedPin, _maxLeftBackwardSpeed);
  analogWrite(_rightMotorDirectionPin, HIGH);
  analogWrite(_rightMotorSpeedPin, _maxRightForwardSpeed);
}

void Motors::zeroRight() {
  analogWrite(_leftMotorDirectionPin, HIGH);
  analogWrite(_leftMotorSpeedPin, _maxLeftForwardSpeed);
  analogWrite(_rightMotorDirectionPin, LOW);
  analogWrite(_rightMotorSpeedPin, _maxRightBackwardSpeed);
}

void Motors::right() {
  analogWrite(_leftMotorDirectionPin, HIGH);
  analogWrite(_leftMotorSpeedPin, _maxLeftForwardSpeed);
  analogWrite(_rightMotorDirectionPin, HIGH);
  analogWrite(_rightMotorDirectionPin, _maxRightForwardSpeed*0.7);
}

void Motors::left() {
  analogWrite(_leftMotorDirectionPin, HIGH);
  analogWrite(_leftMotorSpeedPin, _maxLeftForwardSpeed*0.7);
  analogWrite(_rightMotorDirectionPin, HIGH);
  analogWrite(_rightMotorSpeedPin, _maxRightForwardSpeed);
}

void Motors::stop() {
  analogWrite(_leftMotorDirectionPin, LOW);
  analogWrite(_leftMotorSpeedPin, 0);
  analogWrite(_rightMotorDirectionPin, LOW);
  analogWrite(_rightMotorSpeedPin, 0);
}

void Motors::setLeftMotorSpeed(int speed){
  if (speed >= 0 && speed <= 255){
    _left_speed = speed;
    analogWrite(_leftMotorSpeedPin, _left_speed);
  }
}

void Motors::setRightMotorSpeed(int speed){
  if (speed >= 0 && speed <= 255){
    _right_speed = speed;
    analogWrite(_rightMotorSpeedPin, _right_speed);
  }
}

// correct all functions, and add set motor speed functions


