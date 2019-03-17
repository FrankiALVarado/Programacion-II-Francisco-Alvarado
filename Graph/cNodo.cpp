#include "cNodo.h"



cNodo::cNodo()
{
}


cNodo::cNodo(std::string m_etiqueta, int * m_valor)
{
	m_etiqueta = "";
	m_valor = nullptr;
}

void cNodo::initializeNode(cNodo & node)
{

	node.m_etiqueta = "";
	node.m_valor = nullptr;
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
