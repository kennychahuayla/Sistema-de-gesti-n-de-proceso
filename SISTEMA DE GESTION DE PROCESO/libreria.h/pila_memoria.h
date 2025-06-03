#ifndef PILA_MEMORIA_H
#define PILA_MEMORIA_H

#include <stack>
#include <iostream>
using namespace std;
class PilaMemoria {
private:
    stack<int> memoria;
public:
    void asignarMemoria(int procesoID) {
        memoria.push(procesoID);
        cout << "Memoria asignada al proceso ID " << procesoID << "\n";
    }
    void liberarMemoria() {
        if (!memoria.empty()) {
            int id = memoria.top();
            memoria.pop();
            cout << "Memoria liberada del proceso ID " << id << "\n";
        } else {
            cout << "No hay memoria para liberar\n";
        }
    }
    void mostrar() {
        cout << "Procesos con memoria asignada: " << memoria.size() << "\n";
    }
};

#endif
