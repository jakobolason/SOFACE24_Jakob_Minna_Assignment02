#include "unit.h"

int _unit_get_health(Unit *self)
{
    return self->health;
}

void _unit_set_health(Unit *self, int health)
{
    self->health = health;
}

void _unit_take_hit(Unit *self, int damage)
{
    self->health -= damage;
}

void _unit_attack_target(Unit *self, Unit *target)
{
    printf("'attack' method is not implemented for 'Unit' class");
    assert(0);
}

void _unit_heal_target(Unit *self, Unit *target)
{
    printf("'heal' method is not implemented for 'Unit' class");
    assert(0);
}

// virtual methods
int unit_get_health(Unit *self)
{
    return self->vt->get_health(self);
}

void unit_set_health(Unit *self, int health)
{
    self->vt->set_health(self, health);
}

void unit_take_hit(Unit *self, int damage)
{
    self->vt->take_hit(self, damage);
}

void unit_attack_target(Unit *self, Unit *target)
{
    self->vt->attack_target(self, target);
}

void unit_heal_target(Unit *self, Unit *target)
{
    self->vt->heal_target(self, target);
}

void make_unit(Unit *self, int health)
{
    static UnitVTable vt = {_unit_get_health, _unit_set_health, _unit_take_hit, _unit_attack_target, _unit_heal_target};
    self->vt = &vt;
    self->health = health;
}