class LED
{
  private:
  
     int _pin;
     int _brightness;
     int _fadespeed;
  
  public:
  
    LED(int pin, int fadespeed)
    {
      _pin = pin;
      _fadespeed = fadespeed;
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
};
LED pin1(3, 2);
LED pin2(5, 2);
LED pin3(6, 2);
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  pin1.updateBrightness();
  pin2.updateBrightness();
  pin3.updateBrightness();
}

  
