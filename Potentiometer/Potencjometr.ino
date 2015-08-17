void setup() 
{
  Serial.begin(9600); // Inicjalizacja portu szeregowego
  pinMode(5,OUTPUT); // Zielony LED
  pinMode(6,OUTPUT); // Zolty LED
  pinMode(7,OUTPUT); // Czerwony LED
}

void loop() 
{
  int pot = analogRead(A5); // Odczyt z PINU analogowego A5
  if (pot > 10)
  {    digitalWrite(5,HIGH);  }
  else
  {    digitalWrite(5,LOW);  }
  
  if (pot > 500)
  {    digitalWrite(6,HIGH);  }
  else
  {    digitalWrite(6,LOW);  }
  
  if (pot > 1000)
  {    digitalWrite(7,HIGH);  }
    else
  {    digitalWrite(7,LOW);  }
  
  Serial.println(pot); // Wypisanie na porcie wartosci z potencjometru
  delay(10);        // przerwa pomiedzy odczytami
}
