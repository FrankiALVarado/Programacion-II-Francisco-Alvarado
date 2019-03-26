#pragma once
#include "cNodo.h"
class cNodoPM
{
	friend class cNodo;
private:
	cNodo m_actualNode;
	int m_distance;
	cNodoPM * m_ndpm;
public:
	cNodoPM();
	cNodoPM(cNodo m_actualNode, int m_distance, cNodoPM * m_ndpm);
	cNodo & getActualNode();
	cNodoPM * nodePmAddress();
	int & getDistance();
	void setNode(cNodo & node);
	void setPointer(cNodoPM & nodepm);
	void setDistance(int & dist, int & recorrido);
	std::string & getNPMLabel();
	void initializeStarterPM();
	void printnodePM();
	cNodoPM * getPointer();
	~cNodoPM();
};

