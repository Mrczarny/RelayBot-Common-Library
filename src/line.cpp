#include "line.h"


/// @brief setup for the line sensor, sets one value breakpoint for all sensors
/// @param breakPoint value for the breakpoint
void Line::setup(int breakPoint) {
    for (int i = 0; i < _sensorsNumber; i++)
    {
        _breakPoints[i] = breakPoint;
    }
}


/// @brief setup for the line sensor, sets different value breakpoints for each sensor
/// @param breakPoints array of breakpoints
void Line::setup(int breakPoints[]) {
    for (int i = 0; i < _sensorsNumber; i++)
    {
        _breakPoints[i] = breakPoints[i];
    }
}


/// @brief reads the line sensor data for all sensors
/// @return lineSensorData - struct with all the sensor points
lineSensorData Line::readLine() {
    lineSensorData data;
    for (int i = 0; i < _sensorsNumber; i++)
    {
        data.linePoints[i] = readLinePoint(i);
    }
    return data;
}


/// @brief reads the line sensor data for a single sensor
/// @param pointPosition position of the sensor
/// @return linePoint - struct with the sensor data
linePoint Line::readLinePoint(int pointPosition) {
    linePoint data;
    data.pointPosition = -1;
    data.sensorValue = -1;
    if (_sensorPins[pointPosition] != NULL)
    {
        data.pointPosition = pointPosition;
        data.sensorValue = analogRead(_sensorPins[pointPosition]);
        data.sensorValue > _breakPoints[pointPosition] ? data.isLine = true : data.isLine = false;
    }

    return data;
}

