class LED
{
  private:
  
     int _pin;
     int _fadespeed;
  
  public:
    int _brightness;
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
         delay (10);     ----
    }
};
LED light(3, 2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  light.updateBrightness();
  Serial.println(light._brightness);
  delay(30);
}
