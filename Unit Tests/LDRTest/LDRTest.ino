
//Import modules used
#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>

//interrupt modules
#include <avr/interrupt.h>
#include <avr/power.h>
#include <avr/sleep.h>

//Initialise RF24 Radio Bits
// nRF24L01(+) radio attached to SPI and pins 9 & 10
RF24 radio(9,10);
// Network uses that radio
RF24Network network(radio);
// Address of our node
const uint16_t this_node = 0;
// Address of the other node
const uint16_t other_node = 1;

// Initialise global pin variables
int pirpin = 2; //interrupt pins on 2&3
int temppin = A5;
int battmonitorpin = A4;
int ledoutpin = 3;
int ldrpin = A3;
unsigned long value = 0; //probably not an integer

// Initialise global reading variables
int tempreading = 0;
int battreading = 0;
int ldrreading = 0;

// Delay 
int leddelay = 30000;


void setup()
{
  //Radio setup
  Serial.begin(57600);  //Start the serial connection with the computer
  SPI.begin();
  radio.begin();
  network.begin(/*channel*/ 90, /*node address*/ this_node);  
  
  //Setup pins
  pinMode(pirpin, INPUT);
  pinMode(temppin, INPUT);
  pinMode(battmonitorpin, INPUT);
  pinMode(ledoutpin, OUTPUT);
  pinMode(ldrpin, INPUT);
  
}

void loop()
{
 Serial.print(ldrread()); 
 Serial.print(analogRead(ldrpin));
 delay(3000);
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
