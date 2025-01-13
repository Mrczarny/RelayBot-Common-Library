#include <Arduino.h>
#include <Adafruit_NeoPixel.h>


/*
0 = leftback
1 = rightback
2 = leftfront
3 = rightfront
*/


// Which pin on the Arduino is connected to the NeoPixels?, 13 for stefan and everett, 11 i think for jan
int LEDPIN = 13;

// How many NeoPixels are attached to the Arduino?
int NUMPIXELS = 4;

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LEDPIN, NEO_RGB + NEO_KHZ800);

void normal_Pixel();
void braking_Pixel();
void back_Pixel();
void right_Pixel();
void left_Pixel();

//include pixles.begin(); in setup
void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  // pixels.setPixelColor(0, pixels.Color(150,0,0)); // red at about 60% of full brightness
  // pixels.setPixelColor(1, pixels.Color(0,150,0)); // green at about 60% of full brightness
  // pixels.setPixelColor(2, pixels.Color(0,0,150)); // blue at about 60% of full brightness
  // pixels.setPixelColor(3, pixels.Color(50,50,50)); // white at about 20% of full brightness

   normal_Pixel();
   delay(2000);
   braking_Pixel();
   delay(2000);
   //right_Pixel();
   //delay(2000);
   //left_Pixel();
   //delay(2000);
}

void normal_Pixel()
{
  //pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(75,0,0)); // red at 60
  pixels.setPixelColor(1, pixels.Color(75,0,0)); // red at 60
  pixels.setPixelColor(2, pixels.Color(255, 255, 75)); // white ish headlights 100
  pixels.setPixelColor(3, pixels.Color(255, 255, 75)); // white ish headlights 100
  pixels.show();
}

void braking_Pixel()
{
  //pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(255,0,0)); // red at 100
  pixels.setPixelColor(1, pixels.Color(255,0,0)); // red at 100
  pixels.setPixelColor(2, pixels.Color(255, 255, 75)); // white ish headlights 100
  pixels.setPixelColor(3, pixels.Color(255, 255, 75)); // white ish headlights 100
  pixels.show();
}

void back_Pixel()
{
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(255,0,0)); // red at 100
  pixels.setPixelColor(1, pixels.Color(255,255,255)); // red at 100
  pixels.setPixelColor(2, pixels.Color(255, 255, 75)); // white ish headlights 100
  pixels.setPixelColor(3, pixels.Color(255, 255, 75)); // white ish headlights 100
  pixels.show();
}

  void right_Pixel()
  {
    static bool lightOn = false;
    static unsigned long timer = millis();

    if ((millis() - timer) > 500)
    {
      if(lightOn == true)
      {
        pixels.clear();
        pixels.setPixelColor(0, pixels.Color(75, 0, 0));      // Red at 60
        pixels.setPixelColor(1, pixels.Color(255, 100, 0));   // Orange
        pixels.setPixelColor(2, pixels.Color(255, 100, 0));   // Orange
        pixels.setPixelColor(3, pixels.Color(255, 255, 75));  // White-ish headlights
        pixels.show();
      }
      else
        /*
        0 = leftback
        1 = rightback
        2 = leftfront
        3 = rightfront
        */
      {
        pixels.clear();
        pixels.setPixelColor(0, pixels.Color(75, 0, 0));      // Red at 60
        pixels.setPixelColor(1, pixels.Color(0,0,0));
        pixels.setPixelColor(2, pixels.Color(0,0,0));
        pixels.setPixelColor(3, pixels.Color(255, 255, 75));  // White-ish headlights
        pixels.show(); // Turn off the orange pixels
      }
      lightOn = !lightOn;
      timer = millis();
    }
  }

void left_Pixel() 
{
  static bool lightOn = false;
    static unsigned long timer = millis();

    if ((millis() - timer) > 500)
    {
      if(lightOn == true)
      {
        pixels.clear();
        pixels.setPixelColor(0, pixels.Color(255, 100, 0));   // Orange
        pixels.setPixelColor(1, pixels.Color(75, 0, 0));      // Red
        pixels.setPixelColor(2, pixels.Color(255, 255, 75));  // White
        pixels.setPixelColor(3, pixels.Color(255, 100, 0));   // Orange
        pixels.show();
        }
      else
        /*
        0 = leftback
        1 = rightback
        2 = leftfront
        3 = rightfront
        */
      {
        pixels.clear();
        pixels.setPixelColor(0, pixels.Color(0, 0, 0));      // Red at 60
        pixels.setPixelColor(1, pixels.Color(75, 0, 0));
        pixels.setPixelColor(2, pixels.Color(255, 255, 75));
        pixels.setPixelColor(3, pixels.Color(0, 0, 0));  // White-ish headlights
        pixels.show(); // Turn off the orange pixels
      }
      lightOn = !lightOn;
      timer = millis();
    }
  }