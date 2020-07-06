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
int playChoice;
int stage = 1; // 1 waiting to type, 2  analyzing, 3 outcome
int comBeatChoice;
int playBeatChoice;
int outcome;
int comChoice;
int wins = 0;
int losses = 0;
int ties = 0;
RgbLed rgbLed(3,6,9);
void setup() {
 randomSeed(analogRead(0));
 Serial.begin(9600);
 Serial.println("Type R for rock");
 Serial.println("Type P for paper");    
 Serial.println("Type S for scissors");
} //1 - 3
void loop() {
  // put your main code here, to run repeatedly:
  if (stage == 1){
      comChoice = random(1, 4);
      char Char = Serial.read();
      if (Char == 'r')
      {
         playChoice = 1;
         stage = 2;
      }
      else if (Char == 'p')
      {
         playChoice = 2;
         stage = 2;
      }
      else if (Char == 's')
      {
        playChoice = 3;
        stage = 2;
      }
  }
  else if (stage == 2)
  {
     comBeatChoice = comChoice - 1;
     if (comBeatChoice < 1)
     {
       comBeatChoice += 3;
     }
     playBeatChoice = playChoice - 1;
     if (playBeatChoice < 1)
     {
       playBeatChoice += 3;
     }
     if (playBeatChoice == comChoice)
     {
        outcome = 1;//win
     }
     else if(comBeatChoice == playChoice)
     {
       outcome = 2; //lose
     }
     else
     {
      outcome = 3;//tie 
     }
     stage = 3;
  }
  else if (stage == 3)
  {
    if (playChoice == 1)
    {
      Serial.println("You chose rock");
    }
    else if (playChoice == 2)
    {
      Serial.println("You chose paper");
    }
    else if (playChoice == 3)
    {
      Serial.println("You chose scissors");
    }
    if (comChoice == 1)
    {
      Serial.println("The computer chose rock");
    }
    else if (comChoice == 2)
    {
      Serial.println("The computer chose paper");
    }
    else if (comChoice == 3)
    {
      Serial.println("The computer chose scissors");
    }
    if (outcome == 1)
    {
      Serial.println("----------You win----------");
      rgbLed.updateColor(255,0,255,10);
      wins++;
    }
    else if (outcome == 2)
    {
      Serial.println("----------You lose----------");
      rgbLed.updateColor(0,255,255,10);
      losses++;
    }
    else if (outcome == 3)
    {
      Serial.println("----------Tie----------");
      rgbLed.updateColor(255,255,0,10);
      ties++;
    }
    
    Serial.println("");
    
    Serial.print("Wins: ");
    Serial.println(wins);
    Serial.print("Losses: ");
    Serial.println(losses);
    Serial.print("Ties: ");
    Serial.println(ties);
    Serial.println("");
    Serial.println("Type R for rock");
    Serial.println("Type P for paper");    
    Serial.println("Type S for scissors");
    stage = 1;
  }
  
}
