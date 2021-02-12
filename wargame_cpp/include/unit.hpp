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