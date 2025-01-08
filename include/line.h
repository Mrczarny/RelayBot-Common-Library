#ifndef _line_h
#define _line_h

#include "Arduino.h"


/// @brief single line sensor
struct linePoint
{
    /// @brief position of the sensor from left to right
    int pointPosition;
    /// @brief value of the sensor
    long sensorValue;
    boolean isLine;
} typedef linePoint;

/// @brief line sensor array data for max 8 sensors
struct lineSensorData
{
    /// @brief array of line points
    linePoint linePoints[8];
} typedef lineSensorData;


uint8_t convertToBinary(lineSensorData line);

class Line
{
private:
    int _sensorsNumber;
    int _sensorPins[8] = {NULL};
    int _breakPoints[8] = {NULL};
public:
    /// @brief Construct a new Line object with the number of sensors and the pins
    /// @param sensorsNumber Number of sensors
    /// @param sensorPins sensor pins in order from left to right, leave NULL if not used
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
    void setup(int breakPoint);
    void setup(int breakPoints[]);
    lineSensorData readLine();
    linePoint readLinePoint(int pointPosition);
};



#endif