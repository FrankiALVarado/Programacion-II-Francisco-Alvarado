#include <iostream>
#include <string>
using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::to_string;

void par();

int main() {
	par();
	return 0;
}
		

	void par()
	{
		int num = 0;
		cout << "Ingrese un numero para saber si es par o impar" << endl;
		cin >> num;

		string nums = to_string(num);
		
		if (nums[nums.size() - 1] == '0' || nums[nums.size() - 1] == '2' || nums[nums.size() - 1] == '4' || nums[nums.size() - 1] == '6' || nums[nums.size() - 1] == '8') {
			cout << num << " es par" << endl;
		}
		else {
			cout << num << " es impar" << endl;
		}

		cout << "Quiere ingresar otro numero? (s/n)" << endl;
		char elec = ' ';
		cin >> elec;
		switch (elec)
		{
		case 's':
			par();
		default:
			break;
		}
	}
