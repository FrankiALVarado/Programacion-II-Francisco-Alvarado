#include <iostream>
#include <string>
#include "cArbol.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

cArbol * akinator = new cArbol;
int main() {
	akinator->incializarRaiz(); // se crea raiz con la pregunta real
	akinator->crearHijosRaiz(*akinator->m_raiz); // se crean las categorias Personajes de tv para el lado izquierdo y Animales para el derecho
	akinator->crearMiembrosHijos(*akinator->m_raiz->m_hijoIzq, *akinator->m_raiz->m_hijoDer); // se le añade un miembro a las anteriores categorias
	akinator->akinator(*akinator->m_raiz); // jugar akinator

	//akinator->imprimirArbol(*akinator->m_raiz);
	delete akinator;

	cin.clear();
	cin.ignore();
	cin.get();
	
	return 0;
}