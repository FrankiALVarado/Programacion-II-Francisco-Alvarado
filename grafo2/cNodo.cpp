#include "cNodo.h"



cNodo::cNodo()
{
}

cNodo::cNodo(std::string m_etiqueta, double coordx, double coordy)
{
	m_etiqueta = "";
	coordx = 0;
	coordy = 0;
}



void cNodo::initializeNode(cNodo & node)
{

	node.m_etiqueta = "";
	node.coordx = 0;
	node.coordy = 0;
}

void cNodo::setLabel(std::string & label)
{
	m_etiqueta = label;
}

void cNodo::setLabel(const std::string & label)
{
	m_etiqueta = label;
}


std::string & cNodo::getLabel()
{
	return m_etiqueta;
}

void cNodo::printLabel()
{
	std::cout << "etiqueta: " << m_etiqueta << std::endl;
}

cNodo::~cNodo()
{
	
}
