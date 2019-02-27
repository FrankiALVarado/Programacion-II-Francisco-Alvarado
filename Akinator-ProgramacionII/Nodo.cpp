#include "Nodo.h"



cNodo::cNodo()
{
}

/*cNodo::cNodo(int m_valor, cNodo * m_hijoIzq, cNodo * m_hijoDer)
{
	m_valor = 0;
	m_hijoIzq = nullptr;
	m_hijoIzq = nullptr;
}*/



cNodo::cNodo(string m_pregunta, bool m_categoria, cNodo * m_hijoIzq, cNodo * m_hijoDer)
{
	m_pregunta = "";
	m_categoria = true;
	m_hijoIzq = nullptr;
	m_hijoDer = nullptr;
}

void cNodo::inicializarCategoria(cNodo & nodo)
{
	cout << "como puedes catalogar lo que estabas pensando" << endl;
	string categoria;
	cin >> categoria;
	nodo.m_pregunta = categoria;
	nodo.m_categoria = true;
	nodo.m_hijoIzq = nullptr;
	nodo.m_hijoDer = nullptr;

}

void cNodo::inicializarMiembro(cNodo & nodo)
{
	nodo.inicializarNodo(nodo);
	nodo.m_categoria = false;
}

void cNodo::inicializarMiembro(cNodo & nodo, const string & pregunta) // función usada para los miembros de los hijos de la raiz
{
	nodo.m_pregunta = pregunta;
	nodo.m_categoria = false;
	nodo.m_hijoIzq = nullptr;
	nodo.m_hijoDer = nullptr;
}


void cNodo::inicializarNodo(cNodo & nodo)
{
	cout << "En que estabas pensando" << endl;
	string pregunta;
	cin >> pregunta;
	nodo.m_pregunta = pregunta;
	nodo.m_hijoIzq = nullptr;
	nodo.m_hijoDer = nullptr;
}

void cNodo::inicializarNodo(cNodo & nodo, const string & pregunta) // usado para generar raiz y sus hijos 
{ 
	nodo.m_pregunta = pregunta;
	nodo.m_categoria = true;
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
