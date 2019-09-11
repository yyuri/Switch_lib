
Switch_lib is a library for Arduino

Switch_lib library helps you to handle simple operations on digital pin state, it's thought to actuate on relays, turning ON and OFF devices with timers and handling alternated time controled states:



- Turn any pin HIGH with a timer attached: for 1 second, 5 minutes or 10 hours


- Defines Start and Stop functions to switch the initial defined state of the Pin


It use 4 Functions and a definition:

Definition: Requires a pin on where to actuate and the initial desired state of the pin ( HIGH or LOW )

    Switcher(pin, initial_state);
    
Start and Stop functions:

- Switch HIGH or LOW based on the initial state, so we say Start and Stop to any pin

    Start();            Switch the state of the pin to HIGH if it was LOW, and LOW if it was HIGH
    Stop();	            Switch the state of the pin to the initial state
        
    
    
Timer function:

- Turn the pin to the initial state after any desired time: 5 seconds, 30 minutes or 1 hour.
    
    Timer(long on, int unit);
      - on: Desired time
      - unit: 0: seconds, 1: minutes, 2:hours
      Example: Timer(5,0) will turn the pin to the initial state after 5 seconds
      Timer requires initialization, see example section.

Alternate switcher:

- Switch the state of the pin every certain time: Like 1minute ON, 5 minutes OFF
    
    Alternate(long on, long off, int unit);
      - on: Desired ON time
      - off: Desired OFF time
      - unit: Defines the time unit to use
              0 for seconds, 
              1 for minutes, 
              2 for hours
     Example: Alternate(14, 8, 2); Will create periods of 14h ON, 8h OFF.

[![arduino-library-badge](https://www.ardu-badge.com/badge/switch_lib.svg)](https://www.ardu-badge.com/MyLibrary)

      
