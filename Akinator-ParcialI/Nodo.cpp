#include "Nodo.h"



cNodo::cNodo()
{
}


cNodo::cNodo(string m_pregunta,  cNodo * m_hijoIzq, cNodo * m_hijoDer)
{
	m_pregunta = "";
	m_hijoIzq = nullptr;
	m_hijoDer = nullptr;
}

void cNodo::inicializarCategoria(cNodo & nodo)
{
	
	string categoria;
	cin.ignore();
	std::getline(cin, categoria);
	nodo.m_pregunta = categoria;
	nodo.m_hijoIzq = nullptr;
	nodo.m_hijoDer = nullptr;

}

void cNodo::inicializarMiembro(cNodo & nodo)
{
	nodo.inicializarNodo(nodo);
	
}

void cNodo::inicializarMiembro(cNodo & nodo, const string & pregunta) // función usada para los miembros de los hijos de la raiz
{
	nodo.m_pregunta = pregunta;
	
	nodo.m_hijoIzq = nullptr;
	nodo.m_hijoDer = nullptr;
}


void cNodo::inicializarNodo(cNodo & nodo)
{
	cout << "En que estabas pensando" << endl;
	string pregunta;
	cin.ignore();
	std::getline(cin, pregunta);
	nodo.m_pregunta = pregunta;
	nodo.m_hijoIzq = nullptr;

	nodo.m_hijoDer = nullptr;
}

void cNodo::inicializarNodo(cNodo & nodo, const string & pregunta) // usado para generar raiz y sus hijos 
{ 
	nodo.m_pregunta = pregunta;
	nodo.m_hijoIzq = nullptr;
	nodo.m_hijoDer = nullptr;
}


cNodo::~cNodo()
{
	if (m_hijoDer != nullptr) {
		delete m_hijoDer;
	}
	if (m_hijoIzq != nullptr) {
		delete m_hijoIzq;
	}
}
