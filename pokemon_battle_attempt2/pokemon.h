#ifndef POKEMON_H
#define POKEMON_H

#include <string>

struct Attack {
    std::string name;
    int damage;
};

struct Pokemon {
    std::string name;
    int maxHP;
    int currentHP;
    Attack attacks[2];
};

void showPokemonStatus(const Pokemon& p);
void showMenu(const Pokemon& p);
void attack(Pokemon& attacker, Pokemon& defender, int attackIndex);

#endif
