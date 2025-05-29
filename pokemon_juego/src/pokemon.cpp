#include "pokemon.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Pokemon::Pokemon()
    : nombre("Desconocido"), tipo("Ninguno"), nivel(1), vida(100), vida_max(100),
      ataque(10), defensa(10), velocidad(10), estado(NORMAL), ataques({})
{

}


Pokemon::Pokemon(string nombre, string tipo, int nivel, int vida, int ataque, int defensa, int velocidad, vector<Ataque> ataques)
    : nombre(nombre), tipo(tipo), nivel(nivel), vida(vida), vida_max(vida), ataque(ataque), defensa(defensa), velocidad(velocidad), estado(NORMAL), ataques(ataques) {}

// Getters
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

// Setters
void Pokemon::setVida(int nuevaVida) { vida = nuevaVida; }
void Pokemon::recibirEstado(Estado nuevoEstado) { if (estado == NORMAL) estado = nuevoEstado; }

// Otros métodos
void Pokemon::evolucionar() {
    if (nivel < 100) {
        nivel++;
        if (nivel % 5 == 0) {
            ataque += 2;
            defensa += 2;
            velocidad += 1;
            vida_max += 5;
            vida += 5;
            if (vida > vida_max) vida = vida_max;
        }
    }
}

void Pokemon::procesarEstado() {
    if (estado == QUEMADO) {
        vida -= vida_max * 0.1;
        if (vida < 0) vida = 0;
        cout << nombre << " sufre por quemaduras!" << endl;
    } else if (estado == CONGELADO) {
        if ((rand() % 100) < 50) {
            cout << nombre << " está congelado y no puede moverse!" << endl;
        } else {
            cout << nombre << " se liberó del congelamiento!" << endl;
            estado = NORMAL;
        }
    }
}

bool Pokemon::puedeAtacar() {
    return estado != CONGELADO || (rand() % 100) >= 50;
}

int calcularDmg(Pokemon atacante, Pokemon defensor, Ataque ataque) {
    float efectividad = 1.0;
    if ((ataque.getTipo() == "Fuego" && defensor.getTipo() == "Planta") ||
        (ataque.getTipo() == "Agua" && defensor.getTipo() == "Fuego") ||
        (ataque.getTipo() == "Planta" && defensor.getTipo() == "Agua")) {
        efectividad = 2.0;
    }
    int base = ataque.getPoder() + atacante.getAtaque() - defensor.getDefensa();
    if (base < 1) base = 1;
    return static_cast<int>(base * efectividad);
}

Pokemon crearPokemon(string nombre, string tipo, int nivel, int vida, int ataque, int defensa, int velocidad, vector<Ataque> ataques) {
    return Pokemon(nombre, tipo, nivel, vida, ataque, defensa, velocidad, ataques);
}

vector<Pokemon> inicializarPokemones() {
    vector<Pokemon> lista;
    vector<Ataque> fuego = { Ataque("Ascuas", "Fuego", 40, true, false), Ataque("Llamarada", "Fuego", 60, true, false) };
    vector<Ataque> agua = { Ataque("Pistola Agua", "Agua", 40, false, false), Ataque("Hidrobomba", "Agua", 70, false, true) };
    vector<Ataque> planta = { Ataque("Látigo Cepa", "Planta", 35, false, false), Ataque("Rayo Solar", "Planta", 65, false, false) };

    lista.push_back(crearPokemon("Charmander", "Fuego", 5, 100, 20, 10, 15, fuego));
    lista.push_back(crearPokemon("Squirtle", "Agua", 5, 110, 18, 12, 10, agua));
    lista.push_back(crearPokemon("Bulbasaur", "Planta", 5, 105, 19, 11, 12, planta));
    return lista;
}

Pokemon elegirPokemon(string nombreJugador, vector<Pokemon> listaPokemones) {
    cout << "Selecciona un Pokémon para " << nombreJugador << ":" << endl;
    for (size_t i = 0; i < listaPokemones.size(); i++) {
        cout << i + 1 << ". " << listaPokemones[i].getNombre() << endl;
    }
    int eleccion;
    cin >> eleccion;
    while (eleccion < 1 || eleccion > static_cast<int>(listaPokemones.size())) {
        cout << "Elección inválida. Intenta de nuevo: ";
        cin >> eleccion;
    }
    return listaPokemones[eleccion - 1];
}
