
# Switch_lib: Arduino library

Switch_lib library helps you to handle simple operations on digital pin states:

- Use simple and intuitive functions to switch digital pin states
- Turn HIGH/LOW digital pins with attached temporizators, timecounters and periods of time
- Use this counters and timers to control relays and devices with ease
- Switch_lib does all this timeflow control without using Delay function or RTC clocks, just plain and simple Arduino code

## Usage of the library

#### Definition: 

- Requires a pin on where to actuate and the definition of the initial state of the pin ( HIGH or LOW )

```c++
Switcher light(int pin, bool initial_state);   //initial_state = HIGH or LOW
void setup()
{
  pinMode(pin,OUTPUT);            // pinMode should be defined during setup
  digitalWrite(pin,initial_state);// digitalWrite should also be defined during the setup
}
```


#### Start and Stop functions:

- Switch state of the pin based on the initial state, we can call Start() and Stop()

```c++
    light.Start();            Switch ON the light
    light.Stop();             Switch to the init_state
```       
    
    
#### Timer function:

- Turn to the initial state after any desired time: seconds, minutes or hours.

```c++   
void loop()
{
  if (condition == TRUE) {
  light.Start();                   //Timer requires initialization, see example section.
  condition = FALSE;
  }

  light.Timer(5,0);  //It will keep lights ON for 5 seconds
}
```
light.Timer(long on, int unit);
  - on: Desired time
  - unit: Defines the time unit to use
    - 0 for seconds, 
    - 1 for minutes, 
    - 2 for hour
    
    Timer requires initialization using the Start(); See examples section.

#### Alternated period switcher:

- Switch the state of the pin every certain time: Like 1minute ON, 5 minutes OFF

```c++
void loop()
{
light.Period(14, 8, 2);  //14 hours ON, 8 hours OFF
}
```

Period(long on, long off, int unit);
  - on: Desired ON time
  - off: Desired OFF time
  - unit: Defines the time unit to use
    - 0 for seconds, 
    - 1 for minutes, 
    - 2 for hours
    
    Example: Period(14, 8, 2); 14h ON / 8h OFF.


 [![arduino-library-badge](https://www.ardu-badge.com/badge/Switch_lib.svg?)](https://www.ardu-badge.com/Switch_lib)     
