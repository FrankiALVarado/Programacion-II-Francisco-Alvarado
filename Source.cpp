#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool par(int & val);

int main() {
	while (cin) {
		cout << "ingrese un numero y le dire si es par o impar, ctrl + z y enter para salir" << endl;
		int val = 0;
		cin >> val;
		if (par(val))
			cout << val << " es par" << endl;
		else
			cout << val << " es impar" << endl;
	}
	cin.clear();
	cin.ignore();
	cin.get();
	
	return 0;
}

bool par(int & val)
{
	return (val & 1 == 1) ? false : true;
}
