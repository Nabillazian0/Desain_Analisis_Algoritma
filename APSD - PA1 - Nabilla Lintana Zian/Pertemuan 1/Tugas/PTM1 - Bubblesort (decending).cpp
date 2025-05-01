#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n)
{
	int i, j, tmp;
	for (i = 0; i < n; i++)	{
		for (j = n - 1; j > 0 + i; j--)	{
			if (arr[j] > arr[j-1]){		
				tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
			}
		}	
	}
}

int main(){
	int array[100], n, i;
	
	cout << "Masukkan jumlah elemen: ";
	cin >> n;
	
	cout << "Masukkan nilai:\n";
	for (i = 0; i < n; i++)	{
		cin >> array[i];
	}
	
	cout << "Array sebelum di sort:\n";
	for (i = 0; i < n; i++)	{
		cout << array[i] << ' ';
	}
	cout << endl;
	
	bubble_sort(array, n);
	
	cout << "Hasil setelah di Bubble Sort:\n";
	for (i = 0; i < n; i++)	{
		cout << array[i] << ' ';
	}
}
