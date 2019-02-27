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
	//int m_valor;
	string m_pregunta;
	cNodo * m_hijoIzq;
	cNodo *m_hijoDer;
	bool m_categoria; //true = categoría, false = miembro de una categoría
	//cNodo(int m_valor, cNodo * m_hijoIzq, cNodo *m_hijoDer);
	cNodo(string m_pregunta, bool m_categoria, cNodo * m_hijoIzq, cNodo * m_hijoDer);
	void inicializarCategoria(cNodo & node);
	void inicializarMiembro(cNodo & nodo);
	void inicializarMiembro(cNodo & nodo, const string & pregunta);
	void inicializarNodo(cNodo & nodo);
	void inicializarNodo(cNodo & nodo, const string & valor);

	~cNodo();
};

