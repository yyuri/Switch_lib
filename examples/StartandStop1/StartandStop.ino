/*
 This code will turn ON and OFF a LED attached to pin 13 according to random conditions.
 It will turn HIGH the LED pin when a random number condition is meet
 It will turn LOW the LED pin when another random number condition is meet
 */
#include <Switcher.h>   //Include Switcher library
#define LED 13           // Define the led's pin
bool LED_init = LOW;    //We define LOW as the INITIAL state of the led
int randomNum;
Switcher led(LED, LED_init);


void setup()
{
  pinMode(LED,OUTPUT);
  digitalWrite(LED,LED_init); //The pinMode and initial state should always be defined during setup.
}

void loop()
{
randomnum = random(1,100);
if ( randomNum > 91 ) {
led.Start();   //If we call led.Start() it will turn LED pin 13 into LOW
}
else if (randomNum < 10 ) {
 led.Stop();    //If we call led.Stop() it will turn LED pin 13 into HIGH
}
}
