#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
#include "ataque.h"

using namespace std;

enum Estado { NORMAL, QUEMADO, CONGELADO };

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string BLUE = "\033[34m";
const string YELLOW = "\033[33m";

struct Pokemon {
    string nombre;
    string tipo;
    int nivel;
    int vida;
    int vida_max;
    int ataque;
    int defensa;
    int velocidad;
    Estado estado;
    vector<Ataque> ataques;

    void evolucionar();
    void procesarEstado();
    bool puedeAtacar();
    void recibirEstado(Estado nuevoEstado);
};

int calcularDmg(Pokemon atacante, Pokemon defensor, Ataque ataque);
vector<Pokemon> inicializarPokemones();
Pokemon crearPokemon(string nombre, string tipo, int nivel, int vida, int ataque, int defensa, int velocidad, vector<Ataque> ataques);

#endif
