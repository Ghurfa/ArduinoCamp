class RgbLed
{
  private:
  
     int _pin1;
     int _pin2;
     int _pin3;
  
  public:
  
    RgbLed(int pin1, int pin2, int pin3)
    {
      _pin1 = pin1;
      _pin2 = pin2;
      _pin3 = pin3;
      pinMode(_pin1, OUTPUT);
      pinMode(_pin2, OUTPUT);
      pinMode(_pin3, OUTPUT);
      
      digitalWrite(_pin1, HIGH);
      digitalWrite(_pin2, HIGH);
      digitalWrite(_pin3, HIGH);
      
    }
    void updateColor (int pin1Value, int pin2Value, int pin3Value, int wait)
    {
      analogWrite(_pin1, pin1Value);
      analogWrite(_pin2, pin2Value);
      analogWrite(_pin3, pin3Value);
      delay(wait);
    }
    void flash (int pin1Value, int pin2Value, int pin3Value)
    {
      updateColor(pin1Value, pin2Value, pin3Value, 500);
      updateColor(255, 255, 255,100);
    }
};
RgbLed rgbLed(3, 6, 9);
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 255; i > 0; i--)
  {
   rgbLed.updateColor(255,255, i,10); 
  }
  for (int f = 0; f < 255; f++)
  {
   rgbLed.updateColor(255, 255,f,10);
  }
  for (int g = 0; g < 3; g++)
  {
    rgbLed.flash(255,0,255); 
  }
  for (int y = 0; y < 2; y++)
  {
   rgbLed.flash(255,0,0); 
  }
    for (int r = 255; r > 0; r--)
  {
   rgbLed.updateColor(r,255,r,10);
  }
  for (int r = 0; r < 255; r++)
  {
   rgbLed.updateColor(r,255,r,10); 
  }
}
/*
fade red in and out, blink green 3 times, blink yellow 2 times, fade pink in and out;
*/
