#include "cGraph.h"


cGraph::cGraph()
{
}

cGraph::cGraph(std::vector<cEdge> _edges, std::vector<cNode> _nodes)
{
	m_edges = _edges;
	m_nodes = _nodes;
}

double & cGraph::coordx(std::string & text)
{
	std::string coord;
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == '|') {
			for (int j = i + 1; j < text.size(); j++) {
				if (text[j] == ':') {
					break;
				}
				coord += text[j];
			}
			break;
		}
	}
	double x = std::atof(coord.c_str());
	return x;
}
double & cGraph::coordy(std::string & text)
{
		std::string coord;
		for (int i = 0; i < text.size(); i++) {
			if (text[i] == ':') {
				for (int j = i + 1; j < text.size(); j++) {
					if (text[j] == ',' || text[j] == '\0') {
						break;
					}
					coord += text[j];
				}
				break;
			}
		}
		double x = std::atof(coord.c_str());
		return x;
}

void cGraph::initializeGraphFromText(std::ifstream & text)
{
	int nodes = -1;
	int edges = 0;

	std::string buffer;
	std::string s;

	while (std::getline(text, buffer)) { // ciclo para saber cuantos aristas va a haber e inicializar el arreglo de aristas
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

	std::vector<cNode> nodos(nodes);
	std::vector<cEdge> aristas(edges);

	m_nodes = nodos;
	m_edges = aristas;

	//std::cout << m_nodos.size() << std::endl;
	//std::cout << m_aristas.size() << std::endl;

	text.clear();
	text.seekg(0, std::ios::beg);
}

void cGraph::getGraphFromText(std::ifstream & text)
{
	std::string buffer = "";
	std::string nodes = "";
	float value;
	int edges = 0; //contador para el arreglo de aristas
	int column = -4; //contador para saber en que linea está, utilizada para llegar a referencias de vectores
	int row; //contador para saber en que columna está, inicializa en -1 porque la primera linea es solo para etiquetas
	while (std::getline(text, buffer)) {
		row = 0; // las filas se resetean cada vez que se salta una linea
		std::stringstream ss{ buffer };
		for (nodes; ss >> nodes;) {
			if (column == -1) { //si se encuentra en la primera linea va a agarrar las etiquetas de los nodos
				cNode node;
				node.setLabel(label(nodes));
				double x = coordx(nodes);
				node.setCoordX(x);
				double y = coordy(nodes);
				node.setCoordY(y);
				m_nodes[row] = node;

				//m_nodos[row].printLabel();

			}
			else if (column > -1) { //si ya está directamente en las aristas
				if (nodes != "0") { //si el peso de la arista es diferente de 0 va a agarrar los datos

					cEdge edge;
					value = std::atof(nodes.c_str());
					//std::cout << "valor a agarrar de la arista: " << valor << std::endl;
					edge.setEdge(m_nodes[row], m_nodes[column], value);
					m_edges[edges] = edge;
					edges++;
				}
			}
			row++;
		}
		column++;
	}
}

void cGraph::initializeGraphFromCSV(std::ifstream & text)
{
	int nodes = -4;
	int edges = 0;

	std::string buffer;
	std::string s;

	while (std::getline(text, buffer)) { // ciclo para saber cuantos aristas va a haber e iniciacilizar el arreglo de aristas
		std::stringstream edg{ buffer };
		for (s; edg >> s;) {
			if (nodes >= 0) {
				edges += edgeNumber(s);
			}

		}
		nodes++;
	}

	std::cout << "numero de nodos: " << nodes << std::endl;
	std::cout << "numero de aristas: " << edges << std::endl;

	std::vector<cNode> nodos(nodes);
	std::vector<cEdge> aristas(edges);

	m_nodes = nodos;
	m_edges = aristas;

	//std::cout << m_nodos.size() << std::endl;
	//std::cout << m_aristas.size() << std::endl;

	text.clear();
	text.seekg(0, std::ios::beg);
}

void cGraph::getGraphFromCSV(std::ifstream & text)
{
	std::string buffer;
	std::string nodes = "";
	float value;
	char * pEnd;
	int edges = 0; //contador para el arreglo de aristas
	int column = -4; //contador para saber en que linea está, utilizada para llegar a referencias de vectores
	int row; //contador para saber en que columna está, inicializa en -1 porque la primera linea es solo para etiquetas 
	while (std::getline(text, buffer)) {
		row = 0; // las filas se resetean cada vez que se salta una linea. para uso de las aristas
		std::stringstream ss{ buffer };
		nodes = ss.str();
		if (column == -4) { //linea donde se encuentran los códigos IATA
				while (row < m_nodes.size()) {
					cNode node;
 					node.setIATACode(getStringsFromCSV(nodes));
					m_nodes[row] = node;
					row++;
				}
				
		}
		else if (column == -3) { //linea donde se encuentran las ciudades
				while (row < m_nodes.size()) {
					m_nodes[row].setLabel(getStringsFromCSV(nodes));
					row++;
				}
		}
		else if (column == -2) { //linea donde se encuentran las coordenadas en x 
				while (row < m_nodes.size()) {
					m_nodes[row].setCoordY(std::strtof(getStringsFromCSV(nodes).c_str(), &pEnd));
					row++;
				}
		}
		else if (column == -1) { //linea donde se encuentran las coordenadas en y
				while (row < m_nodes.size()) {
					m_nodes[row].setCoordX(std::strtof(getStringsFromCSV(nodes).c_str(), &pEnd));
					row++;
				}
		}
		else if (column >= 0) { //linea donde empieza la matriz de adyacencia
				while (row < m_nodes.size()) {
					if (getWeightPreview(nodes) != "-1") {
						cEdge edge;
						edge.setEdge(m_nodes[row], m_nodes[column], std::strtof(getStringsFromCSV(nodes).c_str(), &pEnd));
						
						m_edges[edges] = edge;
						edges++;
					}
					else {
						nodes.erase(0, 3);
					}
					    row++;
				}
		}
			
	 column++;
	}
	
}


std::string cGraph::label(std::string & text)
{
	std::string label;
	for (char & x : text) {
		if (x == '|') {
			break;
		}
		label += x;
	}
	return label;
}

void cGraph::getNodeFromString(bool & arrive, std::string & label, cNode & node)
{
	for (int i = 0; i < m_nodes.size(); i++) {
		if (label == m_nodes[i].getLabel() || label == m_nodes[i].getIATACode()) { // si la etiqueta que buscamos es el nombre de la ciudad o el código iata regresa el nodo 
			arrive = true;
			node = m_nodes[i];
			break;
		}
	}
}

void cGraph::printNodes()
{
	for (cNode & x : m_nodes) {
		x.printLabel();
	}
}

void cGraph::loadOutput()
{
	std::cout << "como se llama el archivo de texto" << std::endl;
	std::string name;
	std::cin >> name;
	std::string format;
	std::cout << "que formato es: " << "\n";
	std::cin >> format;
	name += "."; 
	name += format;
	std::ifstream text(name, std::ios::in);
	if (text.fail()) { //en caso de que no abra el archivo
		std::cout << "hubo un error al cargar el archivo, presione una tecla para continuar" << "\n";
		std::cin.ignore(2);
		loadOutput();
	}
	else {
		initializeGraphFromCSV(text);
		getGraphFromCSV(text);
		graphMenu();
	}
}

void cGraph::depthFistSearchOutput()
{
	std::vector<cNode> open;
	std::vector<cNode> closed(m_nodes.size());
	cNode buffer; //buffer utilizado para pushbacks y para evitar muchas copias de nodos.
	cPathFinding * algorithm = new cDepthFirstSearch(open, closed, buffer);
	bool bArrive = false;
	int x = 0; // contador
	//int index = 0; // contador de indice

	cNode start;
	cNode last;
	std::string startlabel;
	std::cout << "desde que nodo quiere empezar? " << std::endl;
	do
	{
		std::cin >> startlabel;
		getNodeFromString(bArrive, startlabel, start);
		if (!bArrive) {
			std::cout << "el nodo no existe, ingrese otro" << std::endl;
		}
	} while (!bArrive);
	
	bArrive = false; // regresar bArrive a falso para ejecutar el algoritmo 

	std::cout << "hasta que nodo?" << std::endl;
	std::string lastlabel;
	do
	{
		std::cin >> lastlabel;
		getNodeFromString(bArrive, lastlabel, last);
		if (!bArrive) {
			std::cout << "el nodo no existe, ingrese otro" << std::endl;
		}
	} while (!bArrive);
	
	algorithm->pushBackFirstNode(start);
	algorithm->pathFind(x, last, bArrive, m_edges);

	if (bArrive) {
		std::cout << std::endl
			<< "Recorrido exitoso" << std::endl;
		std::cout << "numero de nodos recorridos: " << ++x << std::endl;
		std::cout <<
			"camino de cerrados: " << std::endl;
		algorithm->printClosed();
	}
	else {
		std::cout << std::endl
			<< "El recorrido no se pudo completar, no existe tal nodo" << std::endl;
	}

	open.clear();
	closed.clear();
	delete algorithm;
	graphMenu();
}

void cGraph::breadthFirstSearchOutput()
{
	std::vector<cNode> open;
	std::vector<cNode> closed(m_nodes.size());
	cNode buffer; //buffer utilizado para pushbacks y para evitar muchas copias de nodos.
	cPathFinding * algorithm = new cBreadthFirstSearch(open, closed, buffer);
	bool bArrive = false;
	int x = 0; // contador
	//int index = 0; // contador de indice

	cNode start;
	cNode last;
	std::string startlabel;
	std::cout << "desde que nodo quiere empezar? " << std::endl;
	do
	{
		std::cin >> startlabel;
		getNodeFromString(bArrive, startlabel, start);
		if (!bArrive) {
			std::cout << "el nodo no existe, ingrese otro" << std::endl;
		}
	} while (!bArrive);

	bArrive = false; // regresar bArrive a falso para ejecutar el algoritmo 

	std::cout << "hasta que nodo?" << std::endl;
	std::string lastlabel;
	do
	{
		std::cin >> lastlabel;
		getNodeFromString(bArrive, lastlabel, last);
		if (!bArrive) {
			std::cout << "el nodo no existe, ingrese otro" << std::endl;
		}
	} while (!bArrive);

	algorithm->pushBackFirstNode(start);
	algorithm->pathFind(x, last, bArrive, m_edges);

	if (bArrive) {
		std::cout << std::endl
			<< "Recorrido exitoso" << std::endl;
		std::cout << "numero de nodos recorridos: " << ++x << std::endl;
		std::cout <<
			"camino de cerrados: " << std::endl;
		algorithm->printClosed();
	}
	else {
		std::cout << std::endl
			<< "El recorrido no se pudo completar, no existe tal nodo" << std::endl;
	}

	open.clear();
	closed.clear();
	delete algorithm;
	graphMenu();
}


void cGraph::bestFirstOutput()
{
	std::vector<cNode> *open = new std::vector<cNode>;
	std::vector<cNode> *closed = new std::vector<cNode>(m_edges.size() + 1);
	cNode buffer; //buffer utilizado para pushbacks y para evitar muchas copias de nodos.
	cPathFinding * algorithm = new cBestFirst(*open, *closed, buffer);
	bool bArrive = false;
	int x = 0; // contador
	//int index = 0; // contador de indice

	cNode start;
	cNode last;
	std::string startlabel;
	std::cout << "desde que nodo quiere empezar? " << std::endl;

	do
	{
		std::cin >> startlabel;
		getNodeFromString(bArrive, startlabel, start); //usamos bArrive cómo un buffer para determinar si el nodo inicial existe
		if (!bArrive) {
			std::cout << "No existe tal nodo, vuelva a ingresar otra etiqueta" << std::endl;
		}
	} while (!bArrive);

	bArrive = false;

	std::cout << "hasta que nodo?" << std::endl;
	std::string lastlabel;
	do
	{
		std::cin >> lastlabel;
		last.setLabel(lastlabel);
	    getNodeFromString(bArrive, lastlabel, last);
		if (!bArrive) {
			std::cout << "el nodo no existe, ingrese otro" << std::endl;
		}
	} while (!bArrive);

	bArrive = false;
	algorithm->pushBackFirstNode(start);
	algorithm->pathFind(x, last, bArrive, m_edges);

	if (bArrive) {
		std::cout << std::endl
			<< "Recorrido exitoso" << std::endl;
	}
	else {
		std::cout << std::endl
			<< "El recorrido no se pudo completar" << std::endl;
	}

	delete algorithm;
	
	delete open;
	delete closed;
	graphMenu();
}


void cGraph::dijkstraOutput()
{
	std::vector<cNode> open;
	std::vector<cNode> closed(m_nodes.size());
	cNode buffer; //buffer utilizado para pushbacks y para evitar muchas copias de nodos.
	cPathFinding * algorithm = new cDijkstra(open, closed, buffer);
	bool bArrive = false;
	int x = 0; // contador
	//int index = 0; // contador de indice

	cNode start;
	cNode last;
	std::string startlabel;
	std::cout << "desde que nodo quiere empezar? " << std::endl;
	do
	{
		std::cin >> startlabel;
		getNodeFromString(bArrive, startlabel, start);
		if (!bArrive) {
			std::cout << "el nodo no existe, ingrese otro" << std::endl;
		}
	} while (!bArrive);

	bArrive = false; // regresar bArrive a falso para ejecutar el algoritmo 

	std::cout << "hasta que nodo?" << std::endl;
	std::string lastlabel;
	do
	{
		std::cin >> lastlabel;
	    getNodeFromString(bArrive, lastlabel, last);
		if (!bArrive) {
			std::cout << "el nodo no existe, ingrese otro" << std::endl;
		}
	} while (!bArrive);

	algorithm->pushBackFirstNode(start);
	algorithm->pathFind(x, last, bArrive, m_edges);

	open.clear();
	closed.clear();
	delete algorithm;
	graphMenu();
}

void cGraph::aStarOutput()
{
	std::vector<cNode> *open = new std::vector<cNode>;
	std::vector<cNode> *closed = new std::vector<cNode>(m_edges.size() + 1);
	cNode buffer; //buffer utilizado para pushbacks y para evitar muchas copias de nodos.
	cPathFinding * algorithm = new caStar(*open, *closed, buffer);
	bool bArrive = false;
	int x = 0; // contador
	//int index = 0; // contador de indice

	cNode start;
	cNode last;
	std::string startlabel;
	std::cout << "desde que nodo quiere empezar? " << std::endl;

	do
	{
		std::cin >> startlabel;
		getNodeFromString(bArrive, startlabel, start); //usamos bArrive cómo un buffer para determinar si el nodo inicial existe
		if (!bArrive) {
			std::cout << "No existe tal nodo, vuelva a ingresar otra etiqueta" << std::endl;
		}
	} while (!bArrive);

	bArrive = false;

	std::cout << "hasta que nodo?" << std::endl;
	std::string lastlabel;
	do
	{
		std::cin >> lastlabel;
		last.setLabel(lastlabel);
		getNodeFromString(bArrive, lastlabel, last);
		if (!bArrive) {
			std::cout << "el nodo no existe, ingrese otro" << std::endl;
		}
	} while (!bArrive);

	bArrive = false;
	algorithm->pushBackFirstNode(start);
	algorithm->pathFind(x, last, bArrive, m_edges);

	if (bArrive) {
		std::cout << std::endl
			<< "Recorrido exitoso" << std::endl;
	}
	else {
		std::cout << std::endl
			<< "El recorrido no se pudo completar" << std::endl;
	}

	delete algorithm;

	delete open;
	delete closed;
	graphMenu();
}

void cGraph::noGraphWarning()
{
	std::cout << "no hay un grafo cargado, por favor cargue uno (1)" << std::endl;
	std::cout << "presione una tecla para continuar." << std::endl;
	std::cin.ignore(2);
	system("cls");
	graphMenu();
}

void cGraph::pathfindingMenu()
{
	std::vector<cNode> *open = new std::vector<cNode>;
	std::vector<cNode> *closed = new std::vector<cNode>(m_edges.size() + 1);
	cNode buffer; //buffer utilizado para pushbacks y para evitar muchas copias de nodos.
}

int cGraph::edgeNumber(std::string & str)
{
	int counter = 0;
	std::string buffer = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != ',' && str[i] != '\n') {
				buffer += str[i];
			
		}
		else {
			if (buffer != "-1") {
				counter++;
			}
			buffer = "";
		}
	}

	if (buffer != "-1") { //checador adicional porque en el ciclo anterior no alcanza a checar sin infringir acceso de lectura
		counter++;
	}
	return counter;
}


std::string  cGraph::getStringsFromCSV(std::string & str) // funcion que devuelve las strings entre comillas
{
	std::string buffer;
	/*for (char & x : str) {
		if (x == ',' || x == '\n') {
			if (x == ',') {
				str.erase(0, buffer.size() + 1);
			}
			break;
		}
		else
			buffer += x;
	}
	return buffer;
	*/
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ',') {
			str.erase(0, buffer.size()+1);
			return buffer;
		}
		else {
			buffer += str[i];
		}
	}
	return buffer; // que regrese la ultima etiqueta que no se alcanza a checar para no infringir range error
}

std::string cGraph::getWeightPreview(std::string & str)
{
	std::string buffer;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ',') {
			
			return buffer;
		}
		else {
			buffer += str[i];
		}
	}
	return buffer; // que regrese la ultima etiqueta que no se alcanza a checar para no infringir range error
}


cGraph::~cGraph()
{
}

void cGraph::graphMenu()
{

	std::cout << "que desea hacer con el grafo?" << std::endl;
	std::cout << "1) cargar archivo de texto" << std::endl;
	std::cout << "2) busqueda a profundidad" << std::endl;
	std::cout << "3) busqueda en amplitud" << std::endl;
	std::cout << "4) nodo primero mejor" << std::endl;
	std::cout << "5) Dijkstra" << std::endl;
	std::cout << "6) A estrella" << std::endl;
	std::cout << "x) salir" << std::endl;
	std::string eleccion;
	std::cin >> eleccion;
	if (eleccion == "1") {
		if (m_nodes.size() > 0) {
			std::cout << "ya existe un archivo cargado, desea sobreescribirlo? s/n" << std::endl;
			std::string eleccion;
			std::cin >> eleccion;
			if (eleccion == "s") {
				m_edges.clear();
				m_nodes.clear();
				loadOutput();
			}
			else {
				graphMenu();
			}
		}
		else {
			loadOutput();
		}
	}
	else if (eleccion == "2") {
		if (m_nodes.size() == 0) {
			noGraphWarning();
		}
		else {
			depthFistSearchOutput();
		}
	}
	else if (eleccion == "3") {
		if (m_nodes.size() == 0) {
			noGraphWarning();
		}
		else {
			breadthFirstSearchOutput();
		}
	}
	else if (eleccion == "4") {
		if (m_nodes.size() == 0) {
			noGraphWarning();
		}
		else {
			bestFirstOutput();
		}
	}
	else if (eleccion == "5") {
		if (m_nodes.size() == 0) {
			noGraphWarning();
		}
		else {
			dijkstraOutput();
		}
	}
	else if (eleccion == "6") {
		if (m_nodes.size() == 0) {
			noGraphWarning();
		}
		else {
			aStarOutput();
		}
	}
	else if (eleccion == "x") {
		return;
	}
	else
		graphMenu();
}