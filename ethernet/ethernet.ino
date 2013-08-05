#include <SPI.h>
#include <Ethernet.h>
#include <DHT11.h>
#include <VirtualWire.h> // On inclue la librairie VirtualWire




/* Détails technique de la connexion ethernet */
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = {192,168,1, 177 };
byte gateway[] = {192,168,1, 1 };

EthernetServer server(80);



void setup()
{
    // Configuration de la ethernet shield et du server
  Ethernet.begin(mac, ip);
  server.begin();
 
  // Mise en sortie de la broche avec notre led (par défaut éteinte)
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
}


void loop()
{
  
  EthernetClient client = server.available();  // try to get client

    if (client) {  // got client?
        boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) {   // client data available to read
                char c = client.read(); // read 1 byte (character) from client
                // last line of client request is blank and ends with \n
                // respond to client only after last line received
                if (c == '\n' && currentLineIsBlank) {
                    // send a standard http response header
                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-Type: application/json");
                    client.println("Connection: close");
                    client.println();
                    // send web page
                    
                    client.println("{");
                    client.println(" \"temp\" : 25, ");  
                    client.println(" \"humidite\" : 30");
                    client.println("}");
                    break;
                }
                // every line of text received from the client ends with \r\n
                if (c == '\n') {
                    // last character on line of received text
                    // starting new line with next character read
                    currentLineIsBlank = true;
                } 
                else if (c != '\r') {
                    // a text character was received from client
                    currentLineIsBlank = false;
                }
            } // end if (client.available())
        } // end while (client.connected())
        delay(1);      // give the web browser time to receive the data
        client.stop(); // close the connection
    } // end if (client)
  
  
}
