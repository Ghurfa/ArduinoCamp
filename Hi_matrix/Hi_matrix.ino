#include <Adafruit_NeoPixel.h>
int pixel;

Adafruit_NeoPixel matrix(64, 6);

int pixels[64];

void setup() {
  
  matrix.begin();

  matrix.setBrightness(25);
  for(int i = 0; i < 64; i++)
  {
    pixels[i] = 0;
  }
  pixel = 16;
  for(int i = 0; i < 4; i++)
  {
     pixels[pixel] = 255;
     pixel += 8;
  }
  pixel = 19;
  for(int i = 0; i < 4; i++)
  {
     pixels[pixel] = 255;
     pixel += 8;
  }
  pixels[25] = 255;
  pixels[34] = 255;
  pixel = 21;
  for(int i = 0; i < 4; i++)
  {
     pixels[pixel] = 255;
     pixel += 8;
  }
  pixel = 23;
  for(int i = 0; i < 4; i++)
  {
     pixels[pixel] = 255;
     pixel += 8;
  }
  pixels[22] = 255;
  pixels[46] = 255;
}

void loop() {
  // put your main code here, to run repeatedly:
  
   int lastRowPixels[7];
      lastRowPixels[0] = pixels[7];
      lastRowPixels[1] = pixels[15];
      lastRowPixels[2] = pixels[23];
      lastRowPixels[3] = pixels[31];
      lastRowPixels[4] = pixels[39];
      lastRowPixels[5] = pixels[47];
      lastRowPixels[6] = pixels[55];
      lastRowPixels[7] = pixels[63];
  
  //create a firstRowPixels
  
  
  pixel = 7;  
  
  
  for (int i = 0; i < 8; i++)
  {
    for (int d = 0; d < 7; d++)
    {
      pixels[pixel] = pixels[pixel - 1];
      pixel--;
    }
    pixel += 14;
  }
  //set the firstRowPixels = lastRowPixels
  
  pixels[0] = lastRowPixels[0];
  pixels[8] = lastRowPixels[1];
  pixels[16] = lastRowPixels[2];
  pixels[24] = lastRowPixels[3];
  pixels[32] = lastRowPixels[4];
  pixels[40] = lastRowPixels[5];
  pixels[48] = lastRowPixels[6];
  pixels[56] = lastRowPixels[7];
  
 
  for(int i = 0; i < 64; i++)
  {
      matrix.setPixelColor(i, matrix.Color(pixels[i], pixels[i], pixels[i]));
  }
  
  
  matrix.show();
  delay(8000);
}
