#ifndef SONAR_H
#define SONAR_H

#include "Arduino.h"

class Sonar {
    public:
    Sonar(int TriggerPin, int EchoPin):
        _TriggerPin(TriggerPin),
        _EchoPin(EchoPin)
    
    {
        pinMode(_TriggerPin, OUTPUT);
        pinMode(_EchoPin, INPUT);
    }
    void setup();
    int getDistance();
    int test_distance();
    private:
    int _TriggerPin;
    int _EchoPin;
};

#endif