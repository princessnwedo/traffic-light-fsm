# traffic-light-fsm
Traffic Light Finite State Machine in C

## Overview
This project models a traffic light system using a Finite State Machine (FSM) in C, as part of my exploration of systems engineering and control logic. The program tracks the current state of the system and transitions deterministically to the next state in a continuous cycle.

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
