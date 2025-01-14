#ifndef _pixels_h
#define _pixels_h

#include "Arduino.h"
#include <pixels.h>
#include <Adafruit_NeoPixel.h>

class Pixels
{
    public:
        Pixels(int pixelPin);
        void setup();
        void normal_Pixel();
        void braking_Pixel();
        void back_Pixel();
        void right_Pixel();
        void left_Pixel();
    private:
    int _pixelPin = 13;
    int _pixelCount = 4;
    Adafruit_NeoPixel _neoPixels = Adafruit_NeoPixel(_pixelCount, _pixelPin, NEO_RGB + NEO_KHZ800);
};

#endif