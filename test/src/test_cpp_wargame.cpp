#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "unit.hpp"
#include "soldier.hpp"
#include "combat_medic.hpp"

// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

TEST_CASE("Soldier")
{
    Soldier MadMike(120, 10);
    Soldier SkinnyJoe(10, 0);

    REQUIRE(MadMike.get_health() == 120);

    MadMike.attack(SkinnyJoe);
    REQUIRE(SkinnyJoe.get_health() == 0);
}

TEST_CASE("Combat Medic")
{
    Soldier SkinnyJoe(10, 0);
    CombatMedic CaringCarlson(45, 5);

    REQUIRE(SkinnyJoe.get_health() == 10);

    CaringCarlson.attack(SkinnyJoe);
    REQUIRE(SkinnyJoe.get_health() == 5);

    CaringCarlson.heal(SkinnyJoe);
    REQUIRE(SkinnyJoe.get_health() > 5);

    while (SkinnyJoe.get_health() > 0)
    {
        CaringCarlson.attack(SkinnyJoe);
    }

    CaringCarlson.heal(SkinnyJoe);
    REQUIRE(SkinnyJoe.get_health() <= 0); // he is dead
}