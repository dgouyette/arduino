#include <VirtualWire.h> // On inclue la librairie VirtualWire
#include <SPI.h>
#include <Ethernet.h>
#include <DHT11.h>

long lastMesure;
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,20);   //arduino ip address
IPAddress server(88,191,121,181); 
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

EthernetClient client;

String connectToServer(){
  //connect to the server

  Serial.println("connecting...");

  //port 80 is typical of a www page
  if (client.connect(server, 80)) {
    Serial.println("connected");
    client.print("GET ");
    client.println("/aaaaaaaaa");
    client.println();

    //Connected - Read the page
    //return readPage(); //go and read the output

  }
  else{
    Serial.println("connection failed");
    return "connection failed";
  }

}



void setup()
{
  Serial.begin(9600); 
  Ethernet.begin(mac, ip, gateway, gateway, subnet);
  
  connectToServer();

  vw_setup(2000);      // Initialisation de la librairie VirtualWire Ã  2400 bauds  (maximum de mon module)
  vw_set_rx_pin(11);   // On indique que l'on veut utiliser la broche 2 pour reÃ§evoir
  vw_rx_start();      // Activation de la partie rÃ©ception de la librairie VirtualWire

 
}

void loop()
{
  byte buf[VW_MAX_MESSAGE_LEN]; // Tableau qui va contenir le message recu (de taille maximum VW_MAX_MESSAGE_LEN)
  byte buflen = VW_MAX_MESSAGE_LEN; // Taille maximum du buffer

  //Serial.println("Else");
  if (vw_have_message()) // Si on a un message dans le buffer
  {        
    //  Serial.println("hava message");   
    if (vw_get_message(buf, &buflen)) // Alors on rÃ©cupÃ¨re ce message qu'il soit entier ou pas
    {
      int i;
      Serial.println("RX : ");
      for (i = 0; i < buflen; i++) // On affiche tous ce que l'on a
        Serial.write(buf[i]);
      Serial.println(""); // Une fois qu'il est entier, on peut ajouter un retour Ã  la ligne.
    }
  }



}






































