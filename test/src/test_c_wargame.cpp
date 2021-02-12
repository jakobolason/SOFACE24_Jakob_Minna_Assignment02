#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

// use 'extern "C"' when including C header files in C++
extern "C"
{
#include "unit.h"
#include "soldier.h"
#include "combat_medic.h"
}

// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

TEST_CASE("Unit")
{
    Unit SkinnyJoe;
    make_unit(&SkinnyJoe, 10);
    REQUIRE(unit_get_health(&SkinnyJoe) == 10);
}

TEST_CASE("Soldier")
{
    Soldier MadMike;
    make_soldier(&MadMike, 120, 10);
    Unit SkinnyJoe;
    make_unit(&SkinnyJoe, 10);

    REQUIRE(unit_get_health((Unit *)&MadMike) == 120);

    unit_attack_target(((Unit *)&MadMike), &SkinnyJoe);
    REQUIRE(unit_get_health(&SkinnyJoe) == 0);
}

TEST_CASE("Combat Medic")
{
    Unit SkinnyJoe;
    make_unit(&SkinnyJoe, 10);

    CombatMedic CaringCarlson;
    make_combat_medic(&CaringCarlson, 45, 5);

    REQUIRE(unit_get_health(&SkinnyJoe) == 10);

    unit_attack_target((Unit *)&CaringCarlson, &SkinnyJoe);
    REQUIRE(unit_get_health(&SkinnyJoe) == 5);
    unit_attack_target((Unit *)&CaringCarlson, &SkinnyJoe);
    REQUIRE(unit_get_health(&SkinnyJoe) == 0);
    unit_heal_target((Unit *)&CaringCarlson, &SkinnyJoe);

    while (unit_get_health(&SkinnyJoe) > 0)
    {
        unit_attack_target((Unit *)&CaringCarlson, &SkinnyJoe);
    }

    unit_heal_target((Unit *)&CaringCarlson, &SkinnyJoe);
    REQUIRE(unit_get_health(&SkinnyJoe) == 0); // he is dead
}