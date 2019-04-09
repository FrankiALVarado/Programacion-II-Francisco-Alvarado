#include "cPathFinding.h"

constexpr float pi = 3.14159265; // pi
constexpr float r = 6371; //radio de la tierra en kilometros
 float zero = 0.0;
cPathFinding::cPathFinding()
{
}

cPathFinding::cPathFinding(std::vector<cNode> _open, std::vector<cNode> _closed, cNode _buffer)
{
	m_open = _open;
	m_closed = _closed;
	m_buffer = _buffer;
}


/*std::string & cPathFinding::setInitialNodeLabel() // prompt del nodo inicial
{
	std::string label;
	std::cout << "Desde que nodo quiere iniciar?" << std::endl;
	std::cin >> label;
	
	return label;
}

std::string & cPathFinding::setLastNodeLabel() // prompt del nodo final
{
	std::string label;
	std::cout << "Hasta que nodo quiere buscar?" << std::endl;
	std::cin >> label;

	return label;
}*/

void cPathFinding::quicksort(std::vector<cNode>& vector, int min_index, int max_index)
{
	if (min_index < max_index) {
		int pivot = subarray(vector, min_index, max_index);
		quicksort(vector, min_index, pivot - 1);
		quicksort(vector, pivot + 1, max_index);
	}
}

int cPathFinding::subarray(std::vector<cNode>& vector, int & min_index, int & max_index)
{
	double pivot = vector[max_index].getDistance();
	int index = min_index - 1;
	for (int i = min_index; i <= max_index - 1; i++) {
		if (vector[i].getDistance() <= pivot) {
			index++;
			swap(vector[index], vector[i]);
		}
	}
	swap(vector[index + 1], vector[max_index]);
	return ++index;
}

void cPathFinding::swap(cNode & node1, cNode & node2)
{
	
	m_buffer = node1;
	node1 = node2;
	node2 = m_buffer;
}

bool cPathFinding::isInVector(cNode & node, std::vector<cNode> vector) // funcion para checar en vectores para todos los algoritmos menos para primero mejor
{
	for (int i = 0; i < vector.size(); i++) {
		if (node.getLabel() == vector[i].getLabel())
			return true;
	}
	return false;
}

void cPathFinding::freeVector()
{
	m_closed.clear();
	m_closed.resize(0);
	m_closed.shrink_to_fit();

	m_open.clear();
	m_open.resize(0);
	m_open.shrink_to_fit();
}

void cPathFinding::winnerRoute(std::vector<cNode>& nodes, cNode & last)
{
	for (int i = 0; i < nodes.size(); i++) {
		if (nodes[i].getIATACode() == last.getIATACode()) {
			printRoute(nodes[i]);
			break;
		}
	}

}

void cPathFinding::printRoute(cNode & node)
{
	if (node.getPointer() != nullptr) {
		std::cout << std::endl;
		std::cout << "ruta ganadora: " << std::endl;
		printRoute(*node.getPointer());
	}

	node.printNodePM();
	std::cout << "\n";
}

void cPathFinding::printClosed()
{
	for (int i = 0; i < m_closed.size(); i++) {
		m_closed[i].printLabel();
	}
}

void cPathFinding::pushBackFirstNode(cNode & node)
{
	m_open.push_back(node);
}


void cDepthFirstSearch::pathFind(int & counter, cNode & lastLabel, bool & arrive, std::vector<cEdge> & edges)
{
	while (m_open.size() > 0) {
		int max = m_open.size() - 1;
		if (m_open[max].getLabel() == lastLabel.getLabel()) {
			m_closed[counter] = m_open[max];
			arrive = true;
			break;
		}
		else{
			if (!isInVector(m_open[max], m_closed)) {
				std::cout << "agregando a cerrados: " << m_open[max].getLabel() << std::endl;
				m_closed[counter] = m_open[max]; // si el nodo actual no está en el vector de cerrados, lo agrega. 
				std::cout << "lista de nodos cerrados " << std::endl;
				for (int i = 0; i < m_closed.size(); i++) {
					m_closed[i].printLabel();
				}

				std::cout << std::endl;
				counter++;
				std::cout << "numero de nodos recorridos: " << counter << std::endl;


				for (int i = 0; i < edges.size(); i++) { // ciclo para agregar a abiertos a los que apunta
					if (m_open[max].getLabel() == edges[i].getFirstNodeLabel()) { // si el actual y un nodo i tienen la misma etiqueta
						m_buffer = edges[i].getSecondNode();

						if (!isInVector(m_buffer, m_closed)) { // si el nodo al que apunta no está en cerrados, lo pone en abiertos
							std::cout << "agregando a abiertos: " << m_buffer.getLabel() << std::endl;
							m_open.push_back(m_buffer);	//agregar a abiertos todos los nodos que apunta.

						}
					}
				}
			}
				m_open.erase(m_open.begin() + max);
		}
	}
}

cDepthFirstSearch::~cDepthFirstSearch()
{
	freeVector();
}

void cBreadthFirstSearch::pathFind(int & counter, cNode & lastLabel, bool & arrive, std::vector<cEdge>& edge)
{
	while (m_open.size() > 0) {
		if (m_open[0].getLabel() == lastLabel.getLabel()) {
			m_closed[counter] = m_open[0];
			arrive = true;
			break;
		}
		else {
			if (!isInVector(m_open[0], m_closed)) {
				std::cout << "agregando a cerrados: " << m_open[0].getLabel() << std::endl;
				m_closed[counter] = m_open[0]; // si el nodo actual no está en el vector de cerrados, lo agrega. 
				std::cout << "lista de nodos cerrados " << std::endl;
				for (int i = 0; i < m_closed.size(); i++) {
					m_closed[i].printLabel();
				}

				std::cout << std::endl;
				counter++;
				std::cout << "numero de nodos recorridos: " << counter << std::endl;


				for (int i = 0; i < edge.size(); i++) { // ciclo para agregar a abiertos a los que apunta
					if (m_open[0].getLabel() == edge[i].getFirstNodeLabel()) { // si el actual y un nodo i tienen la misma etiqueta
						m_buffer = edge[i].getSecondNode();

						if (!isInVector(m_buffer, m_closed)) { // si el nodo al que apunta no está en cerrados, lo pone en abiertos
							std::cout << "agregando a abiertos: " << m_buffer.getLabel() << std::endl;
							m_open.push_back(m_buffer);	//agregar a abiertos todos los nodos que apunta.

						}
					}
				}
			}
			m_open.erase(m_open.begin());
		}
	}
}

cBreadthFirstSearch::~cBreadthFirstSearch()
{
	freeVector();
}


void cBestFirst::pathFind(int & counter, cNode & lastLabel, bool & arriv, std::vector<cEdge>& edges)
{
	
	while(m_open.size() > 0) {
		std::cout << "nodopm actual: " << std::endl;
		m_open[0].printNodePM();

		if (!isInVector(m_open[0], m_closed)) { // si este nodo está en cerrados 
			m_closed[counter] = m_open[0];
			counter++;


			for (int j = 0; j < edges.size(); j++) { // ciclo para ir agregando a abiertos
				if (m_open[0].getIATACode() == edges[j].getFirstNodeIATACode() && m_open[0].getLabel() != lastLabel.getLabel()) {
					if (m_closed[counter].getLabel() == lastLabel.getLabel()) { // si el nodo al que apunta es el mismo que el que buscamos
						arriv = true;
						
					}
					 
				    if (m_open[0].getLabel2() != edges[j].getSecondNodeLabel()) { // si es diferente de donde viene, para los casos de bidireccionalidad
					    m_buffer = edges[j].getSecondNode(); // le damos informacion al buffer para un pushback
					    m_buffer.setDistance(0); // reset de la distancia como es por referencia el buffer sigue sumando a no ser que se regrese a 0
					    m_buffer.setDistance(edges[j].getWeight(), m_open[0].getDistance()); // le va sumando la distancia recorrida;
					    m_buffer.setPointer(m_closed[counter - 1]); // le da un puntero de donde viene que es el mismo nodopm actual

						if (!isInVector(m_buffer, m_closed)) { //si este nodo el nodo que se va a abrir no se ha evaluado anteriormente
							std::cout << "agregando a abiertos: " << std::endl;
							m_buffer.printNodePM();
							m_open.push_back(m_buffer);
						}
					}

				}
			}


			m_open.erase(m_open.begin()); // eliminar el nodo que ya analizamos 
			if (m_open.size() > 1) {
				quicksort(m_open, 0, m_open.size() - 1); // quicksort
			}
			
		}
		else { // si el nodo ya se ha evaluado solo lo cerramos
			m_closed[counter] = m_open[0];
			counter++;

			m_open.erase(m_open.begin());
			
		}

	}
	winnerRoute(m_closed, lastLabel);
}

bool cBestFirst::isInVector(cNode & node, std::vector<cNode>& vector)
{
	for (int i = 0; i < vector.size(); i++) {
		if (vector[i].getIATACode() == node.getIATACode()) {
			return true;
		}
		if (vector[i].getLabel() == "") { // este ciclo solo lo lleva cerrados que en sus primeras iteraciones va a tener string vacio
			return false;
		}
	}
	return false;


}

cBestFirst::~cBestFirst()
{
	freeVector();
}

void cDijkstra::Radians(cNode & node)
{
	node.setCoordX((node.getCoordX() * pi) / 180);
	node.setCoordY((node.getCoordY() * pi) / 180);
}

float & cDijkstra::haversine(cNode & node1, cNode & node2)
{
		Radians(node1);
	Radians(node2);

	float x1 = sin((node2.getCoordY() - node1.getCoordY()) / 2);
	x1 *= x1; // seno cuadrado de la diferencia de latitudes sobre dos

	float x2 = cos(node1.getCoordY()) * cos(node2.getCoordY());

	float x3 = sin((node2.getCoordX() - node1.getCoordX()) / 2); // seno cuadrado de la diferencia de sus longitudes sobre dos
	x3 *= x3;

	float a = x1 + (x2 * x3);

	float c = asin(sqrt(a));

	float d = (2 * r) * c;
	return d;
}

void cDijkstra::lessTravel(cNode & actual, std::vector<cNode> vector)
{

	for (int i = 0; i < vector.size(); i++) {
		if (vector[i].getLabel() == actual.getLabel()) {
			if (actual.getDistance() < vector[i].getDistance())
				vector[i] = actual;
		}
	}
}

void cDijkstra::pathFind(int & counter, cNode & lastLabel, bool & arriv, std::vector<cEdge>& edges)
{
	while (m_open.size() > 0) {
		if (arriv) {
			break;
		}
		if (!isInVector(m_open[0], m_closed)) { // si el nodopm actual no se encuentra en cerrados
			std::cout << "agregando a cerrados: " << std::endl;
			m_open[0].printNodePM();
			std::cout << std::endl;
			m_closed[counter] = m_open[0];
			for (int i = 0; i < edges.size(); i++) { // ciclo que checa todas las aristas
				if (m_open[0].getLabel() == edges[i].getFirstNodeLabel()) { // si sus etiquetas son iguales
					if (edges[i].getSecondNodeLabel() == lastLabel.getLabel()) {
						arriv = true;
					}
					m_buffer = edges[i].getSecondNode(); // le da un valor a su nodo, al que apunta
					m_buffer.setDistance(0);
					m_buffer.setDistance(edges[i].getWeight(), m_closed[counter].getDistance());
					m_buffer.setPointer(m_closed[counter]); // le da un puntero de donde viene que es el mismo nodopm actual dentro del vector
					if (!isInVector(m_buffer, m_closed)) { // si dicho nodo ya se encuentra cerrado no lo va a agregar a abiertos
						if (isInVector(m_buffer, m_open)) { // si no se encuentra en abiertos lo añade directamente a cerrados, si no analiza si tiene una distancia menor
							lessTravel(m_buffer, m_open);
						}
						else {
							std::cout << "agregando a abiertos: " << std::endl;
							m_buffer.printNodePM();
							std::cout << std::endl;
							m_open.push_back(m_buffer);
						}
					}
				}
			}
			counter++; // crecimiento de nodos para la posible siguiente recursión
			m_open.erase(m_open.begin());
			quicksort(m_open, 0, m_open.size() - 1); // ordenamiento por quicksort del vector de abiertos
			
		}
		else { // si llega a estar dentro del vector, checar que abiertos no esté vacio para realizar siguientes recursiones
				m_open.erase(m_open.begin());
		}
	}


	if (arriv) {
		std::cout << std::endl
			<< "Recorrido exitoso" << std::endl;
		std::cout << "Recorrido: " << std::endl;
		winnerRoute(m_closed, lastLabel);
	}
	else {
		std::cout << std::endl
			<< "El recorrido no se pudo completar, no existe tal nodo" << std::endl;
	}

}

cDijkstra::~cDijkstra()
{
	freeVector();
}

void caStar::Radians(cNode & node) // funcion que convierte las coordenadas de un nodo a radianes
{
	node.setCoordX((node.getCoordX() * pi) / 180);
	node.setCoordY((node.getCoordY() * pi) / 180);
}

float & caStar::haversine(cNode & node1, cNode & node2)
{
	Radians(node1);
	Radians(node2);

	float x1 = sin((node2.getCoordY() - node1.getCoordY()) / 2);
	x1 *= x1; // seno cuadrado de la diferencia de latitudes sobre dos

	float x2 = cos(node1.getCoordY()) * cos(node2.getCoordY());

	float x3 = sin((node2.getCoordX() - node1.getCoordX()) / 2); // seno cuadrado de la diferencia de sus longitudes sobre dos
	x3 *= x3;

	float a = x1 + (x2 * x3);

	float c = asin(sqrt(a));

	float d = (2 * r) * c;
	return d;
}

void caStar::lessTravel(cNode & actual, std::vector<cNode> vector)
{
	for (int i = 0; i < vector.size(); i++) {
		if (vector[i].getLabel() == actual.getLabel()) {
			if (actual.getDistance() < vector[i].getDistance())
				vector[i] = actual;
		}
	}
}

void caStar::pathFind(int & counter, cNode & lastLabel, bool & arriv, std::vector<cEdge>& edges)
{
	while (m_open.size() > 0) {
		if (!isInVector(m_open[0], m_closed)) { // si el nodopm actual no se encuentra en cerrados
			std::cout << "agregando a cerrados: " << std::endl;
			m_open[0].printNodePM();
			std::cout << std::endl;
			m_closed[counter] = m_open[0];
			for (int i = 0; i < edges.size(); i++) { // ciclo que checa todas las aristas
				if (m_open[0].getLabel() == edges[i].getFirstNodeLabel()) { // si sus etiquetas son iguales
					if (m_closed[counter].getLabel() == lastLabel.getLabel()) {
						arriv = true;
						break;
					}
					m_buffer = edges[i].getSecondNode(); // le da un valor a su nodo, al que apunta
					m_buffer.setDistance(0);
					float d = haversine(m_buffer, lastLabel);
					m_buffer.setDistance(edges[i].getWeight(), d);
					m_buffer.setDistance(m_buffer.getDistance(), m_closed[counter].getDistance());
					m_buffer.setPointer(m_closed[counter]); // le da un puntero de donde viene que es el mismo nodopm actual dentro del vector
					if (!isInVector(m_buffer, m_closed)) { // si dicho nodo ya se encuentra cerrado no lo va a agregar a abiertos
						if (!isInVector(m_buffer, m_open)) { // si no se encuentra en abiertos lo añade directamente a cerrados, si no analiza si tiene una distancia menor
							std::cout << "agregando a abiertos: " << std::endl;
							m_buffer.printNodePM();
							std::cout << std::endl;
							m_open.push_back(m_buffer);
						}
					}
				}
			}
			counter++; // crecimiento de nodos para la posible siguiente recursión
			m_open.erase(m_open.begin());
			quicksort(m_open, 0, m_open.size() - 1); // ordenamiento por quicksort del vector de abiertos

		}
		else { // si llega a estar dentro del vector, checar que abiertos no esté vacio para realizar siguientes recursiones
			m_open.erase(m_open.begin());
		}
	}


	if (arriv) {
		std::cout << std::endl
			<< "Recorrido exitoso" << std::endl;
		std::cout << "Recorrido: " << std::endl;
		winnerRoute(m_closed, lastLabel);
	}
	else {
		std::cout << std::endl
			<< "El recorrido no se pudo completar, no existe tal nodo" << std::endl;
	}

}

caStar::~caStar()
{
	freeVector();
}
