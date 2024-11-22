#include "line.h"

void Line::setup(int breakPoint) {
    for (int i = 0; i < _sensorsNumber; i++)
    {
        _breakPoints[i] = breakPoint;
    }
}

void Line::setup(int breakPoints[]) {
    for (int i = 0; i < _sensorsNumber; i++)
    {
        _breakPoints[i] = breakPoints[i];
    }
}

lineSensorData Line::readLine() {
    lineSensorData data;
    for (int i = 0; i < _sensorsNumber; i++)
    {
        data.linePoints[i] = readLinePoint(i);
    }
    return data;
}

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

