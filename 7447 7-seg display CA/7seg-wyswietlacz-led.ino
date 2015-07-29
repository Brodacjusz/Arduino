///////////////////////////////////
//
// Author: Adrian Majchrzak
// http://viewmax.eu
// Using LED 7-segment display with TTL 7447 decoders/drivers
// CODE: BCD
//
// Date: 2015.07.27
//
///////////////////////////////////

void setup() 
{
  pinMode(10, OUTPUT); // A - PIN 7
  pinMode(11, OUTPUT); // B - PIN 1
  pinMode(12, OUTPUT); // C - PIN 2
  pinMode(13, OUTPUT); // D - PIN 6
}

void set_BCD(int number) //BCD code for 7447 7-seg display
{
  switch (number)
  {
    case 0:
      digitalWrite(10, LOW);
      digitalWrite(11, LOW); 
      digitalWrite(12, LOW); 
      digitalWrite(13, LOW); 
      break;
    case 1:
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW); 
      digitalWrite(12, LOW); 
      digitalWrite(13, LOW);
      break;
    case 2:
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH); 
      digitalWrite(12, LOW); 
      digitalWrite(13, LOW);
      break;
    case 3:
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH); 
      digitalWrite(12, LOW); 
      digitalWrite(13, LOW);
      break;
    case 4:
      digitalWrite(10, LOW);
      digitalWrite(11, LOW); 
      digitalWrite(12, HIGH); 
      digitalWrite(13, LOW);
      break;  
    case 5:
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW); 
      digitalWrite(12, HIGH); 
      digitalWrite(13, LOW);
      break;
    case 6:
      digitalWrite(10, LOW);
      digitalWrite(11, HIGH); 
      digitalWrite(12, HIGH); 
      digitalWrite(13, LOW);
      break;
    case 7:
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH); 
      digitalWrite(12, HIGH); 
      digitalWrite(13, LOW);
      break;
    case 8:
      digitalWrite(10, LOW);
      digitalWrite(11, LOW); 
      digitalWrite(12, LOW); 
      digitalWrite(13, HIGH);
      break;
    case 9:
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW); 
      digitalWrite(12, LOW); 
      digitalWrite(13, HIGH);   
      break;  
    case 10:
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW); 
      digitalWrite(12, HIGH); 
      digitalWrite(13, LOW);   
      break; 
    case 11:
      digitalWrite(10, HIGH);
      digitalWrite(11, LOW); 
      digitalWrite(12, HIGH); 
      digitalWrite(13, HIGH);   
      break; 
    case 12:
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH); 
      digitalWrite(12, LOW); 
      digitalWrite(13, LOW);   
      break; 
    case 13:
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH); 
      digitalWrite(12, LOW); 
      digitalWrite(13, HIGH);   
      break; 
    case 14:
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH); 
      digitalWrite(12, HIGH); 
      digitalWrite(13, LOW);   
      break; 
    case 15:
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH); 
      digitalWrite(12, HIGH); 
      digitalWrite(13, HIGH);   
      break; 
  }
}

void loop() 
{
  int i = 0; //set loop for start from 0
  for (i=0; i <= 9; i++)
  {
    set_BCD(i); // set number 0 to 9
    delay(1000);
    if (i == 9) // skip to 15 - clear display
    {
      set_BCD(15);
      delay(1000); 
    }
  }
}
