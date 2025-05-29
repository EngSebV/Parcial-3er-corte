#ifndef POKEDEX_H
#define POKEDEX_H

#include "pokemon.h"

Pokemon createPikachu() {
    return Pokemon {
        "Pikachu",
        100,
        100,
        {
            {"Impactrueno", 20},
            {"Ataque Rápido", 15}
        }
    };
}

Pokemon createCharmander() {
    return Pokemon {
        "Charmander",
        100,
        100,
        {
            {"Llamarada", 25},
            {"Arañazo", 10}
        }
    };
}

#endif
