#pragma once
#include "Nodo.h"
class cArbol
{
public:
	cArbol();
	cNodo * m_raiz;
	cArbol(cNodo *m_raiz);
	cNodo * crearRaiz();
	void incializarRaiz();
	void akinator(cNodo & nodo);
	void insertarNodo(cNodo & nodo, cNodo & padre);
	void imprimirArbol(cNodo & node);
	void crearHijosRaiz(cNodo & padre);
	void crearMiembrosHijos(cNodo & izq, cNodo & der);
	cNodo * crearCategoria();
	cNodo *crearCategoria(const string & pregunta);
	cNodo * crearMiembro();
	cNodo *crearMiembro(const string & pregunta);
	cNodo & lastNode(cNodo & nodo);
	int conteomax(cNodo & nodo, int & nivel, int & mayor);
	int conteo(cNodo & nodo);
	void balanceo();

	~cArbol();
};

