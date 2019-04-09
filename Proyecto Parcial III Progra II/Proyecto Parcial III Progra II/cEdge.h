#pragma once
#include "cNode.h"
class cEdge
{
private:
	cNode * m_node1,* m_node2; // Node1 es el nodo que apunta, Node2 es el nodo que es apuntado
	float m_weight; // peso de la arista
public:
	//constructor
	cEdge();
	//destructor
	~cEdge();

	//getters
	std::string & getFirstNodeIATACode(); //devuelve el codigo iata del nodo que apunta
	std::string & getFirstNodeLabel(); //devuelve la etiqueta del primer nodo(el que apunta)
	std::string & getSecondNodeLabel(); //devuelve la etiqueta dle segunod nodo (el que es apuntado
	std::string & getSecondNodeIATACode(); // devuelve el codigo iata del nodo que es apuntado
	float & getWeight();
	cNode & getSecondNode();

	//setters
	void setEdge(cNode & node1, cNode & node2, float  value); // darle un puntero a sus miembros y un peso a la arista
};

