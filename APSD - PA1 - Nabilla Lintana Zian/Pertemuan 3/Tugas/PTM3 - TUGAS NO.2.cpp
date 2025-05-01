#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];  
    int i = (low - 1);     

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); 
    return (i + 1);
}


void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "=== Program Quick Sort ===" << endl;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Masukkan " << n << " angka:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> arr[i];
    }
    cout << "\nArray sebelum diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    quickSort(arr, 0, n - 1);

    cout << "\nArray setelah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
