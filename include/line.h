#ifndef _line_h
#define _line_h

#include "Arduino.h"

/// @brief line sensor array data for max 8 sensors
typedef struct lineSensorData
{
    /// @brief array of line points
    linePoint linePoints[8];
};


/// @brief single line sensor
typedef struct linePoint
{
    /// @brief position of the sensor from left to right
    int pointPosition;
    /// @brief value of the sensor
    boolean isLine;
};





class Line
{
private:
    int _sensorsNumber;
    int _sensorPins[8] = {NULL};
public:
    Line(int sensorsNumber, int sensorPins[8]){
        _sensorsNumber = sensorsNumber;
        for (int i = 0; i < sensorsNumber; i++) {
            
            if (_sensorPins[i] != NULL)
            {
                pinMode(_sensorPins[i], INPUT);
            }
            
            _sensorPins[i] = sensorPins[i];
        }
    };
    void setup();
    lineSensorData readLine();
    linePoint readLinePoint(int pointPosition);
};


#endif