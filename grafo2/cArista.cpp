#include "cArista.h"



cArista::cArista()
{
}


cArista::cArista(cNodo * m_vertice1, cNodo * m_vertice2, int m_valor)
{
	m_vertice1 = nullptr;
	m_vertice2 = nullptr;
	m_valor = 0;
}

void cArista::initializeEdge(cArista & edge)
{
	edge.m_vertice1 = nullptr;
	edge.m_vertice2 = nullptr;
	m_valor = 1;
}

void cArista::printEdge()
{
	std::cout << m_vertice1->getLabel() << " apunta a : " << m_vertice2->getLabel() << " con un peso de: " << m_valor << std::endl;
	
}

void cArista::setEdge(cNodo & vertice1, cNodo & vertice2, int & valor)
{
	m_vertice1 = &vertice1; //nodo que apunta
	m_vertice2 = &vertice2; //nodo que es apuntado
	m_valor = valor; // peso de la arista
}

std::string cArista::getFirstNodeLabel()
{
	return m_vertice1->getLabel();
}

std::string cArista::getSecondNodeLabel()
{
	return m_vertice2->getLabel();
}

int & cArista::getWeight()
{
	return m_valor;
}

void cArista::copySecondNode(cNodo & copy)
{
	copy.setLabel(m_vertice2->getLabel()) ;

}

cNodo & cArista::getSecondNode()
{
	return *m_vertice2;
}

cArista::~cArista()
{

}
