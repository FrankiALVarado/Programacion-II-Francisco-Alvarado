#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void bubblesort_array(int arreglo[], const int & limite); // función que realiza bubble sort
void ordenar(int & num1, int & num2); // función que cambia de lugar dos enteros
void print_array(int arreglo[],  const int & max); // función que imprime un arreglo

int main() {
	
	int nums[5]{ 5, 4, 3, 2, 1};
	cout << "arreglo original: " << endl;
	print_array(nums, 5);
	bubblesort_array(nums, 5);
	cout << "arreglo ordenado: " << endl;
	print_array(nums, 5);
	cin.get();
	return 0;
}

void bubblesort_array(int arreglo[], const int & limite)
{// agregar una bandera para checar que ya esté ordenado - 
	int count = 0; // booleano que es verdadero a no ser que haya un cambio en el segundo ciclo
	for (int i = 0; i < (limite - 1); i++) // le baje una iteracion a este ciclo, antes solo era hasta menor que limite
	{
		bool ordenado = true;
		for (int j = 0; j <= (limite - 2); j++)
		{
			count++;
			if (arreglo[j] > arreglo[j + 1]) { // tiene que checar los adyacentes hasta el último elemento del vector
				ordenar(arreglo[j], arreglo[j + 1]);
				print_array(arreglo, limite);
				ordenado = false;
			}
		}
		if (ordenado) // esto solo será verdadero cuando en toda una iteración no se efectuen cambios
			break;
	}
	cout << count << " iteracion real: " << endl;
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

