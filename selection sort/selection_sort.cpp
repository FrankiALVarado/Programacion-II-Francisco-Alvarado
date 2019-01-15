#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void selection_sort(int arreglo[], const int & limite); // función que realiza selection sort
void ordenar(int & num1, int & num2); // función que intercambia de lugar 
void print_array(int arreglo[], const int & max); // función para imprimir arreglo

int main() {
	int nums[5]{ 1, 2, 3, 4, 5};
	cout << "arreglo original: " << endl;
	print_array(nums, 5);
	selection_sort(nums, 5);
	cout << "arreglo ordenado: " << endl;
	print_array(nums, 5);
	cin.get();
	return 0;
}

void selection_sort(int arreglo[], const int & limite)
{//agregar una bandera para checar que ya esté ordenado , iteraciones de mas
	int menor = 0, count = 0; // variable utilizada para albergar el valor de i en cada iteración del primer ciclo y usarla para comparaciones sin afectar el arreglo original
	bool penultimo = false;
	for (int i = 0; i < limite - 1; i++) { 
	    menor = i;
		
		for (int j = i+1; j < limite; j++) {
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
	}
	cout << count << " iteracion real: " << endl;
}

void ordenar(int & num1, int & num2)
{
	int aux = num1;
	num1 = num2;
	num2 = aux;
}

void print_array(int arreglo[],const int & max)
{
	for (int i = 0; i < max; i++)
	{
		cout << arreglo[i] << " ";
	}
	cout << endl;
}
