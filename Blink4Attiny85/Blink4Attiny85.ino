int led = 0;
char *msg = "0"; // Tableau qui contient notre message
#include <VirtualWire.h> // On inclue la librairie VirtualWire


void setup() {   
  pinMode(led, OUTPUT);
   vw_setup(2400);        // Initialisation de la librairie VirtualWire Ã  2400 bauds (maximum de mon module)
   vw_set_tx_pin(3);     // On indique que l'on veut utiliser la pin 10 de l'Arduino pour reÃ§evoir  
}

void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);
  vw_send((uint8_t *)msg, strlen(msg)); 
   vw_wait_tx(); 
    msg[0]++;  
  
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(200);               // wait for a second
}
