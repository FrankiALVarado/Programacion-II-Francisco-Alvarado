#include <iostream>

using std::cin;
using std::cout;
using std::endl;


int sum_seq(int & start, int & end, int & step);

int main() {
	int start, end, step;
	while (cin) {
		cout << "ingrese inicio, fin y step, ctrl z + enter para salir" << endl;
		cin >> start;
		cin >> end;
		cin >> step;

		cout << "la suma de la secuencia es: " << sum_seq(start, end, step) << endl;
	}

	return 0;
}

int sum_seq(int & start, int & end, int & step)
{
	if (start > end)
		return 0;

	int rep = (end - start) / step;
	return start * (rep + 1) + step * (rep *rep + rep) / 2;
}
