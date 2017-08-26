
#include <cstring>
#include "Node.h"

Node::Node() {
    value = -1;
    numNodo = -1;
    right = 0;
    left = 0;
    father = 0;
    rheight = 0;
    lheight = 0;
}

Node::Node(int valor, int num) {
    value = valor;
    numNodo = num;
    right = 0;
    left = 0;
    father = 0;
    rheight = 0;
    lheight = 0;
}

Node::Node(int valor, Node * padre, int num) {
    valor = valor;
    numNodo = num;
    right = 0;
    left = 0;
    father = padre;
    rheight = 0;
    lheight = 0;
}

char *Node::toChar() {
    char* datos = new char[16];
    int pos = 0;
    memcpy(&datos[0], &numNodo, 4);
    pos += 4;
    memcpy(&datos[pos], &value, 4);
    pos += 4;
}

void Node::fromChar(char *) {

}
