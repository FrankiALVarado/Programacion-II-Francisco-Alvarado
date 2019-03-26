/*
Labores por terminar:
Clases nodo(string etiqueta, puntero a int), arista(dos punteros, uno a cada vertice que se une), grafo(vector de ambos) - listo
funciones para leer desde archivo - listo;
depth first search - falta empezar;
*/

#include "cGrafo.h"
#include <iostream>
#include <fstream>

int main() {
	cGrafo grafo;
	//grafo.initializeGraph();
	grafo.graphMenu();
	//grafo.printGraph();

	std::cin.ignore();
	std::cin.get();
	return 0;
}