/*
 This code will blink an LED attached to pin 13 on and off. 
 It will stay on for 1 TIME UNIT.
 It will stay off for 3 TIME UNIT.
 TIME UNIT can be in seconds, minutes or hours
 */
#include <Switcher.h> //Include Switcher library
#define LED 13 // Define the led's pin

Switcher led(LED, HIGH);  // Define the Switcher led function led(LED pin, pin initial state: HIGH or LOW )

void setup()
{
  pinMode(LED,OUTPUT);      // Define the Switcher led function
  digitalWrite(LED,HIGH);   // Define the Switcher led function

}

void loop()
{
    led.Update(1,3,0); // Led will stay on for 1 second, off for 3 seconds 
    
//  led.Update(1,3,1); // Led will stay on for 1 minute, off for 3 minutes 
//  led.Update(1,3,2); // Led will stay on for 1 hour, off for 3 hours 

}
