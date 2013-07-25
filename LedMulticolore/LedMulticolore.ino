

int ledVerte = 5;
int ledJaune = 4;
int ledRouge = 3;

int interrupteur = 2;



// the setup routine runs once when you press reset:
void setup() {                
 
 
  pinMode(ledVerte, OUTPUT);  
  pinMode(ledJaune, OUTPUT);  
  pinMode(ledRouge, OUTPUT); 
  pinMode(interrupteur, INPUT); 

 
  
}

// the loop routine runs over and over again forever:
void loop() {
  int switchState  = digitalRead(interrupteur);
  if (switchState==HIGH){
      digitalWrite(ledVerte, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);               // wait for a second
      digitalWrite(ledVerte, LOW);    // turn the LED off by making the voltage LOW
      delay(1000); 
      
      digitalWrite(ledJaune, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);               // wait for a second
      digitalWrite(ledJaune, LOW);    // turn the LED off by making the voltage LOW
      delay(1000); 
      
      digitalWrite(ledRouge, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);               // wait for a second
      digitalWrite(ledRouge, LOW);    // turn the LED off by making the voltage LOW
      delay(1000); 
  }
}
