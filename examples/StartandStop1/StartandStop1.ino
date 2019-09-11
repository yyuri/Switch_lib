/*
 This code will blink an LED attached to pin 13 on and off. 
 It will stay on for 0.25 seconds.
 It will stay off for 1 second.
 */
#include <Switcher.h>   //Include Metro library
#define LED 13           // Define the led's pin
bool LED_init = HIGH;    //We define HIGH as the INITIAL state of the led

Switcher led(LED, LED_init);


void setup()
{
  pinMode(LED,OUTPUT);
  digitalWrite(LED,LED_init); //The pinMode and initial state should still be defined in setup. digitalWrite
}

void loop()
{
led.Start();   //If we call led.Start() it will turn LED pin 13 into LOW
delay(300);
led.Stop();    //If we call led.Stop() it will turn LED pin 13 into HIGH
delay(300);
}
