#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int multpor10(int & val);

int main() {
	while (cin) {
		cout << "ingrese un numero para multiplicarlo por 10, ctrl + z y enter para salir" << endl;
		int val;
		cin >> val;
		cout << val << " multiplicado por 10: " << multpor10(val) << endl;

	} 

	return 0;
}

int multpor10(int & val)
{
	return (val << 1) + (val << 3);
}
