#pragma once
#include <iostream>
#include <string>
using std::cin;
using std::endl;
using std::cout;
using std::string;

class cNodo
{
public:
	cNodo();
	string m_pregunta;
	cNodo * m_hijoIzq;
	cNodo *m_hijoDer;
	cNodo(string m_pregunta,  cNodo * m_hijoIzq, cNodo * m_hijoDer);
	void inicializarCategoria(cNodo & node);
	void inicializarMiembro(cNodo & nodo);
	void inicializarMiembro(cNodo & nodo, const string & pregunta); // inicializar raiz y sus hijos con esta función
	void inicializarNodo(cNodo & nodo);
	void inicializarNodo(cNodo & nodo, const string & pregunta);
	~cNodo();
};

