#include <iostream>
using namespace std;

int main()
{
	int angka[5] = {10, 20, 30, 40, 50};
	
	cout << "Isi array:\n";
	
	for (int i = 0; i < sizeof(angka) / 4; i++)
	{
		cout << "angka[" << i << "] = " << angka[i] << endl;
	}
	
	return 0;
}
