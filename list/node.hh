#ifndef NODE_HH
#define NODE_HH

class Node {
    public:
        Node( int _key );

        // Setters
        void setNext( Node* _next );

        // Getters
        int getKey();
        Node* getNext();

    private:
        int key;
        Node* next;
};

#endif
