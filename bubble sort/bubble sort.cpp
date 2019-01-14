#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void bubblesort_array(int arreglo[], int limite); // función que realiza bubble sort
void ordenar(int & num1, int & num2); // función que cambia de lugar dos enteros
void print_array(int arreglo[], int max); // función que imprime un arreglo

int main() {
	
	int nums[10]{ 28, 11, 2, 59, 39, 47, 0, 7, 40, 29 };
	cout << "arreglo original: " << endl;
	print_array(nums, 10);
	bubblesort_array(nums, 10);
	cout << "arreglo ordenado: " << endl;
	print_array(nums, 10);
	cin.get();
	return 0;
}

void bubblesort_array(int arreglo[], int limite)
{
	for (int i = 0; i < limite; i++)
	{
		for (int j = 0; j <= (limite - 2); j++)
		{
			if (arreglo[j] > arreglo[j + 1]) { // tiene que checar los adyacentes hasta el último elemento del vector
				cout << j + 1 << " iteracion: " << endl;
				ordenar(arreglo[j], arreglo[j + 1]);
				print_array(arreglo, limite);

			}
		}
	}
}

void ordenar(int & num1, int & num2)
{
	int aux = num1;
	num1 = num2;
	num2 = aux;
}

void print_array(int arreglo[], int max)
{
	for (int i = 0; i < max; i++)
	{
		cout << arreglo[i] << " ";
	}
	cout << endl;
}

