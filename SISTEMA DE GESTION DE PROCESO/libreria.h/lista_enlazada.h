#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

#include <iostream>
#include "proceso.h"

using namespace std;

struct Nodo {
    Proceso proceso;
    Nodo* siguiente;

    Nodo(Proceso p) : proceso(p), siguiente(NULL) {}  // 
};

class ListaEnlazada {
private:
    Nodo* cabeza;

public:
    ListaEnlazada() : cabeza(NULL) {}  // 

    void insertar(Proceso p) {
        Nodo* nuevo = new Nodo(p);
        if (!cabeza) {
            cabeza = nuevo;
        } else {
            Nodo* temp = cabeza;
            while (temp->siguiente)
                temp = temp->siguiente;
            temp->siguiente = nuevo;
        }
    }

    void mostrar() {
        Nodo* temp = cabeza;
        cout << "\n--- Lista de procesos ---\n";
        while (temp) {
            cout << "ID: " << temp->proceso.id
                 << ", Nombre: " << temp->proceso.nombre
                 << ", Prioridad: " << temp->proceso.prioridad << endl;
            temp = temp->siguiente;
        }
    }

    Proceso* buscar(int id) {
        Nodo* temp = cabeza;
        while (temp) {
            if (temp->proceso.id == id)
                return &temp->proceso;
            temp = temp->siguiente;
        }
        return NULL;
    }

    bool eliminar(int id) {
        Nodo* temp = cabeza;
        Nodo* anterior = NULL;
        while (temp) {
            if (temp->proceso.id == id) {
                if (anterior)
                    anterior->siguiente = temp->siguiente;
                else
                    cabeza = temp->siguiente;
                delete temp;
                return true;
            }
            anterior = temp;
            temp = temp->siguiente;
        }
        return false;
    }

    ~ListaEnlazada() {
        while (cabeza) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
};

#endif

