#pragma once
#include <vector>
#include <cmath>
#include "cEdge.h"
class cPathFinding
{
protected:
	cNode m_buffer;
	std::vector<cNode> m_open;
	std::vector<cNode> m_closed;
public:
	//constructores
	cPathFinding();
	cPathFinding(std::vector<cNode> _open, std::vector<cNode> _closed, cNode _buffer);
	//funciones virtuales
	virtual void pathFind(int & contador, cNode & lastLabel, bool & arriv, std::vector<cEdge> & edges) = 0; //algoritmo de busqueda a implementar

	//funciones
	bool isInVector(cNode & node, std::vector<cNode> vector); //funcion que regresa verdadero si una etiqueta ya está en un vector
	void freeVector(); //funcion para liberar completamente el espacio de los vectores después de usarlos
	void winnerRoute(std::vector<cNode> & nodes, cNode & last); //funcion que regresa el nodo con la ultima etiqueta para saber su recorrido
	void printRoute(cNode & node); // funcion para imprimir la ruta ganadora
	void printClosed();
	void pushBackFirstNode(cNode & node);
	//-----------------------------------------------------------------------------------------------------------------------------

	//Quicksort--------------------------------------------------------------------------------------------------------------------
	void quicksort(std::vector<cNode> & vector, int min_index, int max_index);
	int subarray(std::vector<cNode> & vector, int & min_index, int & max_index);
	void swap(cNode & node1, cNode & node2);
	//----------------------------------------------------------------------------------------------------------------------------

   //std::string & setInitialNodeLabel();
   // std::string & setLastNodeLabel();
};

class cDepthFirstSearch : public cPathFinding
{
	
private:
	void pathFind(int & counter, cNode & lastLabel, bool & arrive, std::vector<cEdge> & edge);
	
public:
	//constructor
	cDepthFirstSearch(std::vector<cNode> _open, std::vector<cNode> _closed, cNode _buffer) :cPathFinding(_open, _closed, _buffer) {};
	//destructor
	~cDepthFirstSearch();
};

class cBreadthFirstSearch : public cPathFinding
{

private:
	void pathFind(int & counter, cNode & lastLabel, bool & arrive, std::vector<cEdge> & edge);
public:
	//constructor
	cBreadthFirstSearch(std::vector<cNode> _open, std::vector<cNode> _closed, cNode _buffer) :cPathFinding(_open, _closed, _buffer) {};
	//destructor
	~cBreadthFirstSearch();
};

class cBestFirst : public cPathFinding
{
private:
	//void printRoute(cNode & node); // funcion para imprimir la ruta
	//void winnerRoute(std::vector<cNode> & nodes, cNode & last); //funcion que regresa el nodo con la ultima etiqueta para saber su recorrido
	void pathFind(int & counter, cNode & lastLabel, bool & arriv, std::vector<cEdge> & edges);
	bool isInVector(cNode & node, std::vector<cNode> & vector);
public:
	//constructor
	cBestFirst(std::vector<cNode> _open, std::vector<cNode> _closed, cNode _buffer) :cPathFinding(_open, _closed, _buffer) {};
	//destructor
	~cBestFirst();
};

class cDijkstra : public cPathFinding
{
private:
	void Radians(cNode & node);
	float & haversine(cNode & node1, cNode & node2);
	void lessTravel(cNode & actual, std::vector<cNode> vector);
	void pathFind(int & contador, cNode & lastLabel, bool & arriv, std::vector<cEdge> & edges);
public:
	//constructor
	cDijkstra(std::vector<cNode> _open, std::vector<cNode> _closed, cNode _buffer) :cPathFinding(_open, _closed, _buffer) {};
	//destructor
	~cDijkstra();
};

class caStar : public cPathFinding
{
private:
	void Radians(cNode & node);
	float & haversine(cNode & node1, cNode & node2);
	void lessTravel(cNode & actual, std::vector<cNode> vector);
	void pathFind(int & contador, cNode & lastLabel, bool & arriv, std::vector<cEdge> & edges);
public:
	//constructor
	caStar(std::vector<cNode> _open, std::vector<cNode> _closed, cNode _buffer) :cPathFinding(_open, _closed, _buffer) {};
	//destructor
	~caStar();
};