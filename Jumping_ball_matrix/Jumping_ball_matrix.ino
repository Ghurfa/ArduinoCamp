#include <Adafruit_NeoPixel.h>
int pixel;

Adafruit_NeoPixel matrix(64, 6);

void setup() {
  Serial.begin(9600);
  matrix.begin();

  matrix.setBrightness(25);
  for(int i = 0; i < 64; i++)//empty
  {
    matrix.setPixelColor(i, matrix.Color(0, 255, 255));
  }
  for(int i = 56; i < 64; i++)
  {
    matrix.setPixelColor(i, matrix.Color(255, 75, 0));
  }
}
void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available())
 {
  for(int i = 0; i < 64; i++)//empty
  {
    matrix.setPixelColor(i, matrix.Color(0, 255, 255));
  }
  for(int i = 56; i < 64; i++)
  {
    matrix.setPixelColor(i, matrix.Color(255, 75, 0));
  }
      pixel = 43;
      matrix.setPixelColor(pixel, matrix.Color(255, 255, 255));
      matrix.setPixelColor(pixel + 1, matrix.Color(255, 255, 255));
      matrix.setPixelColor(pixel + 8, matrix.Color(255, 255, 255));
      matrix.setPixelColor(pixel + 9, matrix.Color(255, 255, 255));
  char Char = Serial.read();
  if(Char == 'p')
  {
    pixel = 43;
    for(int i = 0; i < 4; i++)
    {
      pixel -= 8;
      matrix.setPixelColor(pixel, matrix.Color(255, 255, 255));
      matrix.setPixelColor(pixel + 1, matrix.Color(255, 255, 255));
      matrix.setPixelColor(pixel + 8, matrix.Color(255, 255, 255));
      matrix.setPixelColor(pixel + 9, matrix.Color(255, 255, 255));
      matrix.setPixelColor(pixel + 16, matrix.Color(0, 255, 255));
      matrix.setPixelColor(pixel + 17, matrix.Color(0, 255, 255));
      matrix.show();
      delay(100);
    }
    for(int i = 0; i < 4; i++)
    {
      pixel += 8;
      matrix.setPixelColor(pixel, matrix.Color(255, 255, 255));
      matrix.setPixelColor(pixel + 1, matrix.Color(255, 255, 255));
      matrix.setPixelColor(pixel + 8, matrix.Color(255, 255, 255));
      matrix.setPixelColor(pixel + 9, matrix.Color(255, 255, 255));
      matrix.setPixelColor(pixel - 8, matrix.Color(0, 255, 255));
      matrix.setPixelColor(pixel - 7, matrix.Color(0, 255, 255));
      matrix.show();
      delay(100);
    }
    matrix.show();
  }


  
 }
  matrix.show();
}
