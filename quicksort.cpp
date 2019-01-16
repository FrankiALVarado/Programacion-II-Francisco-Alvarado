#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void quick_sort(int arreglo[], int  min_index, int max_index);
int sublistas(int arreglo[],  const int & min_index, const int & max_index); // int para que devuelva un pivote nuevo cada vez que se llame
void ordenar(int & num1, int & num2); // funci�n que cambia de lugar dos enteros
void print_array(int arreglo[], const int & max);

int count = 0, swaps = 1; // variable para contadores y la otra para manejar si hubo cambios en una iteracion;
int main() {
	int max_index = 0;
	int arreglo [] {1, 2, 3, 4,5};
    max_index = (sizeof(arreglo) / sizeof(arreglo[0])) -1;

	cout << "arreglo original: " << endl;
	print_array(arreglo, max_index);

	quick_sort(arreglo, 0, max_index);

	cout << "numero de iteraciones: " << count << endl;
	cout << "arreglo ordenado: " << endl;
	print_array(arreglo, max_index);

	cin.get();
	return 0;
}

void quick_sort(int arreglo[], int min_index,  int max_index)
{
	
	if (min_index < max_index && ::swaps > 0) {
		int pivot = sublistas(arreglo, min_index, max_index);
		quick_sort(arreglo, min_index, pivot - 1);
		quick_sort(arreglo, pivot + 1, max_index);
	}

}

int sublistas(int arreglo[], const int & min_index, const int & max_index)
{
	int pivot = max_index; //en este caso el pivote siempre ser� el �ltimo indice
	::swaps = 0;
	for (int i = max_index - 1; i >= min_index; i--) { // ciclo siempre va a checar a la izquierda del pivote
		if (arreglo[i] > arreglo[pivot]) {
			ordenar(arreglo[i], arreglo[pivot]);
			pivot--; // resta para mantener ubicado correctamente la posicion del pivote
			::swaps++;
		}
		count++;
	}
	return pivot;
	
}

void ordenar(int & num1, int & num2)
{
	int aux = num1;
	num1 = num2;
	num2 = aux;
}


void print_array(int arreglo[], const int & max)
{
	for (int i = 0; i <= max; i++)
	{
		cout << arreglo[i] << " ";
	}
	cout << endl;
}