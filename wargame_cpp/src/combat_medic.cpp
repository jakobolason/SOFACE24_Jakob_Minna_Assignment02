#include "combat_medic.hpp"
#include <iostream>
using namespace std;

CombatMedic::CombatMedic(int health, int damage) : Soldier(health, damage)
{
}

void CombatMedic::heal(Unit &target)
{
    if (target.get_health() <= 0)
    {
        cout << "He is gone.."; /* A dead soldier can not be healed */
        return;
    }
    else {
        cout << "Hang in there!";
        target.set_health(target.get_health() + 10 ); /*Medic heals 10hp */
    }
}