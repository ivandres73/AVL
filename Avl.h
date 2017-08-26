
#ifndef AVL_AVL_H
#define AVL_AVL_H

#include "Node.h"
#include <iostream>

using namespace std;

class Avl {
public:
    Avl();
    ~Avl();
    int insert(int);
    void print();
    void preOrden();

    Node* root;

private:

    int insert(int, Node*&);
    void print(Node*, int);
    void preOrden(Node*);
    void rotarIzq(Node*&);
    void rotarDer(Node*&);
    void rotarIzqDoble(Node*&);
    void rotarDerDoble(Node*&);
    void balance(Node*&);
    int cantidadNodos;

};


#endif //AVL_AVL_H
