# traffic-light-fsm
Traffic Light Finite State Machine in C

## Overview
This project models a traffic light system using a Finite State Machine (FSM) in C, as part of my exploration of systems engineering and control logic. The program tracks the current state of the system and transitions deterministically to the next state in a continuous cycle.

The system was later extended with timing and a pedestrian request input to better reflect real-world behaviour.

---

## Key Idea
A simple demonstration of a Finite State Machine (FSM) used to model deterministic system behaviour through clearly defined states and transitions.

---

## System Design

### States
The traffic light is modelled using a fixed set of states:

- RED  
- RED_AMBER  
- GREEN  
- AMBER  

These states repeat in the following cycle:

RED → RED_AMBER → GREEN → AMBER → RED → ...

---

### Enum Definition
An `enum` is used to define a set of unique named states:

```c
typedef enum {
    RED,
    RED_AMBER,
    GREEN,
    AMBER
} State;
```

### Timing
Each state persists for a defined duration to simulate real-world behaviour
- RED → 5 seconds
- RED_AMBER → 1 second
- GREEN → 5 seconds
- AMBER → 2 seconds

---

### Pedestrian Request
	•	The system includes a simulated pedestrian button
	•	The user can request a crossing while the light is GREEN
	•	The request persists until it is served
	•	The system continues safely through AMBER
	•	When the system reaches RED, a WALK phase is activated
	•	WALK lasts 5 seconds
	•	The request is cleared after WALK completes

---

### Control Flow
	•	Display current traffic light state
	•	Accept pedestrian input when the state is GREEN
	•	Wait for the duration of the current state
	•	If the system is in RED and a request is active:
	•	Activate WALK for 5 seconds
	•	Clear the request
	•	Transition to the next state

---

### Design Decisions
	•	I used switch statements because I’m working with a fixed set of known states, which maps naturally to a finite state machine
	•	In getDelay, returning 0 is a safe fallback since it just results in no delay
	•	In updateState, returning 0 would correspond to a valid state (RED), so it could unintentionally change system behaviour
	•	I separated the system into modular components, where each function handled a single responsibility
	•	This improves clarity and maintainability
	•	The original design was fully deterministic, with predefined state transitions
	•	I then enhanced it by adding an asynchronous input, a pedestrian request
	•	This introduces event-driven behaviour while maintaining safe and predictable system logic
	•	In a real junction, pedestrian crossing behaviour is part of the wider control system
	•	For this version, I kept the traffic-light FSM focused on vehicle states and treated WALK as an additional output during RED
	•	This allowed incremental extension without overcomplicating the initial design

---

### Concepts Demonstrated
	•	Finite State Machines (FSM)
	•	Deterministic system design
	•	Modular programming (separation of concerns)
	•	Time-based control systems
	•	Event-driven input handling
	•	Real-world system modelling

---

### Notes
	•	This is a simulation, not a real-time embedded system
	•	Pedestrian input is manually triggered via console input
	•	Asynchronous behaviour is simulated rather than implemented with concurrency

---

### Future Improvements
	•	Continuous loop instead of fixed iterations
	•	More realistic pedestrian signalling (WALK / DON'T WALK)
	•	Multiple pedestrian crossings
	•	Full intersection modelling
	•	Frontend visualisation
