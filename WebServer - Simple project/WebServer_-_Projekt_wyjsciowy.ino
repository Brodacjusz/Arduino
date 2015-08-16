#include <SPI.h>
#include <Ethernet.h>

// MAC ADRES
byte mac[] = {0xEA,0xFE,0xED,0xED,0xAB,0xCD};  
// IP: 192.168.0.100
byte ip[] = {192,168,0,100};    
EthernetServer server(80);
void setup()
{
   Ethernet.begin(mac, ip);
   server.begin();
   Serial.begin(9600);
   Serial.print("Serwer wystartowal z IP");
   Serial.println(Ethernet.localIP());
}

void loop () 
{
   EthernetClient client = server.available();
   if (client) 
   {
     while (client.connected()) 
     {
       if (client.available()) 
	{
           // Wysyla standardowy naglowek HTTP
           client.println("HTTP/1.1 200 OK");
           client.println("Content-Type: text/html");
           client.println("Connection: close");  

	   // Standardowy kod HTML
           client.println("<!DOCTYPE HTML>");
           client.println("<html><head><title>Serwer na Arduino</title></head>");
           client.println("<body><h1>Witaj Swiecie</h1></body></html>");         
           break;
        }
     }
   }
     // konczymy polaczenie
     client.stop();
}
