#include <iostream>
using namespace std;

int main() {
	int a;
	
	cout << "Masukkan sebuah angka: ";
	cin >> a;
	
	if ( a % 2 == 0)
		cout << a << " adalah bilangan genap.";
	else 
		cout << a << " adalah bilangan ganjil.";
}
