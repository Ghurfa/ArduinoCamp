#include <Adafruit_NeoPixel.h>
int ballPixel = 27;
int ballSpx = 1;
int ballSpy = 1;

Adafruit_NeoPixel matrix(64, 6);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9,INPUT_PULLUP);
  matrix.begin();
  matrix.setBrightness(10);
}
int buttonValue;
void loop() {
  // put your main code here, to run repeatedly:
  buttonValue = digitalRead(9);
  for (int i = 0; i < 64; i++)//fill with white
  {
    matrix.setPixelColor(i,matrix.Color(255, 255, 255)); 
  }
  
  ballPixel += ballSpx; //move the ball
  ballPixel += (ballSpy * 8);
  
  matrix.setPixelColor(ballPixel, matrix.Color(0, 0, 255)); //draw the ball
  matrix.setPixelColor(ballPixel + 1, matrix.Color(0, 0, 255)); 
  matrix.setPixelColor(ballPixel + 8, matrix.Color(0, 0, 255)); 
  matrix.setPixelColor(ballPixel + 9, matrix.Color(0, 0, 255)); 
  
  if(ballPixel == 0 || ballPixel == 8 || ballPixel == 16 || ballPixel == 24 || ballPixel == 32 || ballPixel == 40 || ballPixel == 48 || ballPixel == 56) // check for intersections with walls
  {
    ballSpx = 1;
  }
  if(ballPixel == 0 || ballPixel == 1 || ballPixel == 2 || ballPixel == 3 || ballPixel == 4 || ballPixel == 5 || ballPixel == 6 || ballPixel == 7) // check for intersections with walls
  {
    ballSpy = 1;
  }
  if(ballPixel + 1 == 7 || ballPixel + 1 == 15 || ballPixel + 1 == 23 || ballPixel + 1 == 31 || ballPixel + 1 == 39 || ballPixel + 1 == 47 || ballPixel + 1 == 55 || ballPixel + 1 == 63) // check for intersections with walls
  {
    ballSpx = -1;
  }
  if(ballPixel + 8 == 56 || ballPixel + 8 == 57 || ballPixel + 8 == 58 || ballPixel + 8 == 59 || ballPixel + 8 == 60 || ballPixel + 8 == 61 || ballPixel + 8 == 62 || ballPixel + 8 == 63) // check for intersections with walls
  {
    ballSpy = -1;
  }
    matrix.show();
  delay(500);
}
