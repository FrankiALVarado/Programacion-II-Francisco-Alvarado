#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void quick_sort(int arreglo[], int  min_index, int  max_index);
int sublistas(int arreglo[],   int & min_index, int & max_index); // int para que devuelva un pivote nuevo cada vez que se llame
void ordenar(int & num1, int & num2); // función que cambia de lugar dos enteros
void print_array(int arreglo[], const int & max);

int count = 0; // contador global
//hacer una comparacion programa con el mismo arreglo y comparar tiempos con bubble selection y quick sort
int main() {
	int max_index = 0;
	int arreglo [] {5,4,3,2,1,10,9,8,7,6};
    max_index = (sizeof(arreglo) / sizeof(arreglo[0])) -1;
    cout << max_index << endl;
	cout << "arreglo original: " << endl;
	print_array(arreglo, max_index);

	quick_sort(arreglo, 0, max_index);

	cout << "numero de iteraciones: " << count << endl;
	cout << "arreglo ordenado: " << endl;
	print_array(arreglo, max_index);

	cin.get();
	return 0;
}

void quick_sort(int arreglo[], int min_index,  int  max_index)
{
	
	if (min_index < max_index) {
		int pivot = sublistas(arreglo, min_index, max_index);
		quick_sort(arreglo, min_index, pivot - 1);
		quick_sort(arreglo, pivot + 1, max_index);
	}
}

int sublistas(int arreglo[],  int & min_index,  int & max_index)
{
	int index = min_index;
	for (int i = min_index; i <= max_index; i++) {
		if (arreglo[i] < arreglo[max_index]) {
			index++;
		}
	}
	ordenar(arreglo[index], arreglo[max_index]);
	print_array(arreglo, max_index);
	return(index);
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
