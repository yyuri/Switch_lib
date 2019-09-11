/*
 This code will turn ON a LED attached to pin 13 when a condition is meet
 It will stay ON for 5 seconds
 
 Timer() requires initialization: Start() should be called to turn ON the LED
 Timer() should be called as ofter as possible ( like every loop )
 
 */

#include <Switcher.h>          //Include Switcher library
#define LED 13                  //Define the led's pin
bool LED_INIT = LOW;           //We define HIGH as the INITIAL state of the led

Switcher led(LED, LED_INIT);   // Define the Switcher led function led( LED pin , initial state: HIGH or LOW )
int condition = 0;              //Supposed variable condition on which we turn ON the led

void setup()
{
  pinMode(LED,OUTPUT);            // pinMode should be defined during setup
  digitalWrite(LED,LED_INIT);     // digitalWrite with the initial state for the pin should be defined during the setup
}

void loop()
{
  led.Timer(5,0);               // Led will stay ON for 5 seconds, then it will turn OFF
  if (condition = 0) {
    led.Start();                // It will turn ON the led
    condition = 1;
  }
}
//  led.Timer(5,1);   // Led will stay ON for 5 minute
//  led.Timer(5,2);   // Led will stay ON for 5 hour
