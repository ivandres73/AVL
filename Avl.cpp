
#include "Avl.h"

Avl::Avl() {
    root = 0;
    cantidadNodos = 0;
}

Avl::~Avl() {

}

int Avl::insert(int valor) {
    insert(valor, this->root);
}

int  Avl::insert(int valor, Node*& root) {
    if (root == 0) {
        Node* nuevo = new Node(valor, cantidadNodos++);
        root = nuevo;
        return 0;
    }
    if (valor < root->value) {
        int h = insert(valor, root->left);
        root->lheight = h + 1;
    } else {
        int h = insert(valor, root->right);
        root->rheight = h + 1;
    }
    balance(root);
    return (root->rheight < root->lheight) ? root->lheight : root->rheight;
}

void Avl::print() {
    print(root, 0);
}

void Avl::print(Node* root, int conta) {
    if (root == 0) {
        return;
    }
    print(root->right, conta+1);
    for (int i=0; i < conta; i++) {
        cout << "   ";
    }
    cout << root->value << endl;
    print(root->left, conta+1);
}

void Avl::preOrden() {
    preOrden(root);
    cout << endl;
}

void Avl::preOrden(Node* root) {
    if (root == 0) {
        return;
    }
    cout << root->value << ": altura izq " << root->lheight << ", altura der " << root->rheight << endl;
    preOrden(root->left);
    preOrden(root->right);
}

void Avl::rotarIzq(Node*& root) {
    root->rheight = root->right->lheight;
    root->right->lheight++;
    Node* _rightSon = root->right;
    //int tmpheight = root->rheight;
    root->right = _rightSon->left;
    _rightSon->left = root;
    root = _rightSon;
    //root->left->rheight = root->lheight;
    //root->lheight = tmpheight - 1;
}

void Avl::rotarDer(Node*& root) {
    root->lheight = root->left->rheight;
    root->left->rheight++;
    Node* _leftSon = root->left;
    //int tmpheight = root->lheight;
    root->left = _leftSon->right;
    _leftSon->right = root;
    root = _leftSon;
    //root->right->lheight = root->rheight;
    //root->rheight = tmpheight - 1;
}

void Avl::rotarIzqDoble(Node*& root) {
    rotarDer(root->right);
    rotarIzq(root);
}

void Avl::rotarDerDoble(Node*& root) {
    rotarIzq(root->left);
    rotarDer(root);
}

void Avl::balance(Node*& root) {
    int alturaIzq = root->lheight;
    int alturaDer = root->rheight;
    if (alturaIzq - alturaDer == 2) {
        Node* _hi = root->left;
        if (_hi->lheight >= _hi->rheight) {
            rotarDer(root);
        } else {
            rotarDerDoble(root);
        }
    } else if (alturaIzq - alturaDer == -2) {
        Node* _hd = root->right;
        if (_hd->lheight <= _hd->rheight) {
            rotarIzq(root);
        } else {
            rotarIzqDoble(root);
        }
    }
}