#include "line.h"

void Line::setup() {
    return;
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
    if (_sensorPins[pointPosition] != NULL)
    {
        data.pointPosition = pointPosition;
        data.isLine = digitalRead(_sensorPins[pointPosition]) ? true : false;
    }
    return data;
}

