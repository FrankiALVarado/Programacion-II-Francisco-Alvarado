#pragma once
#include<string>
#include<iostream>
class cNodo
{
private: 
	std::string m_etiqueta;
	double coordx;
	double coordy;
public:
	cNodo();
	cNodo(std::string m_etiqueta, double coordx, double coordy);
	void initializeNode(cNodo & node);
	void setLabel(std::string & label);
	void setLabel(const std::string & label);
	std::string & getLabel();
	void printLabel();
	~cNodo();
};

