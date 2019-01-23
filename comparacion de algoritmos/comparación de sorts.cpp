#include <iostream>
#include <time.h>

using std::cin;
using std::cout;
using std::endl;


void ordenar(int & num1, int & num2);
void print_array(int arreglo[], const int & max);
void selection_sort(int arreglo[], const int & limite);
void bubblesort_array(int arreglo[], const int & limite);
int sublistas(int arreglo[], const int & min_index, const int & max_index);
void quick_sort(int arreglo[], int  min_index, int  max_index);
double timelapse(unsigned t1, unsigned t2); // función que regresa la variación de los clock ticks en segundos


int count = 0, swaps = 0;

int main() {

	int num_datos = 0;
	cout << "Numero de datos: ";
	cin >> num_datos;

	int * arr1 = new int[num_datos];
	
	for (int i = 0; i < num_datos; i++) {
		arr1[i] = rand();
	}
	
	int  * arr2 = new int[num_datos];
		
	int * arr3 = new int[num_datos];
	

	for (int i = 0; i < num_datos; i++) {
		arr2[i] = arr1[i];
		arr3[i] = arr1[i];
	}

	unsigned t1, t2;
	double tiempo;
	/*
	t1 = clock();
	bubblesort_array(arr1, num_datos);
	t2 = clock();
	tiempo = timelapse(t1, t2);
	cout << "tiempo de bubblesort: " << tiempo << endl;
	cout << "arreglo ordenado por bubble sort: " << endl;
	//print_array(arr1, n);

	cout << endl;

	t1 = clock();
	selection_sort(arr2, num_datos);
	t2 = clock();
	tiempo = timelapse(t1, t2);
	cout << "tiempo de selection sort: " << tiempo << endl;
	cout << "arreglo ordenado por selection sort: " << endl;
	//print_array(arr2, n);

	cout << endl;
	*/
	t1 = clock();
	quick_sort(arr3, 0, num_datos - 1);
	t2 = clock();
	tiempo = timelapse(t1, t2);
	cout << ::count << " iteraciones quick sort" << endl;
	cout << ::swaps << " swaps quick sort" << endl;
	cout << "tiempo de quick sort: " << tiempo << endl;
	cout << "arreglo ordenado por selection sort: " << endl;
	

	cin.get();
	cin.ignore();
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	return 0;
}

int sublistas(int arreglo[], const int & min_index, const int & max_index)
{
	int index = min_index;
	for (int i = min_index; i <= max_index; i++) {
		if (arreglo[i] < arreglo[max_index]) {
			index++;
		}
		count++;
	}
	ordenar(arreglo[index], arreglo[max_index]);
	swaps++;
	return index;
}

void quick_sort(int arreglo[], int min_index, int  max_index)
{

	if (min_index < max_index) {
		int pivot = sublistas(arreglo, min_index, max_index);
		quick_sort(arreglo, min_index, pivot - 1);
		quick_sort(arreglo, pivot + 1, max_index);
	}
}

double timelapse(unsigned t1, unsigned t2)
{
	return (double (t2 - t1) / CLOCKS_PER_SEC);
}


void ordenar(int & num1, int & num2)
{
	int aux = num1;
	num1 = num2;
	num2 = aux;
}
void print_array(int arreglo[], const int & max)
{
	for (int i = 0; i < max; i++)
	{
		cout << arreglo[i] << " ";
	}
	cout << endl;
}

void selection_sort(int arreglo[], const int & limite)
{//agregar una bandera para checar que ya esté ordenado , iteraciones de mas
	int menor = 0, count = 0, swaps = 0; // variable utilizada para albergar el valor de i en cada iteración del primer ciclo y usarla para comparaciones sin afectar el arreglo original
	bool penultimo = false;
	for (int i = 0; i < limite - 1; i++) {
		menor = i;

		for (int j = i + 1; j < limite; j++) {
			count++;
			if (arreglo[menor] > arreglo[j]) {
				menor = j;
				
			}
			if (i == (limite - 2) && arreglo[menor] > arreglo[j]) // esto es una condicional que mientras i esté en su penultima iteracion y no vaya a hacer un cambio, de positivo a un bool para cerrar el ciclo.
				penultimo = true;
		}
		if (penultimo)
			break;
		ordenar(arreglo[menor], arreglo[i]);
		swaps++;
	}
	cout << count << " iteraciones selection sort " << endl;
	cout << swaps << " swaps selection sort" << endl;
}

void bubblesort_array(int arreglo[], const int & limite)
{// agregar una bandera para checar que ya esté ordenado - 
	int count = 0, swaps = 0; // booleano que es verdadero a no ser que haya un cambio en el segundo ciclo
	for (int i = 0; i < (limite - 1); i++) // le baje una iteracion a este ciclo, antes solo era hasta menor que limite
	{
		bool ordenado = true;
		for (int j = 0; j <= (limite - 2); j++)
		{
			count++;
			if (arreglo[j] > arreglo[j + 1]) { // tiene que checar los adyacentes hasta el último elemento del vector
				ordenar(arreglo[j], arreglo[j + 1]);
				ordenado = false;
				swaps++;
			}
		}
		if (ordenado) // esto solo será verdadero cuando en toda una iteración no se efectuen cambios
			break;
	}
	cout << count << " iteraciones bubblesort " << endl;
	cout << swaps << "swaps en bubblesort " << endl;
}