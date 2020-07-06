class LED
{
  private:
     int _pin;
     int _fadespeed;
  public:
    int _brightness;
    LED(int pin, int fadespeed, int brightness)
    {
      _pin = pin;
      _fadespeed = fadespeed;
      _brightness = brightness;
      pinMode(_pin, OUTPUT);
    }
    void On()
    {
      digitalWrite(_pin, HIGH);
    }
    void Off()
    {
      digitalWrite(_pin, LOW);
    }
    void flash(int onTime, int offTime)
    {
        On();
        delay (onTime);
        Off();
        delay (offTime);
    }
    void updateBrightness()
    {
         _brightness += _fadespeed;
         if (_brightness <= 0 || _brightness >= 255)
         {
             _fadespeed *= -1;
         }
         analogWrite (_pin, _brightness);
         delay (10);     
    }
     void fadein()
    {
      
       for (int i = 0; i < 255; i++)
       {
         _brightness -= _fadespeed;
         analogWrite (_pin, _brightness);
         delay (10);     
       }
    }
    void fadeout()
    {
       for (int i = 0; i < 255; i++)
       {
         _brightness += _fadespeed;
         analogWrite (_pin, _brightness);
         delay (10);     
       }
    }
};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
LED reLight(3,1,0);
LED blueLight (6,1,0);
void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    char character = Serial.read();
    if (character == '1')
    {
       blueLight.On();
       redLight.Off();
       Serial.println("Red light is off");
       Serial.println("Blue light is on");
    }
    if (character == '2')
    {
       redLight.On();
       blueLight.Off();
       Serial.println("Red light is on");
       Serial.println("Blue light is off");
    }
    if (character == '3')
    {
      blueLight._brightness = 255;
      redLight._brightness = 0;
      Serial.println("Red light is fading in");
      Serial.println("Blue light is fading out");      
      blueLight.fadeout();
      redLight.fadein();

    }
    if (character == '4')
    {
      blueLight._brightness = 0;
      redLight._brightness = 255;
      Serial.println("Red light is fading out");
      Serial.println("Blue light is fading in");      
      redLight.fadeout();
      blueLight.fadein();

    }
  }
}
