#ifndef UNIT_H
#define UNIT_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct UnitVTable;

typedef struct Unit
{
    struct UnitVTable *vt;
    int health;
} Unit;

typedef struct UnitVTable
{
    int (*get_health)(Unit *self);
    void (*set_health)(Unit *self, int health);
    void (*take_hit)(Unit *self, int);
    void (*attack_target)(Unit *self, Unit *target);
    void (*heal_target)(Unit *self, Unit *target);
} UnitVTable;

int unit_get_health(Unit *self);
void unit_set_health(Unit *self, int health);
void unit_take_hit(Unit *self, int damage);
void unit_attack_target(Unit *self, Unit *target);
void unit_heal_target(Unit *self, Unit *target);

void make_unit(Unit *self, int health);
#endif // UNIT_H