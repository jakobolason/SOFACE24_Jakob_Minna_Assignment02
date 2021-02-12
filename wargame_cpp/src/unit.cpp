#include "unit.hpp"

Unit::Unit(int health) : health(health)
{
}
const int Unit::get_health()
{
    return health;
}
void Unit::set_health(int health)
{
    this->health = health;
}
void Unit::take_hit(int damage)
{
    set_health(get_health() - damage);
}