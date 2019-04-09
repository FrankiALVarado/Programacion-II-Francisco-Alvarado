#include "cEdge.h"



cEdge::cEdge()
{
	m_node1 = nullptr;
	m_node2 = nullptr;
	m_weight = 0;
}


cEdge::~cEdge()
{
	/*if (m_node1 != nullptr) {
		std::cout << "eliminando nodo " << m_node1->getLabel();
		delete m_node1;
	}
	if (m_node2 != nullptr) {
		std::cout << "eliminando nodo " << m_node2->getLabel();
		delete m_node2;
	}*/
}

std::string & cEdge::getFirstNodeIATACode()
{
	return m_node1->getIATACode();
}

std::string & cEdge::getFirstNodeLabel()
{
	return m_node1->getLabel();
}

std::string & cEdge::getSecondNodeLabel()
{
	return m_node2->getLabel();
}

std::string & cEdge::getSecondNodeIATACode()
{
	return m_node2->getIATACode();
}

float & cEdge::getWeight()
{
	return m_weight;
}

cNode & cEdge::getSecondNode()
{
	return *m_node2;
}

void cEdge::setEdge(cNode & node1, cNode & node2, float  value)
{
	m_node1 = &node1;
	m_node2 = &node2;
	m_weight = value;
}
