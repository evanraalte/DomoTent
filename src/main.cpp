#include <Arduino.h>
#include "Adafruit_NeoPixel.h"

#define PIN 21
 
// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);
 
void setup()
{
pixels.begin(); // This initializes the NeoPixel library.
}
 
void loop()
{
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        for (int l = 0; l < 255; l++){
          pixels.setPixelColor(0, pixels.Color(i * l, j * l, k * l)); 
          pixels.setPixelColor(1, pixels.Color(i * l, j * l, k * l)); 
          pixels.setPixelColor(2, pixels.Color(i * l, j * l, k * l)); 
          pixels.setPixelColor(3, pixels.Color(i * l, j * l, k * l)); 
          pixels.setPixelColor(4, pixels.Color(i * l, j * l, k * l)); 
          pixels.setPixelColor(5, pixels.Color(i * l, j * l, k * l)); 
          pixels.setPixelColor(6, pixels.Color(i * l, j * l, k * l)); 
          pixels.setPixelColor(7, pixels.Color(i * l, j * l, k * l)); 
          pixels.show(); // This sends the updated pixel color to the hardware.
          delay(20); // Delay for a period of time (in milliseconds).
        }
      }
    }
  }
}
