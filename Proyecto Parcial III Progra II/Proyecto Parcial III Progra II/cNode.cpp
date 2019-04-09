#include "cNode.h"



cNode::cNode()
{
	m_IATACode = "";
	m_label = "";
	m_totalDistance = 0;
	m_coordx = 0;
	m_coordy = 0;
	m_ptrlastNode = nullptr;
}

cNode::cNode(std::string label, float totaldistance)
{
	m_label = label;
	m_totalDistance = 0;
	m_ptrlastNode == nullptr;
}

cNode::~cNode()
{
}

std::string & cNode::getLabel()
{
	return m_label;
}

std::string & cNode::getLabel2()
{
	if (m_ptrlastNode != nullptr) {
		return m_ptrlastNode->getLabel();
	}
}

cNode * cNode::getPointer()
{
	if (m_ptrlastNode != nullptr) {
		return m_ptrlastNode;
	}
	else
		return nullptr;
}

float & cNode::getDistance()
{
	return m_totalDistance;
}

float & cNode::getCoordX()
{
	return m_coordx;
}

float & cNode::getCoordY()
{
	return m_coordy;
}

std::string & cNode::getIATACode()
{
	return m_IATACode;
}

void cNode::setIATACode(std::string iata)
{
	m_IATACode = iata;
}

void cNode::setLabel(std::string label)
{
	m_label = label;
}

void cNode::setCoordX(float coord)
{
	m_coordx = coord;
}

void cNode::setCoordY(float coord)
{
	m_coordy = coord;
}

void cNode::setDistance(float & weight, float & distance)
{
	m_totalDistance += weight + distance;
}

void cNode::setDistance(const float & distance)
{
	m_totalDistance = distance;
}

void cNode::setPointer(cNode & nodepm)
{
	m_ptrlastNode = &nodepm;
}

void cNode::printLabel()
{
	std::cout << "Codigo IATA: " << m_IATACode << std::endl;
	std::cout << "Ciudad: " << m_label << std::endl;
}

void cNode::printNodePM()
{
	std::cout << m_label << "\n";
	std::cout << m_totalDistance << "\n";
	if (m_ptrlastNode != nullptr) {
		std::cout << m_ptrlastNode->getLabel() << "\n";
	}
	else
		std::cout << "NULL" << "\n";
}
