# 270191U025-Software-Architecture-assignment-template

Resources:

1. https://www.state-machine.com/doc/AN_Simple_OOP_in_C.pdf
2.

## Assignment

<img src="uml.svg" width=500>

In this exercise we will consider the example of an real-time strategy (RTS) game, such as WarCraft or Red Alert.
Common for RTS games is that you, the commander control a number of units that you can command to attack, cast-abilities and heal other units.
We use this concept to examine an important concept that is at the heart of OOP, the concept of interfaces and the mechanism frequently used to implement these vtables.

During this exercise you will:

1. [Learn about interfaces and dependency injection](Interfaces-and-Dynamic-Dispatch)
2. [Examine how interfaces can be realized in C](Dynamic-Dispatch-and-Vtables-in-C)
3. [Examine how the interfaces can realized in C++](Abstract-Classes-In-C++)

## Interfaces and Dynamic Dispatch

In programming an interface can be though of as a contract defining a set of functions, as well as how to access these.
In C this is provided by the function defintions and variables declared in the header files.

```C
void unit_attack_target(Unit *self, Unit *target);
```

Ideally we would like to be able to call this function on any object that implements this interface like so:

```C

Unit skinny_joe;
Soldier gi_joe;
CombatMedic caring_carl;
// instantiate structs

unit_attack_target(&skinny_joe, &skinny_joe)
unit_attack_target(&gi_joe, &skinny_joe)
unit_attack_target(&caring_carl, &skinny_joe)
```

There are two bad things about this example

1. Compiler will not allow this due to difference in types.
2. Each class has no way of defining their own implementations for methods, for example suppose 'Caring Carl' refuses to attack 'Skinny Joe'?

The solution to this problem is a method known as _dynamic dispatch_ that allow us to determine the correct method to call at runtime based on the type of object we are dealing with.

In dynamic languages like Python or Javascript this happens implicitly:

```python
footman = Unit(100)
gi_joe = Soldier(100,10)

# call function and 'hope' it is there
gi_joe.attack(footman)
footman.attack(gi_joe)
```

In the next part of the assignment you will examine how this is done can be acheived in C and then fix a small bug to make it run.

### Dynamic-Dispatch-and-Vtables-in-C
