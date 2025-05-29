#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>
#include "ataque.h"

using namespace std;

enum Estado { NORMAL, QUEMADO, CONGELADO };

class Pokemon {
private:
    string nombre, tipo;
    int nivel, vida, vida_max, ataque, defensa, velocidad;
    Estado estado;
    vector<Ataque> ataques;

public:
    // Constructor por defecto
    Pokemon();

    // Constructor con parámetros
    Pokemon(string nombre, string tipo, int nivel, int vida, int ataque, int defensa, int velocidad, vector<Ataque> ataques);

    // Getters
    string getNombre() const;
    string getTipo() const;
    int getNivel() const;
    int getVida() const;
    int getVidaMax() const;
    int getAtaque() const;
    int getDefensa() const;
    int getVelocidad() const;
    Estado getEstado() const;
    vector<Ataque> getAtaques() const;

    // Setters
    void setVida(int nuevaVida);
    void recibirEstado(Estado nuevoEstado);

    // Otros métodos
    void evolucionar();
    void procesarEstado();
    bool puedeAtacar();
};

// Funciones auxiliares
int calcularDmg(Pokemon atacante, Pokemon defensor, Ataque ataque);
Pokemon crearPokemon(string nombre, string tipo, int nivel, int vida, int ataque, int defensa, int velocidad, vector<Ataque> ataques);
vector<Pokemon> inicializarPokemones();
Pokemon elegirPokemon(string nombreJugador, vector<Pokemon> listaPokemones);

#endif // POKEMON_H

