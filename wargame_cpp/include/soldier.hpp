#ifndef SOLDIER_HPP
#define SOLDIER_HPP
#include "unit.hpp"

class Soldier : public Unit
{
public:
    Soldier(int health, int damage);
    virtual void attack(Unit &target);
    virtual void heal(Unit &target);
    virtual ~Soldier(){};

private:
    int damage;
};

#endif // SOLDIER_HPP