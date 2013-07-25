#include <VirtualWire.h> // On inclue la librairie VirtualWire
#include <DHT11.h>


char *msg = "0"; // Tableau qui contient notre message
int blinkLed = 13;
DHT11 dht11(2); 


#define LED 11

void setup() // Fonction setup()
{
Serial.begin(9600);
  vw_setup(2000);        // Initialisation de la librairie VirtualWire Ã  2400 bauds (maximum de mon module)
  vw_set_tx_pin(3);     // On indique que l'on veut utiliser la pin 10 de l'Arduino pour reÃ§evoir
 pinMode(blinkLed, OUTPUT);     
}



void loop() {

  int err;
  float temp, humi;
  char *json;  
  if((err=dht11.read(humi, temp))==0)
  {
    char tampon[32];
    unsigned int temp1 = (temp - (unsigned int)temp) * 1000;
    unsigned int humi1 = (humi - (unsigned int)humi) * 1000;
    sprintf(tampon,"{'id':1,'t':%0d.%d,'h':%0d.%d}", (unsigned int)temp, temp1,(unsigned int)humi, humi1 ); 
 
    digitalWrite(blinkLed, HIGH);
    Serial.println(tampon);

    Serial.println(strlen(tampon));
    vw_send((uint8_t *)tampon, strlen(tampon)); 
    vw_wait_tx(); 
    digitalWrite(blinkLed, LOW);    
    delay(10000);

  }
  else
  {
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();    
  }






}


