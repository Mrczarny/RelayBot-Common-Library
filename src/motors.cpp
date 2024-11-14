#include "motors.h"


void Motors::forward() {
  analogWrite(_leftMotorPin1, _maxSpeed);
  analogWrite(_leftMotorPin2, 0);
  analogWrite(_rightMotorPin1, _maxSpeed);
  analogWrite(_rightMotorPin2, 0);
}

void Motors::backward() {
  analogWrite(_leftMotorPin1, 0);
  analogWrite(_leftMotorPin2, _maxSpeed);
  analogWrite(_rightMotorPin1, 0);
  analogWrite(_rightMotorPin2, _maxSpeed);
}

void Motors::zeroLeft() {
  analogWrite(_leftMotorPin1, _maxSpeed);
  analogWrite(_leftMotorPin2, 0);
  analogWrite(_rightMotorPin1, 0);
  analogWrite(_rightMotorPin2, _maxSpeed);
}

void Motors::zeroRight() {
  analogWrite(_leftMotorPin1, 0);
  analogWrite(_leftMotorPin2, _maxSpeed);
  analogWrite(_rightMotorPin1, _maxSpeed);
  analogWrite(_rightMotorPin2, 0);
}

void Motors::right() {
  analogWrite(_leftMotorPin1, _maxSpeed);
  analogWrite(_leftMotorPin2, 0);
  analogWrite(_rightMotorPin1, _maxSpeed*0.7);
  analogWrite(_rightMotorPin2, 0);
}

void Motors::left() {
  analogWrite(_leftMotorPin1, _maxSpeed*0.7);
  analogWrite(_leftMotorPin2, 0);
  analogWrite(_rightMotorPin1, _maxSpeed);
  analogWrite(_rightMotorPin2, 0);
}

void Motors::stop() {
  analogWrite(_leftMotorPin1, 0);
  analogWrite(_leftMotorPin2, 0);
  analogWrite(_rightMotorPin1, 0);
  analogWrite(_rightMotorPin2, 0);
}



