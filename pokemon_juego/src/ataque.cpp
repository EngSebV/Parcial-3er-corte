#include "ataque.h"

Ataque::Ataque(string nombre, string tipo, int poder, bool puedeQuemar, bool puedeCongelar)
    : nombre(nombre), tipo(tipo), poder(poder), puedeQuemar(puedeQuemar), puedeCongelar(puedeCongelar)
{ }

string Ataque::getNombre() const {
    return nombre;
}

string Ataque::getTipo() const {
    return tipo;
}

int Ataque::getPoder() const {
    return poder;
}

bool Ataque::getPuedeQuemar() const {
    return puedeQuemar;
}

bool Ataque::getPuedeCongelar() const {
    return puedeCongelar;
}
