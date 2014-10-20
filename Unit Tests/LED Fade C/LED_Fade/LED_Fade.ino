
int ledoutpin = 3;

void setup()
{
  pinMode(ledoutpin, OUTPUT);
}


void loop()
{
  ledfadeon();
  delay(3000);
  ledfadeoff();
  delay(3000);
}  

int ledfadeon()
{
  //set initial defaults
  int brightness = 0;
  int fadeamount = 1;
  while (brightness != 255)
  {
    brightness = brightness + fadeamount;
    analogWrite(ledoutpin, brightness);
    delay(30);
  }
}


int ledfadeoff()
{
  //set initial defaults
  int brightness = 255;
  int fadeamount = 1;
  while (brightness != 0)
  {
    brightness = brightness - fadeamount;
    analogWrite(ledoutpin, brightness);
    delay(30);
  }
}
