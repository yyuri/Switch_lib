/*
  Switch.h - Library for Switch temporarly relays
  Released into the public domain.
*/
#include "Arduino.h"

#ifndef SWITCHER_H
#define SWITCHER_H


class Switcher  
{  
  public:
    Switcher(int pin, bool state);            //Set pin to operate and initial state HIGH or LOW
    int Period(long on, long off, int unit); 
    void Start();	                            
    void Stop();	
    int Timer(long on, int unit);
    bool st;

    
  private:
    int _pin;      // the number of the Power pin
    bool _state;   // Initial relay state: HIGH OR LOW
    unsigned long _previousMillis; // will store last time DEVICE was updated
};

#endif
