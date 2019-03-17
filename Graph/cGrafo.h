#pragma once
#include "cArista.h"
#include <vector>
#include <fstream>
#include <sstream>
class cGrafo
{
private:
	void getFromText(std::ifstream & text);
	void initializeGraphFromText(std::ifstream & text);
	void depthFirstSearch(int & contador, int & nodos, cNodo & actual, cNodo & buffer, std::vector<cNodo> & abiertos, std::vector<cNodo> & cerrados);
	void breadthFirstSearch(int & contador, int & nodos, cNodo & actual, cNodo & buffer, std::vector<cNodo> & abiertos, std::vector<cNodo> & cerrados);
	bool isInVector(cNodo & node, std::vector<cNodo> & vector2);
	std::vector<cNodo> m_nodos;
	std::vector<cArista> m_aristas;

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

