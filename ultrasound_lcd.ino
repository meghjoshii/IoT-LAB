#include<LiquidCrystal.h>

LiquidCrystal lcd{8,9,4,5,6,7};
int trigPin=2;
int echoPin=3;
int buzzer=13;

 long microsecondsToInches(long microseconds);
 long microsecondsToCentimeters(long microseconds);
 
void setup() {
  // put your setup code here, to run once:
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 pinMode(buzzer,OUTPUT);
 Serial.begin(9600);
 lcd.begin(16,2);
 lcd.setCursor(0,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration,inches,cm;
  lcd.setCursor(0,1);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  duration=pulseIn(echoPin,HIGH);
  inches= microsecondsToInches(duration);
  cm=microsecondsToCentimeters(duration);
  
  lcd.print("Inches:");
  lcd.println(inches);
  lcd.print("Centimeters");
  lcd.println(cm);

  if(cm<5)
  {
      digitalWrite(buzzer,HIGH);
    }

   else
   {
    digitalWrite(buzzer,HIGH);
    }
   
  delay(1000);
}
   long microsecondsToInches(long microseconds)
{
    return microseconds/74/2;
  }

   long microsecondsToCentimeters(long microseconds)
{
    return microseconds/29/2;
  }
