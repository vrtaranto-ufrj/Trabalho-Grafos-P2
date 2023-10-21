all: main.o graph.o list.o node.o
	g++ -Wall -fopenmp -o grafo main.o graph.o list.o node.o

main.o: main.cc ./graph/graph.hh ./list/list.hh
	g++ -Wall -fopenmp -c main.cc

graph.o: ./graph/graph.cc ./graph/graph.hh ./list/list.hh
	g++ -Wall -fopenmp -c ./graph/graph.cc

list.o: ./list/list.cc ./list/list.hh ./list/node.hh
	g++ -Wall -fopenmp -c ./list/list.cc

node.o: ./list/node.cc ./list/node.hh
	g++ -Wall -fopenmp -c ./list/node.cc

clean:
	rm -f grafo *.o *.txt

run: all
	./grafo
