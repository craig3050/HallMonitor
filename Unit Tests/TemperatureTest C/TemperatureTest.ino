// Initialise global pin variables
int tempPin = A5;

void setup()
{  
  Serial.begin(57600);  //Start the serial connection with the computer
}

void loop()
{
  float reading = tempsensor();  
  Serial.print(reading);
  delay(3000);
}  
 
float tempsensor()
{
   //getting the voltage reading from the temperature sensor
 int reading = analogRead(tempPin);  
 
 // converting that reading to voltage, for 3.3v arduino use 3.3
 float voltage = reading * 5.0;
 voltage /= 1024.0; 
 
 float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
 return temperatureC;
} 
 

  
