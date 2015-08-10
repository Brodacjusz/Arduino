#include "DHT.h"

DHT dht(2, DHT11); // 2 - Digital PIN, DHT11 - typ sensora
float temperatura, wilgotnosc;
void setup() 
{
  Serial.begin(9600);
  dht.begin();
}

void loop() 
{
  delay(2000); // 2 sekundy na każdy pomiar
  wilgotnosc = dht.readHumidity();
  temperatura = dht.readTemperature();
  
  if (wilgotnosc == 0 || temperatura == 0)
  {
    Serial.println("Problem z odczytem z sensora");
  }

  Serial.print("Wilgotnosc: ");
  Serial.print(wilgotnosc);
  Serial.println(" % ");
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" *C ");
  Serial.println("----------------");
}
