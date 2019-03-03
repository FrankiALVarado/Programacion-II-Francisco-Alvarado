

#include "cArbol.h"

cArbol::cArbol()
{
}

cArbol::cArbol(cNodo *raiz)
{
	m_raiz = nullptr;
}


cArbol::~cArbol()
{
	delete m_raiz;
}

cNodo * cArbol::crearRaiz()
{
	cNodo * nodo = new cNodo;

	nodo->inicializarNodo(*nodo, "real"); // la raiz empieza con la pregunta "es real"
	return nodo;
}
void cArbol::incializarRaiz()
{
	m_raiz = crearRaiz();
}

void cArbol::akinator(cNodo & nodo)
{
	cout << "estas pensando en (algo) " << nodo.m_pregunta << " s/n , x para salir" << endl;
	string eleccion;
	cin >> eleccion;


	if (eleccion != "s" && eleccion != "n" && eleccion != "x") {
		cout << "ingrese s/n" << endl;
		akinator(nodo);
	}
	else if (eleccion == "x") {
		return;
	}
	else if (eleccion == "n"  && nodo.m_hijoIzq != nullptr) {
		akinator(*nodo.m_hijoIzq); //llegar a la siguiente categoria
	}
	else if (eleccion == "n"  && nodo.m_hijoIzq == nullptr && nodo.m_hijoDer == nullptr) { // si esta en los miembros finales de su categoria y no acierta
		cNodo *miembro = new cNodo;
		miembro->inicializarMiembro(*miembro);
		nodo.m_hijoDer = miembro; //lo que el usuario piensa

		string buffer = nodo.m_pregunta;
		cout << "Cual es la diferencia?" << endl;
		cNodo *node = new cNodo;
		node->inicializarCategoria(*node); //crear pregunta de separación de un miembro u otro
		nodo.m_hijoIzq = node;

		nodo.m_pregunta = node->m_pregunta;
		node->m_pregunta = buffer;

		balanceo();
		akinator(*m_raiz);

	}
	else if (eleccion == "n"  && nodo.m_hijoIzq == nullptr && nodo.m_hijoDer != nullptr) { // si no es de una categoria crear otra y agregarle un miembro
		cNodo *miembro = new cNodo;
		miembro->inicializarMiembro(*miembro);

		cout << "como lo catalogarias?" << endl;
		cNodo *node = new cNodo;
		node->inicializarCategoria(*node); //crear pregunta de separación de un miembro u otro
		nodo.m_hijoIzq = node;
		nodo.m_hijoIzq->m_hijoDer = miembro; //lo que el usuario piensa
		
		balanceo();
		akinator(*m_raiz);

	}
	else if (eleccion == "s" && nodo.m_hijoIzq == nullptr && nodo.m_hijoDer == nullptr) { // si el programa acierta la decision
		cout << "He ganado" << endl;
		akinator(*m_raiz);
	}
	else if (eleccion == "s") { // Empezar a preguntar por los miembros de la categoria

		akinator(*nodo.m_hijoDer);
	}

}


cNodo & cArbol::lastNode(cNodo & nodo)
{
	if (nodo.m_hijoIzq != nullptr) lastNode(*nodo.m_hijoIzq);
	else
		return nodo;
}

void cArbol::crearHijosRaiz(cNodo & padre)
{

	cNodo * nodo = new cNodo;
	cNodo * nodo2 = new cNodo;

	nodo->inicializarNodo(*nodo, "Personaje de tv"); // categoria inicial de la izquierda de la raiz
	nodo2->inicializarNodo(*nodo2, "Animales"); // categoria inicial de la derecha de la raiz
	
	padre.m_hijoIzq = nodo;
	padre.m_hijoDer = nodo2;
}

void cArbol::crearMiembrosHijos(cNodo & izq, cNodo & der)
{
	cNodo * nodo = new cNodo;
	cNodo * nodo2 = new cNodo;

	nodo->inicializarMiembro(*nodo, "Homero Simpson"); // hijo izq de la raiz tiene este miembro
	nodo2->inicializarMiembro(*nodo2, "Cocodrilo"); // hijo derecho de la raiz tiene este miembro

	izq.m_hijoDer = nodo;
	der.m_hijoDer = nodo2;
}



int cArbol::conteomax(cNodo & nodo, int nivel, int & mayor) //funcion que cuenta el nivel maximo de nodos para saber donde se encuentran sus hojas //nivel empieza en 2
{
	if (nivel > mayor) {
		mayor = nivel;
	}

	if (nodo.m_hijoIzq != nullptr) { // recorre de izquierda a derecha recursivamente, la variable mayor la tengo con referencia para que siempre devuelva la misma al momento de que recorra el arbol por completo
		conteomax(*nodo.m_hijoIzq, ++nivel, mayor);
	}
	else if (nodo.m_hijoDer != nullptr) {
		conteomax(*nodo.m_hijoDer, ++nivel, mayor);
	}
	return mayor;
}



void cArbol::balanceo()
{
	int nivel = 1;
	int mayor = 0;
	int lvlIzq = conteomax(*m_raiz->m_hijoIzq, nivel, mayor); // empezar a contar el mayor nivel por la izquierda de la raiz
	nivel = 1;
	mayor = 0;
	int lvlDer = conteomax(*m_raiz->m_hijoDer, nivel, mayor); // empezar a contar el arbol por la derecha de la raiz

	if (lvlDer - lvlIzq >= 2) {
		cNodo  *nodo = &lastNode(*m_raiz->m_hijoIzq); // la ultima categoria del lado desbalanceado, en este caso del lado izquierdo
		
		cout << "Ayuda a balancear el arbol, piensa en una categoria nueva para algo irreal" << endl;
		cNodo * categoria = new cNodo;
		categoria->inicializarCategoria(*categoria);

		cNodo * miembro = new cNodo;
		miembro->inicializarMiembro(*miembro);

		nodo->m_hijoIzq = categoria; //insertar nueva categoria
		nodo->m_hijoIzq->m_hijoDer = miembro; // agregarle un miembro

		
	}
	else if (lvlIzq - lvlDer >= 2) {
		cNodo  *nodo = &lastNode(*m_raiz->m_hijoDer); // la ultima categoria del lado desbalanceado, en este caso del lado derecho

		cout << "Ayuda a balancear el arbol, piensa en una categoria nueva para algo real" << endl;
		cNodo * categoria = new cNodo;
		categoria->inicializarCategoria(*categoria);

		cNodo * miembro = new cNodo;
		miembro->inicializarMiembro(*miembro);

		nodo->m_hijoIzq = categoria; // insertar nueva categoria
		nodo->m_hijoIzq->m_hijoDer = miembro; // agregarle un miembro 
	}
}

