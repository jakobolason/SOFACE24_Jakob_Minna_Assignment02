#ifndef COMBAT_MEDIC_HPP
#define COMBAT_MEDIC_HPP

#include "soldier.hpp"

class CombatMedic : public Soldier
{
public:
    CombatMedic(int health, int damage);
    virtual void heal(Unit &target);
};

#endif // COMBAT_MEDIC_HPP