#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "pokemon.h"
#include "ataque.h"

using namespace std;

void mostrarBarraVida(const Pokemon &p) {
    int total = 20;
    int barras = static_cast<int>((static_cast<float>(p.getVida()) / p.getVidaMax()) * total);
    cout << p.getNombre() << " [";
    for (int i = 0; i < barras; i++) cout << "#";
    for (int i = barras; i < total; i++) cout << "-";
    cout << "] " << p.getVida() << "/" << p.getVidaMax();
    if (p.getEstado() == QUEMADO) cout << " 🔥";
    if (p.getEstado() == CONGELADO) cout << " ❄️";
    cout << endl;
}

void mostrarPokemon(const Pokemon &p) {
    cout << GREEN << p.getNombre() << RESET << " (" << p.getTipo() << ") Nivel " << p.getNivel() << endl;
    cout << "Ataque: " << p.getAtaque() << " | Defensa: " << p.getDefensa() << " | Velocidad: " << p.getVelocidad() << endl;
    mostrarBarraVida(p);
    cout << "Ataques:" << endl;
    vector<Ataque> ataques = p.getAtaques();
    for (size_t i = 0; i < ataques.size(); i++) {
        cout << i + 1 << ". " << ataques[i].getNombre() << " (Tipo: " << ataques[i].getTipo()
             << ", Poder: " << ataques[i].getPoder();
        if (ataques[i].getPuedeQuemar()) cout << ", puede quemar";
        if (ataques[i].getPuedeCongelar()) cout << ", puede congelar";
        cout << ")" << endl;
    }
}

void turnoDeAtaque(Pokemon &atacante, Pokemon &defensor, bool esJugador) {
    cout << YELLOW << "\nTurno de " << atacante.getNombre() << RESET << endl;

    atacante.evolucionar();
    atacante.procesarEstado();
    if (!atacante.puedeAtacar()) return;

    int eleccion = 0;
    vector<Ataque> ataques = atacante.getAtaques();
    if (esJugador) {
        do {
            cout << "Elige un ataque:" << endl;
            for (size_t i = 0; i < ataques.size(); i++)
                cout << i + 1 << ". " << ataques[i].getNombre() << endl;
            cin >> eleccion;
        } while (eleccion < 1 || eleccion > static_cast<int>(ataques.size()));
    } else {
        eleccion = rand() % ataques.size() + 1;
        cout << "El bot eligió: " << ataques[eleccion - 1].getNombre() << endl;
    }

    Ataque ataque = ataques[eleccion - 1];
    int dmg = calcularDmg(atacante, defensor, ataque);
    int nuevaVida = defensor.getVida() - dmg;
    if (nuevaVida < 0) nuevaVida = 0;
    defensor.setVida(nuevaVida);

    cout << BLUE << atacante.getNombre() << " usó " << ataque.getNombre() << "!" << RESET << endl;
    cout << "¡Causó " << dmg << " de daño!" << endl;

    if (ataque.getPuedeQuemar() && (rand() % 100) < 30)
        defensor.recibirEstado(QUEMADO);
    else if (ataque.getPuedeCongelar() && (rand() % 100) < 20)
        defensor.recibirEstado(CONGELADO);

    mostrarBarraVida(defensor);
}

bool combateFinalizado(const Pokemon &p1, const Pokemon &p2) {
    return p1.getVida() <= 0 || p2.getVida() <= 0;
}

void anunciarGanador(const Pokemon &p1, const Pokemon &p2) {
    cout << GREEN << "\n\n--- Combate Finalizado ---\n" << RESET;
    if (p1.getVida() <= 0 && p2.getVida() <= 0)
        cout << "Empate. Ambos Pokémon cayeron..." << endl;
    else if (p1.getVida() <= 0)
        cout << p2.getNombre() << " es el ganador!" << endl;
    else
        cout << p1.getNombre() << " es el ganador!" << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    vector<Pokemon> listaPokemones = inicializarPokemones();

    cout << "¡Bienvenido al simulador de batalla Pokémon!" << endl;
 int modo;
while (true) {
    cout << "Selecciona el modo de juego:" << endl;
    cout << "1. Jugador vs Bot" << endl;
    cout << "2. Jugador vs Jugador" << endl;
    cout << "> ";

    cin >> modo;

    if (cin.fail() || (modo != 1 && modo != 2)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "Entrada inválida. Por favor, ingresa 1 o 2." << RESET << endl;
    } else {
        break;
    }
}   
    bool vsBot = (modo == 1);

    Pokemon jugador1 = elegirPokemon("Jugador 1", listaPokemones);
    Pokemon jugador2;
    if (vsBot) {
        jugador2 = listaPokemones[rand() % listaPokemones.size()];
        cout << "El bot eligió a " << jugador2.getNombre() << "!" << endl;
    } else {
        jugador2 = elegirPokemon("Jugador 2", listaPokemones);
    }

    cout << YELLOW << "\n¡El combate comienza!" << RESET << endl;

    while (!combateFinalizado(jugador1, jugador2)) {
        if (jugador1.getVelocidad() >= jugador2.getVelocidad()) {
            turnoDeAtaque(jugador1, jugador2, true);
            if (combateFinalizado(jugador1, jugador2)) break;
            turnoDeAtaque(jugador2, jugador1, !vsBot);
        } else {
            turnoDeAtaque(jugador2, jugador1, !vsBot);
            if (combateFinalizado(jugador1, jugador2)) break;
            turnoDeAtaque(jugador1, jugador2, true);
        }
    }

    anunciarGanador(jugador1, jugador2);
    return 0;
}