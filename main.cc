#include <iostream>
#include <ctime>

#include "./graph/graph.hh"

using namespace std;


int main( int argc, char *argv[] ) {
    time_t inicio;
    Graph* grafo = new Graph();
    inicio = time( NULL );
    grafo->loadList( argv[1] );
    cout << "tempo para guardar na memoria: " << time( NULL ) - inicio << "s" << endl;
    //grafo->printList();
    float distancia;
    

    int vezes = 1;
    inicio = time( NULL );
    for ( int i = 0; i < vezes; i++ ) {
        distancia = grafo->dijkstra_heap( i ); 
    }
    cout << "tempo do dijkstra: " << (time( NULL ) - inicio)/(vezes * 1.0) << "s" << endl;

    return 0;
}
