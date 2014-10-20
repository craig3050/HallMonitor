
//interrupt modules
#include <avr/interrupt.h>
#include <avr/power.h>
#include <avr/sleep.h>

// Initialise global pin variables
int pirPin = 2; //interrupt pins on 2&3

void setup()
{
  //Radio setup
  Serial.begin(57600);  //Start the serial connection with the computer 
  

  //Setup pins
  pinMode(pirPin, INPUT);
  
}

void loop()
{
 Serial.print(digitalRead(pirPin)); 
 delay(1000);
 sleepNow();
}

void sleepNow(void)
{
    // Set pin 2 as interrupt and attach handler:
    attachInterrupt(0, pinInterrupt, CHANGE);
    delay(100);
    //
    // Choose our preferred sleep mode:
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);

    // Set sleep enable (SE) bit:
    sleep_enable();

    // Put the device to sleep:
    sleep_mode();

    // Upon waking up, sketch continues from this point.
    sleep_disable();


}

void pinInterrupt(void)
{
  detachInterrupt(0);
}


