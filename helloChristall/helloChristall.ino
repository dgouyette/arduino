// include the library code:
#include <LiquidCrystal.h>

const int sensorPin = A0;
const float baselineTemp = 20.0;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  // Print a message to the LCD.
  //lcd.print("cestpasdur.com");
}

void loop() {
  
  static int temperatures [10];
  int total = 0.0;
  int i=0;
  for (i = 0; i < 10; i = i + 1) {
    int sensorVal = analogRead(sensorPin);
    float voltage = (sensorVal/1024.0)*5;
    float temp = (voltage-.5)*100;
    total = total+temp;
  }
  delay(10000);  
  lcd.begin(16, 2); 
  lcd.print("Temp = ");
  lcd.print(total/10.0);
  lcd.print((char)223);
  lcd.print("C");
  
  
 


}
