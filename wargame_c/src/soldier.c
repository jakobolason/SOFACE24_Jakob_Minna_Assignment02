#include "soldier.h"

void _soldier_attack(Unit *self, Unit *target)
{
    Soldier *soldier = (Soldier *)self;
    unit_take_hit(target, soldier->damage);
}

void make_soldier(Soldier *self, int health, int damage)
{
    make_unit(&self->inherited, health);

    // override "attack" method from base class
    self->inherited.vt->attack_target = _soldier_attack;

    self->damage = damage;
}