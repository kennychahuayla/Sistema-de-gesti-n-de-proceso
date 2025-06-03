#ifndef PILA_MEMORIA_H
#define PILA_MEMORIA_H

#include <stack>
#include <iostream>

class PilaMemoria {
private:
    std::stack<int> memoria;
public:
    void asignarMemoria(int procesoID) {
        memoria.push(procesoID);
        std::cout << "Memoria asignada al proceso ID " << procesoID << "\n";
    }
    void liberarMemoria() {
        if (!memoria.empty()) {
            int id = memoria.top();
            memoria.pop();
            std::cout << "Memoria liberada del proceso ID " << id << "\n";
        } else {
            std::cout << "No hay memoria para liberar\n";
        }
    }
    void mostrar() {
        std::cout << "Procesos con memoria asignada: " << memoria.size() << "\n";
    }
};

#endif