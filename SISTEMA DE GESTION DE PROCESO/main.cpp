#include <iostream>
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
        std::cout << "\n--- MENÚ PRINCIPAL ---\n";
        std::cout << "1. Registrar proceso\n";
        std::cout << "2. Ejecutar proceso\n";
        std::cout << "3. Liberar memoria\n";
        std::cout << "4. Mostrar estructuras\n";
        std::cout << "5. Salir\n";
        std::cout << "Ingrese opción: ";
        std::cin >> opcion;
        switch(opcion) {
            case 1: {
                int id, prioridad;
                std::string nombre;
                std::cout << "ID: "; std::cin >> id;
                std::cout << "Nombre: "; std::cin >> nombre;
                std::cout << "Prioridad (1=Alta, 2=Media, 3=Baja): "; std::cin >> prioridad;
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
