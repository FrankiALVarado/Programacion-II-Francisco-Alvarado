#pragma once
#include<string>
#include<iostream>
class cNodo
{
private: 
	std::string m_etiqueta;
	int * m_valor;
public:
	cNodo();
	cNodo(std::string m_etiqueta, int * m_valor);
	void initializeNode(cNodo & node);
	void setLabel(std::string & label);
	void setLabel(const std::string & label);
	std::string & getLabel();
	void printLabel();
	~cNodo();
};

