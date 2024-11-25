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
  digitalWrite(_leftMotorDirectionPin, HIGH);                      // direction of left motor
  analogWrite(_leftMotorSpeedPin, _maxLeftForwardSpeed);           // speed of left motor 
  digitalWrite(_rightMotorDirectionPin, HIGH);                     // direction of right motor
  analogWrite(_rightMotorSpeedPin, _maxRightForwardSpeed);         // speed of right motor 
}

void Motors::forward(int speed) {
  digitalWrite(_leftMotorDirectionPin, HIGH);                      // direction of left motor
  analogWrite(_leftMotorSpeedPin, _maxLeftForwardSpeed*speed);     // speed of left motor 
  digitalWrite(_rightMotorDirectionPin, HIGH);                     // direction of right motor
  analogWrite(_rightMotorSpeedPin, _maxRightForwardSpeed*speed);   // speed of right motor 
}

void Motors::backward() {
  digitalWrite(_leftMotorDirectionPin, LOW);                       // direction of left motor
  analogWrite(_leftMotorSpeedPin, _maxLeftBackwardSpeed);          // speed of left motor
  digitalWrite(_rightMotorDirectionPin, LOW);                      // direction of right motor
  analogWrite(_rightMotorSpeedPin, _maxRightBackwardSpeed);    // speed of left motor
}

void Motors::zeroLeft() {
  digitalWrite(_leftMotorDirectionPin, LOW);                       // direction of left motor
  analogWrite(_leftMotorSpeedPin, _maxLeftBackwardSpeed);          // speed of left motor
  digitalWrite(_rightMotorDirectionPin, HIGH);                     // direction of right motor
  analogWrite(_rightMotorSpeedPin, _maxRightForwardSpeed);         // speed of right motor
}

void Motors::zeroRight() {
  digitalWrite(_leftMotorDirectionPin, HIGH);                      // direction of left motor
  analogWrite(_leftMotorSpeedPin, _maxLeftForwardSpeed);           // speed of left motor
  digitalWrite(_rightMotorDirectionPin, LOW);                      // direction of right motor
  analogWrite(_rightMotorSpeedPin, _maxRightBackwardSpeed);        // speed of right motor
}

void Motors::right() {
  digitalWrite(_leftMotorDirectionPin, HIGH);                      // direction of left motor
  analogWrite(_leftMotorSpeedPin, _maxLeftForwardSpeed);           // speed of left motor
  digitalWrite(_rightMotorDirectionPin, HIGH);                     // direction of right motor
  analogWrite(_rightMotorSpeedPin, _maxRightForwardSpeed*0.7); // speed of right motor * 0.7 to initiate turn
}

void Motors::left() {
  digitalWrite(_leftMotorDirectionPin, HIGH);                      // direction of left motor
  analogWrite(_leftMotorSpeedPin, _maxLeftForwardSpeed*0.7);       // speed of left motor * 0.7 to initiate turn
  digitalWrite(_rightMotorDirectionPin, HIGH);                     // direction of right motor
  analogWrite(_rightMotorSpeedPin, _maxRightForwardSpeed);         // speed of right motor
}

void Motors::stop() {
  digitalWrite(_leftMotorDirectionPin, LOW);                       // direction of left motor, can be HIGH or LOW
  analogWrite(_leftMotorSpeedPin, 0);                              // speed of left motor, if HIGH value = 255, if LOW value = 0
  digitalWrite(_rightMotorDirectionPin, LOW);                      // direction of right motor, can be HIGH or LOW
  analogWrite(_rightMotorSpeedPin, 0);                             // speed of right motor, if HIGH vlaue = 255 if LOW vlaue = 0
}

void Motors::setLeftMotorSpeed(int speed){
  if (speed >= 0 && speed <= 255){
    _left_speed = speed;                                           // set speed for left motor
    analogWrite(_leftMotorSpeedPin, _left_speed);                  // update left motor PWM pin output value
  }
}

void Motors::setRightMotorSpeed(int speed){
  if (speed >= 0 && speed <= 255){
    _right_speed = speed;                                          // set speed for right motor
    analogWrite(_rightMotorSpeedPin, _right_speed);                // update right motor PWM pin output value
  }
}