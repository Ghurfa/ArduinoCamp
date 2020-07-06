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
};
LED light1(3,2,0); // blue
LED light2(6,-2,255); // red
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  Serial.println("Hello, the program is starting");
}

void loop() {
  // put your main code here, to run repeatedly:
 light1.updateBrightness();
 light2.updateBrightness();
 
  if (light1._brightness >= 255)
  {
     Serial.println("Blue light is fully on"); 
  }
  if (light2._brightness >= 255)
  {
     Serial.println("Red light is fully on"); 
  }
  if (light1._brightness <= 0)
  {
     Serial.println("Blue light is fully off"); 
  }
  if (light2._brightness <= 0)
  {
     Serial.println("Red light is fully off"); 
  }
} 
