#include <iostream>
#include "pokemon.h"
#include "pokedex.h"

using namespace std;

void showPokemonStatus(const Pokemon& p) {
    cout << p.name << " HP: " << p.currentHP << "/" << p.maxHP << endl;
}

void showMenu(const Pokemon& p) {
    cout << "Turno de " << p.name << ". Elige un ataque:" << endl;
    cout << "1. " << p.attacks[0].name << " (daño: " << p.attacks[0].damage << ")" << endl;
    cout << "2. " << p.attacks[1].name << " (daño: " << p.attacks[1].damage << ")" << endl;
    cout << "Opción: ";
}

void attack(Pokemon& attacker, Pokemon& defender, int attackIndex) {
    int damage = attacker.attacks[attackIndex].damage;
    defender.currentHP -= damage;
    if (defender.currentHP < 0) defender.currentHP = 0;
    cout << attacker.name << " usó " << attacker.attacks[attackIndex].name << " y causó " << damage << " puntos de daño." << endl;
    showPokemonStatus(defender);
}

int main() {
    Pokemon pikachu = createPikachu();
    Pokemon charmander = createCharmander();

    while (pikachu.currentHP > 0 && charmander.currentHP > 0) {
        showMenu(pikachu);
        int choice;
        cin >> choice;
        while (choice < 1 || choice > 2) {
            cout << "Opción inválida, elige 1 o 2: ";
            cin >> choice;
        }
        attack(pikachu, charmander, choice - 1);
        if (charmander.currentHP == 0) break;

        showMenu(charmander);
        cin >> choice;
        while (choice < 1 || choice > 2) {
            cout << "Opción inválida, elige 1 o 2: ";
            cin >> choice;
        }
        attack(charmander, pikachu, choice - 1);
    }

    if (pikachu.currentHP > 0) {
        cout << "¡" << pikachu.name << " ha ganado!" << endl;
    } else {
        cout << "¡" << charmander.name << " ha ganado!" << endl;
    }

    return 0;
}
