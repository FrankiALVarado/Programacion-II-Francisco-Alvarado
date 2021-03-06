#include "cGrafo.h"

/*
Labores por terminar:
nodo primero mejor
arista agarra peso - listo
menu ciclico y informar al usuario que primero cargue un vector o que lo va a sobreescribir - listo

*/

cGrafo::cGrafo()
{
}


cGrafo::cGrafo(std::vector<cNodo> m_nodos, std::vector<cArista> m_aristas)
{
	m_nodos;
	m_aristas;
}


/*cGrafo::cGrafo(cNodo * m_nodes, cArista * m_edges)
{
	m_nodes = nullptr;
	m_edges = nullptr;
}*/

cGrafo::~cGrafo()
{
}

void cGrafo::getFromText(std::ifstream & text)
{
	std::string buffer = "";
	std::string nodes = "";
	int valor;
	int edges = 0; //contador para el arreglo de aristas
	int column = -1; //contador para saber en que linea est�, utilizada para llegar a referencias de vectores
	int row; //contador para saber en que columna est�, inicializa en -1 porque la primera linea es solo para etiquetas
	while (std::getline(text, buffer)) {
		row = 0; // las filas se resetean cada vez que se salta una linea
		std::stringstream ss{ buffer };
		for (nodes; ss >> nodes;) {
			if (column == -1) { //si se encuentra en la primera linea va a agarrar las etiquetas de los nodos
				cNodo node;
				node.initializeNode(node);
				node.setLabel(nodes);
				m_nodos[row] = node;
				//m_nodos[row].printLabel();

			}
			else if(column > -1) { //si ya est� directamente en las aristas
		   
				if (nodes != "0") { //si el peso de la arista es diferente de 0 va a agarrar los datos
			
					cArista edge;
					edge.initializeEdge(edge);
					valor = atoi(nodes.c_str());
					//std::cout << "valor a agarrar de la arista: " << valor << std::endl;
					edge.setEdge(m_nodos[row], m_nodos[column], valor);
					m_aristas[edges] = edge;
					edges++;
			    }
			}
			row++;
		}
			column++;
	}
}

void cGrafo::depthFirstSearch(int &contador, int & nodos, cNodo & actual, cNodo & buffer, std::vector<cNodo> & abiertos, std::vector<cNodo> & cerrados)
{
	std::cout << "nodo actual: " << actual.getLabel() << std::endl; 
	if (abiertos.size() > 0) {
		if (actual.getLabel() == abiertos[abiertos.size() - 1].getLabel()) { // si el nodo actual es el �ltimo de abiertos y abiertos no est� vac�o, se borra
			abiertos.pop_back();
		}
	}
	while (contador < m_aristas.size()) { // el while se repetira por el numero de aristas
		if (!isInVector(actual, cerrados)) {
			std::cout << "agregando a cerrados: " << actual.getLabel() << std::endl;
			cerrados[nodos] = actual; // si el nodo actual no est� en el vector de cerrados, lo agrega. 
			std::cout << "lista de nodos cerrados " << std::endl;
			for (cNodo & c : cerrados) {
				c.printLabel();
			}
			std::cout << std::endl;
			nodos++;
			std::cout << "numero de nodos recorridos: " << nodos << std::endl;


			//ciclo para a�adir a los que apunta a abiertos
			for (int i = 0; i < m_aristas.size(); i++) {
				if (actual.getLabel() == m_aristas[i].getFirstNodeLabel()) { // si el actual y un nodo i tienen la misma etiqueta
					//std::cout << "nodo que comparamos: " << actual.getLabel() << std::endl;
					//std::cout << "estamos comparando con: " << m_aristas[i].getFirstNodeLabel() << std::endl;
					buffer = m_aristas[i].getSecondNode();

					std::cout << "agregando a abiertos: " << buffer.getLabel() << std::endl;
					abiertos.push_back(buffer);	//agregar a abiertos todos los nodos que apunta.
					//std::cout << abiertos.size() << std::endl;
					
				}
			}
		}
		cNodo buffer2 = abiertos[abiertos.size() - 1];
		contador++;
		if (abiertos.size() > 0) {
			depthFirstSearch(contador, nodos, buffer2, buffer, abiertos, cerrados);

		}
	}
}

void cGrafo::breadthFirstSearch(int & contador, int & nodos, cNodo & actual, cNodo & buffer, std::vector<cNodo>& abiertos, std::vector<cNodo>& cerrados)
{
	std::cout << "nodo actual: " << actual.getLabel() << std::endl;
	if (abiertos.size() > 0) {
		if (actual.getLabel() == abiertos[0].getLabel()) {
			abiertos.erase(abiertos.begin());
		}
	}
	while (contador < m_aristas.size()) { // el while se repetira por el numero de aristas
		if (!isInVector(actual, cerrados)) {
			std::cout << "agregando a cerrados: " << actual.getLabel() << std::endl;
			cerrados[nodos] = actual; // si el nodo actual no est� en el vector de cerrados, lo agrega. 

			std::cout << "lista de nodos cerrados " << std::endl;
			for (cNodo & c : cerrados) {
				c.printLabel();
			}
			std::cout << std::endl;
			
			nodos++;
			std::cout << "numero de nodos recorridos: " << nodos << std::endl;


			//ciclo para a�adir a los que apunta a abiertos
			for (int i = 0; i < m_aristas.size(); i++) {
				if (actual.getLabel() == m_aristas[i].getFirstNodeLabel()) {

					buffer = m_aristas[i].getSecondNode();
					std::cout << "agregando a abiertos: " << buffer.getLabel() << std::endl;
					abiertos.push_back(buffer);
					//std::cout << abiertos.size() << std::endl;
				}
			}
		}
		cNodo buffer2 = abiertos[0];
		contador++;
		if (abiertos.size() > 0) {
			buffer = abiertos[0];
			breadthFirstSearch(contador, nodos, buffer2, buffer, abiertos, cerrados);
		}
		/*
		else if (abiertos.size() > 0 && buffer.getLabel() == "") {
			buffer = abiertos[abiertos.size() - 1];
			depthFirstSearch(contador, nodos, buffer, abiertos, cerrados);
		}*/
	}
}

bool cGrafo::isInVector(cNodo & node, std::vector<cNodo>& vector)
{
	bool inVector = false;
	for (int i = 0; i < vector.size(); i++) {
		if (node.getLabel() == vector[i].getLabel()) inVector = true;
		if (inVector) break;
	}
	return inVector;
}


/*void cGrafo::initializeGraph()
{
	std::vector<cNodo> nodes;
	std::vector<cArista> edges;
	
	m_nodos = nodes;
	m_aristas = edges;
}*/

void cGrafo::initializeGraphFromText( std::ifstream & text)
{
	int nodes = -1;
	int edges = 0;
	
	std::string buffer;
	std::string s;

	while (std::getline(text, buffer)) { // ciclo para saber cuantos aristas va a haber e iniciacilizar el arreglo de aristas
		std::stringstream edg{ buffer };
		for (s; edg >> s;) {
			if (nodes != -1) {
				if (s != "0") {
					edges++;
				}
			}
			
		}
			nodes++;
	}

	std::cout << "numero de nodos: " << nodes << std::endl;
	std::cout << "numero de aristas: " << edges << std::endl;

	std::vector<cNodo> nodos(nodes);
	std::vector<cArista> aristas(edges);
	
	m_nodos = nodos;
	m_aristas = aristas;

	//std::cout << m_nodos.size() << std::endl;
	//std::cout << m_aristas.size() << std::endl;

	text.clear();
	text.seekg(0, std::ios::beg);
	
}

void cGrafo::graphMenu()
{
std::cout << "que desea hacer con el grafo?" << std::endl;
std::cout << "1) cargar archivo de texto" << std::endl;
std::cout << "2) busqueda a profundidad" << std::endl;
std::cout << "3) busqueda en amplitud" << std::endl;
std::string eleccion;
std::cin >> eleccion;
if (eleccion == "1") {
	if (m_nodos.size() > 0) {
		std::cout << "ya existe un archivo cargado, desea sobreescribirlo? s/n" << std::endl;
		std::string eleccion;
	std:cin >> eleccion;
		if (eleccion == s) {

		}
	}
	std::cout << "como se llama el archivo de texto" << std::endl;
	std::string name;
	std::cin >> name;
	name += ".txt"; //facilita al usuario para que solo escriba el nombre sin su formato
	std::ifstream texto(name, std::ios::in);
	initializeGraphFromText(texto);
	getFromText(texto);
	graphMenu();
	
}
else if (eleccion == "2") { 
	if (m_nodos.size() == 0) {
		std::cout << "no hay un grafo cargado, por favor cargue uno (1)" << std::endl;
		std::cout << "presione una tecla para continuar." << std::endl;
		std::cin.ignore(2);
		system("cls");
		graphMenu();
	}
	else {

		std::vector<cNodo> abiertos;
		std::vector<cNodo> cerrados(m_nodos.size());
		int x = 0; // contador
		int nod = 0; // nodos recorridos 
		cNodo buffer; //buffer utilizado para pushbacks y para evitar muchas copias de nodos.
		//int index = 0; // contador de indice
		
		depthFirstSearch(x, nod, m_nodos[0], buffer, abiertos, cerrados);
		abiertos.clear();
		cerrados.clear();
		graphMenu();
	}
}
else if (eleccion == "3") {
	if (m_nodos.size() == 0) {
		std::cout << "no hay un grafo cargado, por favor cargue uno (1)" << std::endl;
		std::cout << "presione una tecla para continuar." << std::endl;
		std::cin.ignore(2);
		system("cls");
		graphMenu();
	}
	else {

		cNodo buffer;  //buffer utilizado para pushbacks y para evitar muchas copias de nodos.
		int x = 0; // contador
		int nod = 0; // nodos recorridos 
		//int index = 0; //contador de indice
		std::vector<cNodo> abiertos;
		std::vector<cNodo> cerrados(m_nodos.size());
		breadthFirstSearch(x, nod, m_nodos[0], buffer, abiertos, cerrados);
		abiertos.clear();
		cerrados.clear();
		graphMenu();
	}
}
else {
	return;
}
}

void cGrafo::printGraph() //para imprimir el grafo, agarra todos sus miembros de los vectores y llama sus propias impresiones.
{
	/*int max_nodes = sizeof(m_nodes) / sizeof(cNodo);
	std::cout << "numero de nodos: " << max_nodes << std::endl;
	for (int i = 0; i < max_nodes; i++) {
		m_nodes[i].getLabel();
	}*/
	
	for (cNodo & c : m_nodos) {
		c.printLabel();
	}

	std::cout << std::endl;

	for (cArista & x : m_aristas) {
		x.printEdge();
	}
}

