#include <SPI.h>
#include <Ethernet.h>
#include <DHT11.h>
#include <VirtualWire.h> // On inclue la librairie VirtualWire




/* Détails technique de la connexion ethernet */
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = {
  192,168,1, 177 };

EthernetServer server(80);

float temp, humi=0;
long lastMesure;




void setup()
{

  Serial.begin(9600); 
  vw_setup(2000);      // Initialisation de la librairie VirtualWire
  vw_set_rx_pin(6);   // On indique que l'on veut utiliser la broche 2 pour reÃ§evoir
  vw_rx_start();      // Activation de la partie rÃ©ception de la librairie VirtualWire


  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());

  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
  Serial.println("SETUP");




}




void loop()
{

  EthernetClient client = server.available();  // try to get client
  getMessage();
  if (client) {
    httpServer(client);
  }
  else {
  }



}

void getMessage(){
  // Serial.println("else");
  if (vw_have_message()) // Si on a un message dans le buffer
  {     
    Serial.println("vw_have_message");
    byte buf[VW_MAX_MESSAGE_LEN]; // Tableau qui va contenir le message recu (de taille maximum VW_MAX_MESSAGE_LEN)
    byte buflen = VW_MAX_MESSAGE_LEN; // Taille maximum du buffer

    //  Serial.println("hava message");   
    if (vw_get_message(buf, &buflen)) // Alors on rÃ©cupÃ¨re ce message qu'il soit entier ou pas
    {
      Serial.println("vw_get_message");
    }
  }
}




void httpServer(EthernetClient client){

  Serial.println("got client");

  boolean currentLineIsBlank = true;
  while (client.connected()) {
    if (client.available()) {   // client data available to read
      char c = client.read(); // read 1 byte (character) from client
      // Serial.write(c);

      // last line of client request is blank and ends with \n
      // respond to client only after last line received
      if (c == '\n' && currentLineIsBlank) {

        // send a standard http response header
        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: application/json");
        client.println("Connection: close");
        client.println();

        client.println("{");
        client.print(" \"temp\" : ");
        client.print(temp);
        client.println(",");
        client.print(" \"humidite\" :");
        client.print(humi);
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

}






























