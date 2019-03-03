#pragma once
#include "Nodo.h"
class cArbol
{
public:
	cArbol();
	cNodo * m_raiz;
	cArbol(cNodo *m_raiz);
	cNodo * crearRaiz(); 
	void incializarRaiz(); //funcion para darle un puntero a la raiz
	void akinator(cNodo & nodo); //juego akinator
	void crearHijosRaiz(cNodo & padre);  //crear las categorias hijas de la raiz
	void crearMiembrosHijos(cNodo & izq, cNodo & der); //crear los miembros de dichas categorias
	cNodo & lastNode(cNodo & nodo); //regresar el ultimo nodo que se muestra como categoria
	int conteomax(cNodo & nodo, int nivel, int & mayor);
	void balanceo();

	~cArbol();
};

