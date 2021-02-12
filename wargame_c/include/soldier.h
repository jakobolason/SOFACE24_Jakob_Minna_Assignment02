#ifndef SOLDIER_H
#define SOLDIER_H

#include "unit.h"

typedef struct Soldier
{
    Unit inherited;
    int damage;
} Soldier;

void make_soldier(Soldier *self, int health, int damage);

#endif // SOLDIER_H