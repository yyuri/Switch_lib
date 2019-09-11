/*
  Switch.h - Library for Switch temporarly relays
  Released into the public domain.
*/
#include "Arduino.h"

#ifndef SWITCHER_H
#define SWITCHER_H


class Switcher   //Turn on/off a relay, set delay timer for HIGH and LOW state, or switch a relay with a timer(seconds).
{  
  public:
    Switcher(int pin, bool state);
    void Update(long on, long off, int unit);
    void Start();	
    void Stop();	
    void Timer(long on, int unit);
    int count;
    bool st;

    
  private:
    int _pin;      // the number of the Power pin
    bool _state;   // Initial relay state: HIGH OR LOW
    unsigned long _previousMillis; // will store last time DEVICE was updated
};

#endif
