#include <iostream>
using namespace std;
#include "proceso.h"
#include "lista_enlazada.h"
#include "cola_prioridad.h"
#include "pila_memoria.h"

int main() {
	setlocale(LC_CTYPE,"Spanish");
    ListaEnlazada lista;
    ColaPrioridad cola;
    PilaMemoria pila;
    int opcion;
    do {
        cout << "\n--- MENÚ PRINCIPAL ---\n";
        cout << "1. Registrar proceso\n";
        cout << "2. Ejecutar proceso\n";
        cout << "3. Liberar memoria\n";
        cout << "4. Mostrar estructuras\n";
        cout << "5. Salir\n";
        cout << "Ingrese opción: ";
        cin >> opcion;
        switch(opcion) {
            case 1: {
                int id, prioridad;
                string nombre;
                cout << "ID: "; std::cin >> id;
                cout << "Nombre: "; std::cin >> nombre;
                cout << "Prioridad (1=Alta, 2=Media, 3=Baja): "; std::cin >> prioridad;
                Proceso p(id, nombre, prioridad);
                lista.insertar(p);
                cola.encolar(p);
                pila.asignarMemoria(id);
                break;
            }
            case 2:
                cola.ejecutar();
                break;
            case 3:
                pila.liberarMemoria();
                break;
            case 4:
                lista.mostrar();
                cola.mostrar();
                pila.mostrar();
                break;
        }
    } while (opcion != 5);
    return 0;
}
