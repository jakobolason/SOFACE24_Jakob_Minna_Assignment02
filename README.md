# 270191U025-Software-Architecture-assignment-template

Resources:

1. https://www.state-machine.com/doc/AN_Simple_OOP_in_C.pdf
2. https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/

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

## Dynamic Dispatch and Vtables in C

A common way to implement dynamic dispatch in C is using vtables. Contrary to their name these are often implemented without the use of arrays, but rather as a struct of function pointers:

```C
typedef struct UnitVTable
{
    int (*get_health)(Unit *self);
    void (*set_health)(Unit *self, int health);
    void (*take_hit)(Unit *self, int);
    void (*attack_target)(Unit *self, Unit *target);
    void (*heal_target)(Unit *self, Unit *target);
} UnitVTable;
```

In simple terms we do:

1. Add vtable to `Unit`, `Solider` and `CombatMedic`
2. When calling a function for a specific type, look up the function pointer and invoke this.

```C
int unit_get_health(Unit *self)
{
    return self->vt->get_health(self);
}
```

It should be noted that the implementation of vtables are inherently non-portable and error-prone since they rely on how the compiler lays out the fields of the struct in memory.

Examine the code listed in `unit.h, soldier.h, combat_medic.h` and their associated source files.
**Focus on the concepts -- not the concrete implementation, the goal is simply to show you that it is a messy affair in C.**

Run the tests defined in `test_c_wargame.cpp`, this fails on line 56, because CaringCarlson is able to 'resurrect' SkinnyJoe which should not be possible.

```C
while (unit_get_health(&SkinnyJoe) > 0)
{
    unit_attack_target((Unit *)&CaringCarlson, &SkinnyJoe);
}

unit_heal_target((Unit *)&CaringCarlson, &SkinnyJoe);
REQUIRE(unit_get_health(&SkinnyJoe) == 0); // he is dead
```

Correct the implementation in `combat_medic.c` such that the tests passes.

## Abstract Classes In C++

Dynamic Dispatch can be implemented in C++ without the hassle of manually creating Vtables.
Instead functions are simply marked as virtual as follows:

```cpp
#ifndef UNIT_HPP
#define UNIT_HPP
class Unit
{
public:
    Unit(int health);
    virtual const int get_health();
    virtual void set_health(int);
    virtual void take_hit(int damage);
    virtual void attack(Unit &target) = 0;
    virtual void heal(Unit &target, int health) = 0;
    virtual ~Unit(){};

private:
    int health;
};
#endif // UNIT_HPP
```

The `= 0` marks a function as pure-virtual indicating that Unit defines no implementation for this.
This also results in the class becoming abstract, meaning it cannot be instantiated, that is only it's derived classes can be.

Methods not marked with `= 0` must be implemented in `unit.cpp`, these serve as default implementations for the derived class such that they do not have to implement this functionality themselves.

Correct the code in `soldier.cpp, combat_medic.cpp` to make the tests pass.
**Notice that in the C code an Unit was possible to instantiate. This is no longer the case since Unit has pure-virtual methods. A Solider object is used instead of a Unit object in the tests**
