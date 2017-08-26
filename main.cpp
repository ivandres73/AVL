#include <iostream>

#include "Avl.h"

void test (Avl& a) {
    a.insert(8);
    a.insert(7);
    a.insert(6);
}

int main() {
    Avl arbol = Avl();
    short op;
    int aux;
    do {
        cout << "1. Insertar nodo\n";
        cout << "2. Imprimir Arbol\n";
        cout << "3. Pre Orden\n";
        cout << "4. Proximamente\n";
        cout << "5. Proximamente\n";
        cout << "6. Salir\n";
        cin >> op;
        switch (op) {
            case 1:
                cout << "Coloque el numero: ";
                cin >> aux;
                arbol.insert(aux);
                break;
            case 2:
                arbol.print();
                break;
            case 3:
                arbol.preOrden();
                break;
            case 4:

                break;
            case 5:
                break;
        }
    } while (op != 6);
    return 0;
}