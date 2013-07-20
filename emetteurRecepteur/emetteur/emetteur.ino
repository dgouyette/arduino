#include <VirtualWire.h> // On inclue la librairie VirtualWire

char *msg = "0"; // Tableau qui contient notre message
int blinkLed = 13;

#define LED 11

void setup() // Fonction setup()
{
      Serial.begin(2400);
      Serial.println("setup");
      vw_setup(2400);        // Initialisation de la librairie VirtualWire Ã  2400 bauds (maximum de mon module)
      vw_set_tx_pin(3);     // On indique que l'on veut utiliser la pin 10 de l'Arduino pour reÃ§evoir
      pinMode(blinkLed, OUTPUT);     

}



void loop() {
  digitalWrite(blinkLed, HIGH);
  delay(1000);    
   vw_send((uint8_t *)msg, strlen(msg)); 
   vw_wait_tx(); 
    msg[0]++;  
  Serial.println("EM : ");
  Serial.println(msg[0]);
   //Serial.println("ok");

 digitalWrite(blinkLed, LOW);    
  delay(1000);               
}
