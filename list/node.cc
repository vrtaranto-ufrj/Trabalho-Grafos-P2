#include "node.hh"

Node::Node( int _key ) {
    // Inicializa o nó com a chave passada como argumento
    // Argumentos:
    //     _key: chave do nó a ser inicializado

    key = _key;
}

void Node::setNext( Node* _next ){
    // Método para setar o próximo nó
    // Argumentos:
    //     _next: próximo nó

    next = _next;
}

int Node::getKey() {
    // Método para retornar a chave do nó
    // Retorno:
    //     key: chave do nó

    return key;
}

Node* Node::getNext() {
    // Método para retornar o próximo nó
    // Retorno:
    //     next: próximo nó
    
    return next;
}
