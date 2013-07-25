

const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup() {                
 Serial.begin(9600);
       
}

void loop() {
  
  int sensorVal = analogRead(sensorPin);
  //Serial.print("Sensor value");
  float voltage = (sensorVal/1024.0)*5;
  float temp = (voltage-.5)*100;
  
  
  
  Serial.print("sensorVal : "); 
  Serial.println(sensorVal);

  Serial.print("voltage : ");
  Serial.println(voltage);
  
  Serial.print("temp : ");
  Serial.println(temp);


  
}
