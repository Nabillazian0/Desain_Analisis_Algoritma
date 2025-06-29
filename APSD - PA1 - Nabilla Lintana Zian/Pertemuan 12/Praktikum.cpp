#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

const int MAX = 100;
int storage[MAX];
int hdt_boundary;

// Fungsi Linear Probing
void tambah_linear_probing(int n) {
    bool inserted = false;
    int hash;
    int i = 0;

    while (!inserted && i < hdt_boundary) {
        hash = (n % hdt_boundary) + i;
        if (storage[hash] == 0) {
            storage[hash] = n;
            inserted = true;
        } else {
            ++i;
            cout << "Terjadi tabrakan di " << hash << endl;
        }
    }

    if (i == 0)
        cout << "Langsung" << endl;

    cout << "Isi hash[" << hash << "] dengan " << n << endl;
    cout << "===========================================" << endl;
}

// Fungsi Quadratic Probing
void tambah_quadric_probing(int n) {
    bool inserted = false;
    int hash;
    int i = 0;

    while (!inserted && i < hdt_boundary) {
        hash = (n % hdt_boundary) + (i * i);
        if (storage[hash] == 0) {
            storage[hash] = n;
            inserted = true;
        } else {
            ++i;
            cout << "Terjadi tabrakan di " << hash << endl;
        }
    }

    if (i == 0)
        cout << "Langsung" << endl;

    cout << "Isi hash[" << hash << "] dengan " << n << endl;
    cout << "===========================================" << endl;
}

// Fungsi Mencari Bilangan Prima di Atas
int prima_atas(int n) {
    if (n % 2 == 0)
        n = n + 1;
    else
        n = n + 2;

    bool ketemu = false;

    while (!ketemu) {
        bool prima = true;
        if (n % 2 == 0)
            prima = false;
        else {
            int i = 3;
            while (prima && i <= sqrt(n)) {
                if (n % i == 0)
                    prima = false;
                i += 2;
            }
        }

        if (prima)
            ketemu = true;
        else
            n = n + 2;
    }

    return n;
}

// Fungsi Mencari Bilangan Prima di Bawah (untuk hashing ke-2)
int prima_bawah() {
    int n = hdt_boundary - 1;
    while (n > 1) {
        bool prima = true;
        for (int i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                prima = false;
                break;
            }
        }
        if (prima) return n;
        n--;
    }
    return 2;
}

// Fungsi Double Hashing
void tambah_double_hashing(int n) {
    int hash;
    int hash2 = prima_bawah();
    bool inserted = false;
    int i = 0;

    while (!inserted && i < hdt_boundary) {
        hash = ((n % hdt_boundary) + i * ((n % hash2) + 1)) % hdt_boundary;

        if (storage[hash] == 0) {
            storage[hash] = n;
            inserted = true;
        } else {
            ++i;
            cout << "Terjadi tabrakan di " << hash << endl;
        }
    }

    if (i == 0)
        cout << "Langsung" << endl;

    cout << "Isi hash[" << hash << "] dengan " << n << endl;
    cout << "===========================================" << endl;
}

// Fungsi Cetak Output Hashtable
void cetak(int n) {
    cout << endl;
    cout << "Output program : " << endl;
    for (int a = 0; a < n; ++a) {
        cout << "hash[" << a << "] = " << storage[a] << endl;
    }
}

// Fungsi Generate Angka Random
int getRandomNumberFromRange(int min, int max) {
    return min + (rand() % (max - min));
}

// Main Program
int main() {
    int n, random_number;
    char pilihan;
    string cara;

    srand((unsigned)time(0));

    cout << "Masukan jumlah data : ";
    cin >> n;

    cout << "Kami menggunakan metode open addressing ada 3 cara. pilih salah satu dengan memilih a,b, atau c : " << endl;
    cout << "a. linear probing" << endl;
    cout << "b. quadric probing" << endl;
    cout << "c. double hashing" << endl;
    cout << "Pilih a,b, atau c ? ";
    cin >> pilihan;

    cout << endl << endl << "Proses pemasukan data ke hashtable " << endl;

    hdt_boundary = prima_atas(n);

    for (int a = 0; a < n; ++a) {
        random_number = getRandomNumberFromRange(0, n);

        switch (pilihan) {
        case 'a':
            tambah_linear_probing(random_number);
            cara = "Linear Probing";
            break;
        case 'b':
            tambah_quadric_probing(random_number);
            cara = "Quadric Probing";
            break;
        case 'c':
            tambah_double_hashing(random_number);
            cara = "Double hashing";
            break;
        }
    }

    // Output hasil akhir
    cetak(n);
    cout << "Diatas adalah hasil output Hashtable dengan cara \"" << cara << "\"" << endl;

    switch (pilihan) {
    case 'a':
        cout << "h(k) = (k mod " << hdt_boundary << ") + i" << endl;
        break;
    case 'b':
        cout << "h(k) = (k mod " << hdt_boundary << ") + i*i" << endl;
        break;
    case 'c':
        cout << "h1(k) = k mod " << hdt_boundary << endl;
        break;
    }

    return 0;
}
