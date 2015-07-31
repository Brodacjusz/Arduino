///////////////////////////////////
//
// Author: Adrian Majchrzak
// http://viewmax.eu
// Toggle button - Arduino tutorial, reading states from analog ports.
// Check my website for schematic. Use serial monitor and type 1 or 2
// for enable LED's or the same keys for disable LED's
//
// Date: 2015.07.31
//
///////////////////////////////////

int yellow, green;

void setup() 
{
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  yellow = analogRead(A3); // yellow LED
  green  = analogRead(A4); // green LED
    
  switch(Serial.read())
  {
    case 49: //keyboard key code for button "1"
    {
      if (green == 0)
      {
        digitalWrite(3,HIGH);
        Serial.println("Green LED is ON");
      }
      else
      {
        digitalWrite(3,LOW);
        Serial.println("Green LED is OFF");
      }  
      break;
    }   
    case 50: //keyboard key code for button "2"
    {
      if (yellow == 0)
      {
        digitalWrite(4,HIGH);
        Serial.println("Yellow LED is ON");
      }
      else
      {
        digitalWrite(4,LOW);
        Serial.println("Yellow LED is OFF");
      }
      break;
    } 
  }  
  delay(10);
}
