#include "Switcher.h"


Switcher::Switcher(int pin, bool initstate)

{
  _pin = pin;		 //Stores the Arduino pin that operates the relay
  _state = initstate;	 //Stores the inital or default state of the relay (HIGH OR LOW)
  st = _state;     	 //Stores the current state of the Switch  (HIGH OR LOW)
}

int Switcher::Period(long on, long off, int unit)  //Switch the relay according to the ON and OFF time set. Is referenced in Hours. 
  {
    // check to see if it's time to change the state of the DEVICE
    unsigned long OnTime;
    unsigned long OffTime;
    unsigned long currentMillis = millis();
    int i=0;
    if (unit == 0) {
	OnTime = on*1000;	//Seconds to milliseconds
	OffTime = off*1000;
	}		
    else if (unit == 1) {
	OnTime = on*60000;	//Minutes to milliseconds	
	OffTime = off*60000;	
	}	
    else {
	OnTime = on*3600000;	//Hours to milliseconds
	OffTime = off*3600000;
	}	

    if((st == HIGH) && (currentMillis - _previousMillis >= OnTime) )
    {
	_previousMillis = currentMillis; 	// Save current time
	digitalWrite(_pin, LOW);  		// Switch the relay
	st = LOW;  				// Save current state of the relay
	i = 1;
    }
    else if ((st == LOW) && (currentMillis - _previousMillis >= OffTime) )
    {
	_previousMillis = currentMillis;  	// Save current time
	digitalWrite(_pin, HIGH);   		// Switch the relay
	st = HIGH;  				// Save current state of the relay
    }
    return(i);
  }

void Switcher::Start()			//Switch the relay state. Turns to HIGH if it was OFF, OFF is it was ON 
  {
	if (st == _state) {
		st = !_state;
		digitalWrite(_pin, st);   	// Start DEVICE
		_previousMillis = millis();     //Save current time, so we know when it was switched last
	}
}

void Switcher::Stop()			//Switch the relay state. Turns to HIGH if it was OFF, OFF is it was ON 
  {
	if (st != _state) {
		st = _state;
		digitalWrite(_pin, st);   	// Stop DEVICE
		_previousMillis = millis();     //Save current time, so we know when it was switched last
	}
}

int Switcher::Timer(long on, int unit)		//Switch the relay to initial state if it was switched more than x Time. It can be refferenced in seconds, minutes or hours.
  {
    unsigned long OnTime;
    unsigned long currentMillis = millis();
    int i = 0;
    if (unit == 0) {
	OnTime = on*1000;	//Seconds to milliseconds
	}		
    else if (unit == 1) {
	OnTime = on*60000;	//Minutes to milliseconds
	}		
    else {
	OnTime = on*3600000;	//Seconds to milliseconds
	}	
	
    if(st != _state  && (currentMillis - _previousMillis >= OnTime)) {
	st = _state;
 	digitalWrite(_pin, st);   // Start DEVICE
	i = 1;
    }
    return(i);	
 }
