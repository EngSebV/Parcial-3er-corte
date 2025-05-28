#include "pokemon.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Pokemon::Pokemon(string nombre, string tipo, int nivel, int vida, int ataque, int defensa, int velocidad, vector<Ataque> ataques)
    : nombre(nombre), tipo(tipo), nivel(nivel), vida(vida), vida_max(vida), ataque(ataque), defensa(defensa), velocidad(velocidad), estado(NORMAL), ataques(ataques), haEvolucionado(false)
{ }

string Pokemon::getNombre() const { return nombre; }
string Pokemon::getTipo() const { return tipo; }
int Pokemon::getNivel() const { return nivel; }
int Pokemon::getVida() const { return vida; }
int Pokemon::getVidaMax() const { return vida_max; }
int Pokemon::getAtaque() const { return ataque; }
int Pokemon::getDefensa() const { return defensa; }
int Pokemon::getVelocidad() const { return velocidad; }
Estado Pokemon::getEstado() const { return estado; }
vector<Ataque> Pokemon::getAtaques() const { return ataques; }

void Pokemon::setVida(int nuevaVida) {
    if(nuevaVida < 0)
        nuevaVida = 0;
    vida = nuevaVida;
}

void Pokemon::setEstado(Estado nuevoEstado) {
    estado = nuevoEstado;
}

void Pokemon::evolucionar() {
    if(nivel >= 30 && !haEvolucionado) {
        ataque += 5;
        defensa += 5;
        haEvolucionado = true;
        std::cout << GREEN << nombre << " ha evolucionado y se ha vuelto más fuerte!" << RESET << std::endl;
    }
}

void Pokemon::procesarEstado() {
    if (estado == QUEMADO) {
        setVida(vida - 5);
        std::cout << RED << nombre << " está quemado y pierde 5 de vida!" << RESET << std::endl;
    } else if (estado == CONGELADO) {
        if (rand() % 100 < 50) {
            std::cout << BLUE << nombre << " sigue congelado y no puede atacar!" << RESET << std::endl;
        } else {
            std::cout << nombre << " se ha descongelado!" << std::endl;
            estado = NORMAL;
        }
    }
}

bool Pokemon::puedeAtacar() {
    return (estado != CONGELADO);
}

void Pokemon::recibirEstado(Estado nuevoEstado) {
    if (estado == NORMAL)
        estado = nuevoEstado;
}

int calcularDmg(const Pokemon& atacante, const Pokemon& defensor, const Ataque& ataque) {
    int dmgBase = ataque.getPoder() + atacante.getAtaque() - (defensor.getDefensa() / 2);
    if (dmgBase < 1)
        dmgBase = 1;
    return dmgBase;
}

vector<Pokemon> inicializarPokemones() {
    vector<Pokemon> pokemones;

    vector<Ataque> ataquesCharmander = {
        Ataque("Ascuas", "Fuego", 40, true, false),
        Ataque("Arañazo", "Normal", 35, false, false),
        Ataque("Lanzallamas", "Fuego", 60, true, false)
    };

    vector<Ataque> ataquesSquirtle = {
        Ataque("Pistola Agua", "Agua", 40, false, false),
        Ataque("Placaje", "Normal", 35, false, false),
        Ataque("Hidrobomba", "Agua", 65, false, false)
    };

    vector<Ataque> ataquesBulbasaur = {
        Ataque("Látigo Cepa", "Planta", 45, false, false),
        Ataque("Gruñido", "Normal", 20, false, false),
        Ataque("Rayo Solar", "Planta", 65, false, false)
    };

    vector<Ataque> ataquesMachomp = {
        Ataque("Golpe Karate", "Lucha", 50, false, false),
        Ataque("Doble Filo", "Normal", 60, false, false),
        Ataque("Puño Fuego", "Fuego", 55, true, false)
    };

    vector<Ataque> ataquesPsyduck = {
        Ataque("Confusión", "Psíquico", 50, false, false),
        Ataque("Cabezazo", "Normal", 40, false, false),
        Ataque("Rayo Hielo", "Hielo", 60, false, true)
    };

    vector<Ataque> ataquesGrowlithe = {
        Ataque("Gruñido", "Normal", 20, false, false),
        Ataque("Colmillo Ígneo", "Fuego", 60, true, false),
        Ataque("Mordisco", "Siniestro", 40, false, false)
    };

    pokemones.push_back(Pokemon("Charmander", "Fuego", 25, 150, 70, 60, 65, ataquesCharmander));
    pokemones.push_back(Pokemon("Squirtle", "Agua", 25, 160, 60, 70, 50, ataquesSquirtle));
    pokemones.push_back(Pokemon("Bulbasaur", "Planta", 25, 155, 65, 65, 55, ataquesBulbasaur));
    pokemones.push_back(Pokemon("Machomp", "Lucha", 21, 180, 80, 60, 70, ataquesMachomp));
    pokemones.push_back(Pokemon("Psyduck", "Agua", 22, 170, 70, 55, 60, ataquesPsyduck));
    pokemones.push_back(Pokemon("Growlithe", "Fuego", 23, 165, 75, 60, 58, ataquesGrowlithe));

    return pokemones;
}

Pokemon elegirPokemon(const string &nombreJugador, const vector<Pokemon>& lista) {
    std::cout << nombreJugador << ", elige tu Pokémon:" << std::endl;
    for (size_t i = 0; i < lista.size(); i++) {
        std::cout << i + 1 << ". " << lista[i].getNombre() << " (" << lista[i].getTipo() << ")" << std::endl;
    }
    int eleccion = 0;
    do {
        std::cout << "> ";
        std::cin >> eleccion;
    } while (eleccion < 1 || eleccion > static_cast<int>(lista.size()));
    return lista[eleccion - 1];
}