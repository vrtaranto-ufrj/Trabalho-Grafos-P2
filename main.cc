#include <iostream>
#include <ctime>

#include "./graph/graph.hh"

using namespace std;



int main( int argc, char *argv[] ) {
    Graph* grafo = new Graph();
    time_t before, now;
    string graf, resp;

    cout << "Bem vindo ao programa de grafos!\n";
    cout << "Digite qual grafo que deseja carregar (1-6): ";
    getline( cin, graf );

    if ( graf <= "6" && graf >= "1" ) {
        graf = "./grafos/grafo_" + graf + ".txt";
    }
    else {
        cout << "Grafo invalido!\n";
        return 1;
    }
    

    cout << "\nCarregar em lista ou matriz? (L/m): ";
    getline( cin, resp );
    
    before = time(nullptr);
    cout << "Alocando memoria para o grafo...\n";
    if ( resp == "M" || resp == "m" )
        grafo->loadMatrix( graf );
    else
        grafo->loadList( graf );
    cout << "Tempo botar alocar na memória: " << time(nullptr) - before << "s\n" << endl;

    while ( true ) {
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
        cout << "Funcoes disponiveis:" << endl;
        cout << "1 - Arvore BFS" << endl;
        cout << "2 - Arvore DFS" << endl;
        cout << "3 - Escrever informacoes" << endl;
        cout << "4 - Distancia entre dois vertices" << endl;
        cout << "5 - Diametro" << endl;
        cout << "6 - Sair\n" << endl;
        cout << "Digite o numero da funcao que deseja executar: ";
        getline( cin, resp );

        switch ( resp[0] ) {
            case '1':
                cout << "Digite o vertice inicial: ";
                getline( cin, resp );
                grafo->bfs( stoi( resp ) );
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
                cout << "Arvore BFS gerada!" << endl << endl;
                break;
            case '2':
                cout << "Digite o vertice inicial: ";
                getline( cin, resp );
                grafo->dfs( stoi( resp ) );
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
                cout << "Arvore DFS gerada!" << endl << endl;
                break;
            case '3':
                grafo->write_informations();
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
                cout << "Informacoes escritas no arquivo!\n" << endl;
                break;
            case '4':
                cout << "Digite os vertices (Ex: v1 v2) : ";
                getline( cin, resp );
                cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
                cout << "Distancia entre os vertice: " << grafo->distance( stoi( resp.substr( 0, resp.find( ' ' ) ) ), stoi( resp.substr( resp.find( ' ' ) + 1 ) ) ) << endl << endl;
                break;
            case '5':
                cout << "Diametro exato ou aproximado? (A/e): ";
                getline( cin, resp );
                if ( resp == "E" || resp == "e" ) {
                    cout << "Quantos threads deseja usar? (Padrao=Maximo): ";
                    getline( cin, resp );
                    if ( resp == "" ) {
                        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
                        cout << "Diametro exato: " << grafo->diameter() << endl << endl;
                    }
                    else {
                        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
                        cout << "Diametro exato: " << grafo->diameter( stoi( resp ) ) << endl << endl;
                    }
                }
                else {
                    cout << "Digite o numero de iteracoes (padrao 50): ";
                    getline( cin, resp );
                    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
                    if ( resp == "" ) {
                        cout << "Diametro aproximado: " << grafo->diameter_aprox() << endl << endl;
                    }
                    else {
                        cout << "Diametro aproximado: " << grafo->diameter_aprox( stoi( resp ) ) << endl << endl;  
                    }
                                
                }
                break;
            case '6':
                cout << "Desalocando memoria do grafo...\n";
                delete grafo;
                cout << "Memoria desalocada!\n";
                return 0;
            default:
                cout << "Funcao invalida!\n";
        }


    }

    //grafo.loadMatrix( graf );
    grafo->loadList( graf );
    now = time(nullptr);
    cout << "Tempo botar grafo na memória: " << now - before << "s\n" << endl;

    before = now;
    grafo->bfs( 4 );
    now = time(nullptr);
    cout << "Tempo para rodar bfs: " << now - before << "s\n" << endl;
    
    before = now;
    grafo->write_informations();
    now = time(nullptr);
    cout << "Tempo botar escrever as informacoes: " << now - before << "s\n" << endl;
        

    before = now;
    cout << "Distancia de 2 vertices: " << grafo->distance( 1, 4 ) << endl;
    now = time(nullptr);
    cout << "Tempo para calcular distancia: " <<  now - before << "s\n" << endl;
    
    before = now;
    //cout << "Diametro: " << grafo.diameter(8) << endl;
    cout << "Diametro: " << grafo->diameter_aprox(100) << endl;
    now = time(nullptr);
    cout << "Tempo calcular o diametro: "<< now - before << "s\n" << endl;
    

    return 0;
}
