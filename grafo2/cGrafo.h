#pragma once
#include "cArista.h"
#include <vector>
#include <fstream>
#include <sstream>
#include "cNodoPM.h"
class cGrafo
{
private:
	void getFromText(std::ifstream & text);
	void initializeGraphFromText(std::ifstream & text);
	void depthFirstSearch(int & contador, int & nodos, cNodo & actual, cNodo & buffer, std::vector<cNodo> & abiertos, std::vector<cNodo> & cerrados, std::string & lastlabel);
	void breadthFirstSearch(int & contador, int & nodos, cNodo & actual, cNodo & buffer, std::vector<cNodo> & abiertos, std::vector<cNodo> & cerrados);
	void primeroMejorOutput();
	void primeroMejor(int & contador, std::vector<cNodoPM> & abiertos, std::vector<cNodoPM> & cerrados, cNodoPM & start, std::string & lastLabel);
	bool isInVector(cNodo & node, std::vector<cNodo> & vector2);
	bool isinVector(cNodoPM & nodepm, std::vector<cNodoPM> & vector);
	void loadOutput();
	std::vector<cNodo> m_nodos;
	std::vector<cArista> m_aristas;
	void quicksort(std::vector<cNodoPM> & vector, int min_index, int max_index);
	int sublistas(std::vector<cNodoPM> & vector, int & min_index, int & max_index);
	void ordenar(cNodoPM & nodepm1, cNodoPM & nodepm2);
	void mejorNodoPM(std::vector<cNodoPM> & cerrados, std::string & lastLabel);
	void mejorRutaPM(cNodoPM & ganador);
public:
	cGrafo();
	cGrafo(std::vector<cNodo> m_nodos, std::vector<cArista> m_aristas);
	//cNodo * m_nodes;
	//cArista * m_edges;
	//cGrafo(cNodo * m_nodes, cArista * m_edges);
	~cGrafo();
	
	void graphMenu();
	void printGraph();
};

