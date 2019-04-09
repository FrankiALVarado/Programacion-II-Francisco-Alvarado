#pragma once
#include <string>
#include <iostream>
class cNode
{
private:
	std::string m_IATACode;
	std::string m_label; // etiqueta
	float m_totalDistance; // distancia reccorida
	float m_coordx; // latitud
	float m_coordy; // longitud
	cNode* m_ptrlastNode; // puntero hacia el nodo anterior 

public:
	//constructores
	cNode();
	cNode(std::string label, float totaldistance); //constructor para nodo inicial de nodepm y dijsktra
	//destructor
	~cNode();

	//getters
	float & getDistance();
	float & getCoordX();
	float & getCoordY();
	std::string & getIATACode(); // regresa el código IATA
	std::string & getLabel(); //regresa la etiqueta del nodo
	std::string & getLabel2(); //regresa la etiqueta desde donde viene el nodo
	cNode * getPointer();

	//setters
	void setIATACode(std::string iata);
	void setLabel(std::string label);
	void setCoordX(float coord);
	void setCoordY(float coord);
	void setDistance(float & weight, float & distance);
	void setDistance(const float & distance);
	void setPointer(cNode & nodepm);

	//printers
	void printLabel();
	void printNodePM();
};

