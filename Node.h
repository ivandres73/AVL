
#ifndef AVL_NODE_H
#define AVL_NODE_H

#include <string.h>

class Node {
public:
    Node();
    Node(int, int);
    Node(int, Node*, int);
    ~Node();

    int value;
    int numNodo;
    Node* left;
    Node* right;
    Node* father;
    int rheight, lheight;

    char* toChar();
    void fromChar(char*);
};


#endif //AVL_NODE_H
