#ifndef LIST_HH
#define LIST_HH
#include "node.hh"

class List {
    public:
        List();
        ~List();

        void insertNode( int key );

        // Getters
        Node* getHead();

    private:
        Node* head;

};

#endif