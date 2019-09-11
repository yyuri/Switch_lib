
# Switch_lib: Arduino library

Switch_lib library helps you to handle simple operations on digital pin state,

- It's thought to actuate on relays, turn ON & OFF with ease relays with attached temporization and counters

- Handle timers and switch relays without delay functions or RTC clocks, just simple functions for Arduino

## Usage of the library

Definition: Requires a pin on where to actuate and the initial state of the pin ( HIGH or LOW )

```c++
Switcher light(int pin, bool initial_state);   //initial_state = HIGH or LOW
void setup()
{
  pinMode(pin,OUTPUT);            // pinMode should be defined during setup
  digitalWrite(pin,initial_state);     // digitalWrite with the initial state for the pin should be defined during the setup
}
```
### Start and Stop functions:

- Switch state of the pin based on the initial state, we can call Start() and Stop()
```c++
    light.Start();            Switch the state of the pin to HIGH if it was LOW, and LOW if it was HIGH
    light.Stop();	            Switch the state of the pin to the initial state
```       
    
    
### Timer function:

- Turn to the initial state after any desired time: 5 seconds, 30 minutes or 1 hour.

```c++   
Switcher light(int pin, bool initial_state);   //initial_state = HIGH or LOW
void setup()
{
  pinMode(pin,OUTPUT);             // pinMode should be defined during setup
  digitalWrite(pin,initial_state); // digitalWrite with the initial state for the pin should be defined during the setup
  light.start();                   //Timer requires initialization, see example section.
}
void loop()
{
light.Timer(5,0);  //It will stay ON for 5seconds
}
```       
light.Timer(long on, int unit);
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


      
