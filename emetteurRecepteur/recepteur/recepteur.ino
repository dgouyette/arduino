#include <VirtualWire.h> // On inclue la librairie VirtualWire


int blinkLed = 13;

void setup()
{
    Serial.begin(9600); // Initialisation du port sÃ©rie pour avoir un retour sur le serial monitor

    vw_setup(2000);	// Initialisation de la librairie VirtualWire Ã  2400 bauds  (maximum de mon module)
    vw_set_rx_pin(11);   // On indique que l'on veut utiliser la broche 2 pour reÃ§evoir
    vw_rx_start();      // Activation de la partie rÃ©ception de la librairie VirtualWire
    pinMode(blinkLed, OUTPUT);     

}

void loop()
{
  
  byte buf[VW_MAX_MESSAGE_LEN]; // Tableau qui va contenir le message recu (de taille maximum VW_MAX_MESSAGE_LEN)
  byte buflen = VW_MAX_MESSAGE_LEN; // Taille maximum du buffer


    if (vw_have_message()) // Si on a un message dans le buffer
    {

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
