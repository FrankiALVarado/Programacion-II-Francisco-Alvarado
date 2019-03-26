#include "cNodoPM.h"



cNodoPM::cNodoPM()
{
}

cNodoPM::cNodoPM(cNodo m_actualNode, int m_distance, cNodoPM * m_ndpm)
{
	m_actualNode;
	m_distance;
	m_ndpm = nullptr;
}

cNodo & cNodoPM::getActualNode()
{
	return m_actualNode;
	// TODO: insertar una instrucción return aquí
}

cNodoPM * cNodoPM::nodePmAddress()
{
	return m_ndpm;
}

int & cNodoPM::getDistance()
{
	return m_distance;
}

void cNodoPM::setNode(cNodo & node)
{
	m_actualNode = node;
}

void cNodoPM::setPointer(cNodoPM & nodepm)
{
	m_ndpm = &nodepm;
}

void cNodoPM::setDistance(int & dist, int & recorrido)
{
	m_distance += dist + recorrido;
}

std::string & cNodoPM::getNPMLabel()
{
	if (m_ndpm != nullptr) {
		return m_ndpm->getActualNode().getLabel();
	}
	else {
		std::string vacio = "vacio";
		return vacio;
	}
}


void cNodoPM::initializeStarterPM()
{
	m_actualNode;
	m_distance = 0;
	m_ndpm = nullptr;
}

void cNodoPM::printnodePM()
{
	std::cout << m_actualNode.getLabel() << std::endl;
	std::cout << m_distance << std::endl;
	if (m_ndpm != nullptr) {
		std::cout << m_ndpm->getActualNode().getLabel() << std::endl;
	}
	else {
		std::cout << "null" << std::endl;
	}
}

cNodoPM * cNodoPM::getPointer()
{
	return m_ndpm;
}


cNodoPM::~cNodoPM()
{
}
