#include <Adafruit_NeoPixel.h>
int pixel;
int color = 0;
Adafruit_NeoPixel matrix(64, 6);

void setup() {
  Serial.begin(9600);
  matrix.begin();

  matrix.setBrightness(25);
  
  

}

void loop() {
  // put your main code here, to run repeatedly:
      char Char = Serial.read();
      if (Char == 'y')
      {
         color = 255;
      }
      else if (Char == 'n')
      {
        color = 0;  
      }
  for(int i = 0; i < 64; i++)
  {
    matrix.setPixelColor(i, matrix.Color(color, color, color));
  }
  matrix.show();
}
