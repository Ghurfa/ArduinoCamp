#include <Adafruit_NeoPixel.h>
int redBallPixel;

Adafruit_NeoPixel matrix(64, 6);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9,INPUT_PULLUP);
  matrix.begin();
  matrix.setBrightness(10);
}
int buttonValue;
int greenBallPixel = 16;
int greenBallDirection = 1;
void loop() {
  // put your main code here, to run repeatedly:
  buttonValue = digitalRead(9);
  Serial.println(buttonValue);
  delay(100);
  for(int i = 0; i < 64; i++)
  {
    matrix.setPixelColor(i, matrix.Color(0, 255, 255)); 
  }
  redBallPixel = 51;
  if(buttonValue == 0)
  {
    for(int i = 0; i < 4; i++)
    {
      redBallPixel -= 8;
      matrix.setPixelColor(greenBallPixel, matrix.Color(0, 255, 0));
      matrix.setPixelColor(greenBallPixel + 1, matrix.Color(0, 255, 0));
      matrix.setPixelColor(greenBallPixel + 8, matrix.Color(0, 255, 0));
      matrix.setPixelColor(greenBallPixel + 9, matrix.Color(0, 255, 0));
      matrix.setPixelColor(redBallPixel, matrix.Color(255, 0, 0));
      matrix.setPixelColor(redBallPixel + 1, matrix.Color(255, 0, 0));
      matrix.setPixelColor(redBallPixel + 8, matrix.Color(255, 0, 0));
      matrix.setPixelColor(redBallPixel + 9, matrix.Color(255, 0, 0));
      matrix.setPixelColor(redBallPixel + 16, matrix.Color(0, 255, 255));
      matrix.setPixelColor(redBallPixel + 17, matrix.Color(0, 255, 255));
      matrix.show();
      delay(100);
    }
    for(int i = 0; i < 4; i++)
    {
      redBallPixel += 8;
      matrix.setPixelColor(redBallPixel - 7, matrix.Color(0, 255, 255));
      matrix.setPixelColor(greenBallPixel, matrix.Color(0, 255, 0));
      matrix.setPixelColor(greenBallPixel + 1, matrix.Color(0, 255, 0));
      matrix.setPixelColor(greenBallPixel + 8, matrix.Color(0, 255, 0));
      matrix.setPixelColor(greenBallPixel + 9, matrix.Color(0, 255, 0));
      matrix.setPixelColor(redBallPixel, matrix.Color(255, 0, 0));
      matrix.setPixelColor(redBallPixel + 1, matrix.Color(255, 0, 0));
      matrix.setPixelColor(redBallPixel + 8, matrix.Color(255, 0, 0));
      matrix.setPixelColor(redBallPixel + 9, matrix.Color(255, 0, 0));
      matrix.setPixelColor(redBallPixel - 8, matrix.Color(0, 255, 255));
      matrix.show();
      delay(100);
    } 
  }
  else{
    greenBallPixel += greenBallDirection;
    matrix.setPixelColor(redBallPixel, matrix.Color(255, 0, 0));
    matrix.setPixelColor(redBallPixel + 1, matrix.Color(255, 0, 0));
    matrix.setPixelColor(redBallPixel + 8, matrix.Color(255, 0, 0));
    matrix.setPixelColor(redBallPixel + 9, matrix.Color(255, 0, 0));
    matrix.setPixelColor(greenBallPixel, matrix.Color(0, 255, 0));
    matrix.setPixelColor(greenBallPixel + 1, matrix.Color(0, 255, 0));
    matrix.setPixelColor(greenBallPixel + 8, matrix.Color(0, 255, 0));
    matrix.setPixelColor(greenBallPixel + 9, matrix.Color(0, 255, 0));
    if (greenBallPixel == 16 || greenBallPixel == 22)
    {
     greenBallDirection *= -1; 
    }
    matrix.show();
  }
}
