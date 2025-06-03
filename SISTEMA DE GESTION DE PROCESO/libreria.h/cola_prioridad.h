#ifndef COLA_PRIORIDAD_H
#define COLA_PRIORIDAD_H

#include <queue>
#include <vector>
#include <iostream>
#include "proceso.h"

class ColaPrioridad {
private:
    struct Comparador {
        bool operator()(Proceso a, Proceso b) {
            return a.prioridad > b.prioridad; // menor valor = mayor prioridad
        }
    };
    std::priority_queue<Proceso, std::vector<Proceso>, Comparador> cola;
public:
    void encolar(Proceso p) {
        cola.push(p);
    }
    void ejecutar() {
        if (!cola.empty()) {
            Proceso p = cola.top();
            cola.pop();
            std::cout << "Ejecutando proceso ID " << p.id << ": " << p.nombre << "\n";
        } else {
            std::cout << "No hay procesos por ejecutar\n";
        }
    }
    void mostrar() {
        std::cout << "Procesos listos para ejecución: " << cola.size() << "\n";
    }
};

#endif
