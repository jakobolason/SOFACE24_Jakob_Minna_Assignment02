add_library(wargame_c src/unit.c src/soldier.c src/combat_medic.c)
target_include_directories(wargame_c PUBLIC include)