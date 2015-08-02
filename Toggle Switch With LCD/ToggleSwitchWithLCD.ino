///////////////////////////////////
//
// Author: Adrian Majchrzak
// http://viewmax.eu
// Toggle button - Arduino tutorial, reading states from analog ports.
// Check my website for schematic. Use serial monitor and type 1 or 2
// for enable LED's or the same keys for disable LED's. Also the same 
// information you should see on LCD 16x2 HD44780
//
// Date: 2015.08.02
//
///////////////////////////////////
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int yellow, green;

void setup() 
{
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.write("Toggle Switch by");
  lcd.setCursor(0,1);
  lcd.write("Adrian Majchrzak");
  Serial.begin(9600);
}

void loop() 
{
  yellow = analogRead(A3); // yellow LED
  green  = analogRead(A4); // green LED
  lcd.display();
  
  switch(Serial.read())
  {
    case 49: //keyboard key code for button "1"
    {
      if (green == 0)
      {
        digitalWrite(7,HIGH);
        Serial.println("Green LED is: ON");
        lcd.setCursor(0,0);
        lcd.write("Green is:  ON    ");
      }
      else
      {
        digitalWrite(7,LOW);
        Serial.println("Green LED is: OFF");
        lcd.setCursor(0,0);
        lcd.write("Green is:  OFF   ");
      }  
      break;
    }   
    case 50: //keyboard key code for button "2"
    {
      if (yellow == 0)
      {
        digitalWrite(8,HIGH);
        lcd.setCursor(0,1);
        lcd.write("Yellow is: ON    ");
        Serial.println("Yellow LED is: ON");
      }
      else
      {
        digitalWrite(8,LOW);
        lcd.setCursor(0,1);
        lcd.write("Yellow is: OFF   ");
        Serial.println("Yellow LED is: OFF");
      }
      break;
    } 
  }  
  delay(10);
}
