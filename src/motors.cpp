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
  analogWrite(_leftMotorForwardPin, _maxLeftForwardSpeed);
  analogWrite(_leftMotorBackwardPin, 0);
  analogWrite(_rightMotorForwardPin, _maxRightForwardSpeed);
  analogWrite(_rightMotorBackwardPin, 0);
}

void Motors::backward() {
  analogWrite(_leftMotorForwardPin, 0);
  analogWrite(_leftMotorBackwardPin, _maxLeftBackwardSpeed);
  analogWrite(_rightMotorForwardPin, 0);
  analogWrite(_rightMotorBackwardPin, _maxRightBackwardSpeed);
}

void Motors::zeroLeft() {
  analogWrite(_leftMotorForwardPin, _maxLeftBackwardSpeed);
  analogWrite(_leftMotorBackwardPin, 0);
  analogWrite(_rightMotorForwardPin, 0);
  analogWrite(_rightMotorBackwardPin, _maxRightBackwardSpeed);
}

void Motors::zeroRight() {
  analogWrite(_leftMotorForwardPin, 0);
  analogWrite(_leftMotorBackwardPin, _maxLeftBackwardSpeed);
  analogWrite(_rightMotorForwardPin, _maxRightBackwardSpeed);
  analogWrite(_rightMotorBackwardPin, 0);
}

void Motors::right() {
  analogWrite(_leftMotorForwardPin, _maxLeftForwardSpeed);
  analogWrite(_leftMotorBackwardPin, 0);
  analogWrite(_rightMotorForwardPin, _maxRightForwardSpeed*0.7);
  analogWrite(_rightMotorBackwardPin, 0);
}

void Motors::left() {
  analogWrite(_leftMotorForwardPin, _maxLeftForwardSpeed*0.7);
  analogWrite(_leftMotorBackwardPin, 0);
  analogWrite(_rightMotorForwardPin, _maxRightForwardSpeed);
  analogWrite(_rightMotorBackwardPin, 0);
}

void Motors::stop() {
  analogWrite(_leftMotorForwardPin, 0);
  analogWrite(_leftMotorBackwardPin, 0);
  analogWrite(_rightMotorForwardPin, 0);
  analogWrite(_rightMotorBackwardPin, 0);
}



