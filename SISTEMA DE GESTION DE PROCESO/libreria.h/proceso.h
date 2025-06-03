#ifndef PROCESO_H
#define PROCESO_H

#include <string>

struct Proceso {
    int id;
    std::string nombre;
    int prioridad;
    Proceso(int i, std::string n, int p) : id(i), nombre(n), prioridad(p) {}
};

#endif
