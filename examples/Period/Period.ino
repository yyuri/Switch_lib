/*
 This code will turn ON and OFF a LED attached to pin 13. 
 It will stay ON for 5 seconds
 It will stay OFF for 10 seconds
 TIME UNIT can be in seconds, minutes or hours
 */
#include <Switcher.h>       //Include Switcher library
#define LED 13               // Define the led's pin
bool LED_INIT = LOW;        //We define LOW as the INITIAL state of the led

Switcher led(LED, LED_INIT);    // Define the Switcher led function led(LED pin, pin initial state: HIGH or LOW )

void setup()
{
  pinMode(LED,OUTPUT);            // pinMode should be defined during setup
  digitalWrite(LED,LED_INIT);     // digitalWrite with the initial state for the pin should be defined during the setup

}

void loop()
{
    led.Period(5,10,0);       // Led will stay ON for 5 second, OFF for 10 seconds     
}   
//  led.Period(5,10,1);        // We could use minutes: Led will stay on for 5 minute, off for 10 minutes 
//  led.Period(5,10,2);        // We could use hours: Led will stay on for 5 hour, off for 10 hours 
