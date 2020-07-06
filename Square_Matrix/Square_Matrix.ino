#include <Adafruit_NeoPixel.h>
int pixel;

Adafruit_NeoPixel matrix(64, 6);

void setup() {
  
  matrix.begin();

  matrix.setBrightness(25);
  
  randomSeed(analogRead(0));
  pixel = 0;
  for(int i = 0; i < 64; i++)
  {
    int red = 255;
    int green = 255;
    int blue = 255; 
    matrix.setPixelColor(i, matrix.Color(red, green, blue));
  }
  
  pixel = 8;
  for(int i = 0; i < 6; i++)
  {
      int red = 0;
      int green = 0;
      int blue = 0;
    for(int d = 0; d < 6; d++) 
    {
       pixel++;
       matrix.setPixelColor(pixel, matrix.Color(red, green, blue));
    }
     pixel += 2;
  }
 
  
  matrix.show();

}

void loop() {
  // put your main code here, to run repeatedly:

}
