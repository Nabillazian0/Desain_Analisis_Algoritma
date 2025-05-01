#include <iostream>
using namespace std;

int main()
{
	int user_input;
	cout << "Masukkan sebuah angka: ";
	cin >> user_input;
	
	if (user_input % 2 == 0)
	{
		cout << user_input << " adalah bilangan genap.";
	}
	else
	{
		cout << user_input << " adalah bilangan ganjil.";
	}
	
	return 0;
}
