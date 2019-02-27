/*
Labores para terminar:
añadir categoria a la derecha e izquierda de nodo y darles un miembro -listo
cambiar la forma de crear nodos y adaptarla -listo
funcion del akinator completo en proceso -listo
balanceo del arbol -en proceso arreglar balanceo y contador de maximo nivel - listo
getlines
*/

/*
Detalles del arbol:
raíz tiene dos hijos categorías, de ahi cada uno solo tiene categorías a la izquierda y miembros a la derecha.
solo los nodos miembros tienen su puntero a la izq vacio
por como está hecho el programa no se puede tener una categoría vacía.
*/

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

	nodo->inicializarNodo(*nodo, "real");
	return nodo;
}
void cArbol::incializarRaiz()
{
	m_raiz = crearRaiz();
}

void cArbol::akinator(cNodo & nodo)
{
	cout << "estas pensando en (algo) " << nodo.m_pregunta << " s/n , x para salir"<< endl;
    string eleccion;
	cin >> eleccion;
	
	
	if (eleccion != "s" && eleccion != "n" && eleccion != "x") {
		cout << "ingrese s/n" << endl;
		akinator(nodo);
	}
	else if (eleccion == "x") {
		return;
	}
	else if (eleccion == "n" && nodo.m_categoria && nodo.m_hijoIzq != nullptr) {
		akinator(*nodo.m_hijoIzq); //llegar a la siguiente categoria
	}
	else if (eleccion == "n" && nodo.m_categoria && nodo.m_hijoIzq == nullptr) { // si no hay categoria siguiente y aun no atina la categoria
		cout << "fin de categorias, se creara una nueva" << endl;
		cNodo *node = new cNodo;
		node->inicializarCategoria(*node); //crear categoria
		nodo.m_hijoIzq = node;

		cNodo *miembro = new cNodo;
		miembro = crearMiembro(); 
		nodo.m_hijoIzq->m_hijoDer = miembro; //ponerle un miembro a la categoria
		balanceo();
		akinator(*m_raiz);
	}
	else if (eleccion == "n" && !nodo.m_categoria && nodo.m_hijoDer == nullptr) { // si el primer miembro no es el apropiado
		cout << "fin de los miembros,  se creara uno nuevo" << endl;
		cNodo *node = new cNodo;
		node = crearMiembro();
		nodo.m_hijoDer = node;
		balanceo();
		akinator(*m_raiz);
	}
	else if (eleccion == "s" && nodo.m_categoria) { // Empezar a preguntar por los miembros de la categoria
		balanceo();
		akinator(*nodo.m_hijoDer);
	}
	else if (eleccion == "s" && !nodo.m_categoria) { // si el programa acierta la decision
		cout << "He ganado" << endl;
		akinator(*m_raiz);
	}
}


/*void cArbol::insertarNodo(cNodo &node, cNodo &padre) // start es nodo padre
{

}*/

void cArbol::imprimirArbol(cNodo & node) {
	cout << "nodo actual: " << node.m_pregunta << endl;

	if (node.m_hijoIzq == nullptr && node.m_hijoDer == nullptr)
		cout << "el nodo actual no tiene hijos." << endl;

	if (node.m_hijoIzq != nullptr) {
		cout << "hijo izq: " << node.m_hijoIzq->m_pregunta << endl;
	}

	if (node.m_hijoDer != nullptr) {
		cout << "hijo der: " << node.m_hijoDer->m_pregunta << endl;
	}

	if (node.m_hijoIzq != nullptr) {
		imprimirArbol(*node.m_hijoIzq);
	}
	if (node.m_hijoDer != nullptr) {
		imprimirArbol(*node.m_hijoDer);
	}
}

cNodo * cArbol::crearCategoria()
{
	cNodo * nodo = new cNodo;
	nodo->inicializarCategoria(*nodo);
	return nodo;
}

cNodo * cArbol::crearMiembro()
{
	cNodo * nodo = new cNodo;
	nodo->inicializarMiembro(*nodo);
	return nodo;
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

	nodo->inicializarNodo(*nodo, "Personaje de tv");
	nodo2->inicializarNodo(*nodo2, "Animales");
	
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



int cArbol::conteomax(cNodo & nodo, int & nivel, int & mayor) //funcion que cuenta el nivel maximo de nodos para saber donde se encuentran sus hojas //nivel empieza en 2
{
	int buffer = mayor;
	mayor = nivel + 1 + conteo(*nodo.m_hijoDer); // siempre va a haber por lo menos un hijo derecho
	if (buffer > mayor) mayor = buffer;
	
	if (nodo.m_hijoIzq != nullptr) {
		conteomax(*nodo.m_hijoIzq, ++nivel, mayor);
	}
	else if (nodo.m_hijoIzq == nullptr) {
		return mayor;
	}
}

int cArbol::conteo(cNodo & nodo) // suma de los hijos del lado derecho
{
	if (nodo.m_hijoDer == nullptr) return 0;

	return 1 + conteo(*nodo.m_hijoDer);
}

void cArbol::balanceo()
{
	int nivel = 1;
	int mayor = 0;
	int lvlIzq = conteomax(*m_raiz->m_hijoIzq, nivel, mayor);
	nivel = 1;
	mayor = 0;
	int lvlDer = conteomax(*m_raiz->m_hijoDer, nivel, mayor);

	//cout << "mayor nivel izquierdo: " << lvlIzq << endl;
	//cout << "mayor nivel derecho: " << lvlDer << endl;


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

