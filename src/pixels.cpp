#include "pixels.h"
#include <Adafruit_NeoPixel.h>

Pixels::Pixels(int pixelPin)
{
    _pixelPin = pixelPin;
    _neoPixels = Adafruit_NeoPixel(_pixelCount, _pixelPin, NEO_RGB + NEO_KHZ800);
}

void Pixels::setup()
{
    _neoPixels.begin();
}

void Pixels::normal_Pixel()
{
  //pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  _neoPixels.clear();
  _neoPixels.setPixelColor(0, _neoPixels.Color(75,0,0)); // red at 60
  _neoPixels.setPixelColor(1, _neoPixels.Color(75,0,0)); // red at 60
  _neoPixels.setPixelColor(2, _neoPixels.Color(255, 255, 75)); // white ish headlights 100
  _neoPixels.setPixelColor(3, _neoPixels.Color(255, 255, 75)); // white ish headlights 100
  _neoPixels.show();
}

void Pixels::braking_Pixel()
{
  //_neoPixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  _neoPixels.clear();
  _neoPixels.setPixelColor(0, _neoPixels.Color(255,0,0)); // red at 100
  _neoPixels.setPixelColor(1, _neoPixels.Color(255,0,0)); // red at 100
  _neoPixels.setPixelColor(2, _neoPixels.Color(255, 255, 75)); // white ish headlights 100
  _neoPixels.setPixelColor(3, _neoPixels.Color(255, 255, 75)); // white ish headlights 100
  _neoPixels.show();
}

void Pixels::back_Pixel()
{
  _neoPixels.clear();
  _neoPixels.setPixelColor(0, _neoPixels.Color(255,0,0)); // red at 100
  _neoPixels.setPixelColor(1, _neoPixels.Color(255,255,255)); // red at 100
  _neoPixels.setPixelColor(2, _neoPixels.Color(255, 255, 75)); // white ish headlights 100
  _neoPixels.setPixelColor(3, _neoPixels.Color(255, 255, 75)); // white ish headlights 100
  _neoPixels.show();
}

  void Pixels::right_Pixel()
  {
    static bool lightOn = false;
    static unsigned long timer = millis();

    if ((millis() - timer) > 500)
    {
      if(lightOn == true)
      {
        _neoPixels.clear();
        _neoPixels.setPixelColor(0, _neoPixels.Color(75, 0, 0));      // Red at 60
        _neoPixels.setPixelColor(1, _neoPixels.Color(255, 100, 0));   // Orange
        _neoPixels.setPixelColor(2, _neoPixels.Color(255, 100, 0));   // Orange
        _neoPixels.setPixelColor(3, _neoPixels.Color(255, 255, 75));  // White-ish headlights
        _neoPixels.show();
      }
      else
        /*
        0 = leftback
        1 = rightback
        2 = leftfront
        3 = rightfront
        */
      {
        _neoPixels.clear();
        _neoPixels.setPixelColor(0, _neoPixels.Color(75, 0, 0));      // Red at 60
        _neoPixels.setPixelColor(1, _neoPixels.Color(0,0,0));
        _neoPixels.setPixelColor(2, _neoPixels.Color(0,0,0));
        _neoPixels.setPixelColor(3, _neoPixels.Color(255, 255, 75));  // White-ish headlights
        _neoPixels.show(); // Turn off the orange pixels
      }
      lightOn = !lightOn;
      timer = millis();
    }
  }

void Pixels::left_Pixel() 
{
  static bool lightOn = false;
    static unsigned long timer = millis();

    if ((millis() - timer) > 500)
    {
      if(lightOn == true)
      {
        _neoPixels.clear();
        _neoPixels.setPixelColor(0, _neoPixels.Color(255, 100, 0));   // Orange
        _neoPixels.setPixelColor(1, _neoPixels.Color(75, 0, 0));      // Red
        _neoPixels.setPixelColor(2, _neoPixels.Color(255, 255, 75));  // White
        _neoPixels.setPixelColor(3, _neoPixels.Color(255, 100, 0));   // Orange
        _neoPixels.show();
        }
      else
        /*
        0 = leftback
        1 = rightback
        2 = leftfront
        3 = rightfront
        */
      {
        _neoPixels.clear();
        _neoPixels.setPixelColor(0, _neoPixels.Color(0, 0, 0));      // Red at 60
        _neoPixels.setPixelColor(1, _neoPixels.Color(75, 0, 0));
        _neoPixels.setPixelColor(2, _neoPixels.Color(255, 255, 75));
        _neoPixels.setPixelColor(3, _neoPixels.Color(0, 0, 0));  // White-ish headlights
        _neoPixels.show(); // Turn off the orange pixels
      }
      lightOn = !lightOn;
      timer = millis();
    }
  }