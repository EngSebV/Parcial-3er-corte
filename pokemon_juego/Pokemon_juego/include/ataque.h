#ifndef ATAQUE_H
#define ATAQUE_H

#include <string>
using std::string;

class Ataque {
private:
    string nombre;
    string tipo;
    int poder;
    bool puedeQuemar;
    bool puedeCongelar;

public:
    Ataque(string nombre, string tipo, int poder, bool puedeQuemar = false, bool puedeCongelar = false);

    // Getters
    string getNombre() const;
    string getTipo() const;
    int getPoder() const;
    bool getPuedeQuemar() const;
    bool getPuedeCongelar() const;
};

#endif
