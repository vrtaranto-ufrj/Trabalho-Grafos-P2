#include "list.hh"

List::List() {
    // Inicializa a lista vazia

    head = nullptr;
}

List::~List() {
    // Deleta todos os nós da lista

    Node* no;

    while ( head != nullptr ) {
        no = head->getNext();
        delete head;
        head = no;
    }

}

void List::insertNode( int key ) {
    // Método para inserir um nó na lista
    // Argumentos:
    //     key: chave do nó a ser inserido

    Node* newNode = new Node( key );
    newNode->setNext( head );
    head = newNode;
}

Node* List::getHead() {
    // Método para retornar o nó cabeça da lista
    // Retorno:
    //     head: nó cabeça da lista
    
    return head;
}
