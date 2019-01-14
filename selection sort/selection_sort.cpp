#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void selection_sort(int arreglo[], int limite); // función que realiza selection sort
void ordenar(int & num1, int & num2); // función que intercambia de lugar 
void print_array(int arreglo[], int max); // función para imprimir arreglo

int main() {
	int nums[10]{ 28, 11, 2, 59, 39, 47, 0, 7, 40, 29 };
	cout << "arreglo original: " << endl;
	print_array(nums, 10);
	selection_sort(nums, 10);
	cout << "arreglo ordenado: " << endl;
	print_array(nums, 10);
	cin.get();
}

void selection_sort(int arreglo[], int limite)
{
	int menor = 0; // variable utilizada para albergar el valor de i en cada iteración del primer ciclo y usarla para comparaciones sin afectar el arreglo original
	for (int i = 0; i < limite - 1; i++) { 
	    menor = i;
		for (int j = i+1; j < limite; j++) {
			if (arreglo[menor] > arreglo[j])
				menor = j;
				
		}
		ordenar(arreglo[menor], arreglo[i]);
		cout << i + 1 << " iteracion: " << endl;
		print_array(arreglo, limite);
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
