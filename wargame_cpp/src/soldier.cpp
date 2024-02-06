#include "soldier.hpp"

Soldier::Soldier(int health, int damage) : Unit(health), damage(damage)
{
}

void Soldier::attack(Unit &target)
{
    target.set_health(target.get_health() - damage); /* Damage to target is equal to soldiers damage value*/
}
void Soldier::heal(Unit &target)
{
    return; /* Soldier can not heal */
}
