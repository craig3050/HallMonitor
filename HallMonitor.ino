
//Setup the pin assignments
  int pirpin = 2;
  int temppin = A5;
  int battmonitorpin = A4;
  int ledoutpin = 3;
  int ldrpin = A3;

//Initial setup of programme perameters
void setup()
{
//Start the serial connection with the computer
  Serial.begin(9600);  

//Setup pins as inputs or outputs
  pinMode(pirpin, INPUT);
  pinMode(temppin, INPUT);
  pinMode(battmonitorpin, INPUT);
  pinMode(ledoutpin, OUTPUT);
  pinMode(ldrpin, INPUT);

}

void loop()
{
  
  
  
  
  
}

int tempsensor()
{
// read the voltage from the temperature sensor
  int reading = analogRead(temppin);

//converting reading to voltage
  float voltage = reading * 3.3;
  voltage /= 1024.0;

//convert to a temperature degC
  float result = (voltage - 0.5) * 100;
  return result;
}

int ldrread()
{
  //read photocell and if lower than a threshold return HIGH, otherwise LOW
  int ldrreading = 0;
  ldrreading = analogRead(ldrpin);
  if (ldrreading < 200)
  {
    return HIGH;
  }
  else
  {
    return LOW;
  }
}
  
int batterymonitor()
{
  int value = 0;
  float pinvoltage = 0;
  float batteryvoltage = 0;
  float ratio = x; //measured value from output to potential divided output
  value = analogRead(battmonitorpin);
  pinvoltage = value * 0.00488;
  batteryvoltage = pinvoltage * ratio;
  return batteryvoltage;
}
  

