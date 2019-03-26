#pragma once
#include "cNodo.h"
class cArista
{
private:
	cNodo * m_vertice1; // vértice que apunta
	cNodo * m_vertice2; // vértice que es apuntado
	int m_valor;
public:
	cArista();
	cArista(cNodo * m_vertice1, cNodo * m_vertice2, int m_valor);
	void initializeEdge(cArista & edge); //inicializacion de la clase
	void printEdge(); //impresion en consola de la clase
	void setEdge(cNodo & vertice1, cNodo & vertice2, int & valor); // darle un puntero a sus clases
	void copySecondNode(cNodo & copy);
	cNodo & getSecondNode();//funcion utilizadas para busquedas
	std::string getFirstNodeLabel(); //funcion utilizadas para busquedas
	std::string getSecondNodeLabel();
	int & getWeight();
	~cArista();
};

