#pragma once
#include "cPathFinding.h"
#include <fstream>
#include <sstream>
class cGraph 
{
private:
	//miembros
	std::vector<cEdge> m_edges;
	std::vector<cNode> m_nodes;
	//--------------------------------------------------------------------------------

	//metodos
	double & coordx(std::string & text); // no se usa actualmente, formatos viejos
	double & coordy(std::string & text); // no se usa actualmente, formatos viejos
	void initializeGraphFromText(std::ifstream & text);// no se usa actualmente, formatos viejos
	void getGraphFromText(std::ifstream & text); // no se usa actualmente, formatos viejos
	void initializeGraphFromCSV(std::ifstream & text); // funcion temporal para testear el csv
	void getGraphFromCSV(std::ifstream & text);  // funcion temporal para testear el csv
	std::string label(std::string & text);
	void getNodeFromString(bool & arrive, std::string & label, cNode & node); // si detecta el codigo iata o nombre de ciudad, regresa la información del nodo
	//--------------------------------------------------------------------------------

	//printers 
	void printNodes();
	//---------------------------------------------------------------------------------

	//prompts
	//suplantar los algoritmos en uno solo
	void loadOutput(); //prompt para cargar en base a un nombre 
	void depthFistSearchOutput(); // output para realizar una busqueda de profundidad
	void breadthFirstSearchOutput();  // output para realizar una busqueda en amplitud
	void bestFirstOutput(); // outuput para realizar una busqueda del primero mejor
	void dijkstraOutput();
	void aStarOutput();
	void noGraphWarning(); //funcion que avisa al usuario que cargue un grafo antes de usar un método de busqueda

	void pathfindingMenu();

	//parsers
	int edgeNumber(std::string & str); //ciclo que evalua cada renglon de la matriz para saber de cuanto disponer el vector de aristas
	std::string getStringsFromCSV(std::string & str); // funcion que devuelve las strings entre comillas
	std::string getWeightPreview(std::string & str); // funcion identica al parser de strings solo que sin borrar la información
public:
	//constructores
	cGraph();
	cGraph(std::vector<cEdge> _edges, std::vector<cNode> _nodes);
	~cGraph();

	//menu
	void graphMenu();
};

