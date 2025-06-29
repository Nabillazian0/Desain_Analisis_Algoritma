/**
 *Program Hashtable dengan OpenAddressing
 *Penampung data menggunakan array
 *Tiga Implementasi menggunakan Linear Probing, Quadric Probing, Double Hashing
 *Populasi data menggunakan fungsi random
 */

#include <iostream>
#include <vector> // Using vector is safer for dynamic arrays
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

// Menggunakan std::vector untuk keamanan dan fleksibilitas, diinisialisasi ke 0
vector<int> storage;
int hdt_boundary;

// ===== FUNGSI HASHING YANG DIPERBAIKI =====

void tambah_linear_probing(int n) {
    bool inserted = false;
    int hash;
    int i = 0;

    while ((!inserted) && (i < hdt_boundary)) {
        // FIX: Probing 'i' ditambahkan ke hash dan menggunakan modulo untuk wrap-around
        hash = ((n % hdt_boundary) + i) % hdt_boundary;

        if (storage[hash] == 0) {
            storage[hash] = n;
            inserted = true;
        } else {
            ++i;
            cout << "Terjadi tabrakan di " << hash << endl;
        }
    }

    if (i == 0) {
        cout << "Langsung" << endl;
    }

    if (!inserted) {
        cout << "Gagal memasukkan " << n << ". Tabel mungkin sudah penuh." << endl;
    } else {
        cout << "Isi Hash [" << hash << "] dengan " << n << endl;
    }
    cout << "=================================================================" << endl;
}

void tambah_quadric_probing(int n) {
    bool inserted = false;
    int hash;
    int i = 0;

    while ((!inserted) && (i < hdt_boundary)) {
        // FIX: Menambahkan modulo di akhir untuk memastikan hash tetap dalam batas array
        hash = ((n % hdt_boundary) + (i * i)) % hdt_boundary;

        if (storage[hash] == 0) {
            storage[hash] = n;
            inserted = true;
        } else {
            ++i;
            cout << "Terjadi tabrakan di " << hash << endl;
        }
    }

    if (i == 0) {
        cout << "Langsung" << endl;
    }
    
    if (!inserted) {
        cout << "Gagal memasukkan " << n << ". Tabel mungkin sudah penuh." << endl;
    } else {
        cout << "Isi Hash [" << hash << "] dengan " << n << endl;
    }
    cout << "==================================================================" << endl;
}

// ===== FUNGSI PRIMA YANG DIPERBAIKI & DISEDERHANAKAN =====

// Fungsi pembantu untuk mengecek apakah sebuah angka itu prima
bool is_prima(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Mencari bilangan prima terdekat SETELAH n
int prima_atas(int n) {
    int num = n + 1;
    while (true) {
        if (is_prima(num)) {
            return num;
        }
        num++;
    }
}

// FIX: Fungsi ini diperbaiki total. Mencari bilangan prima terdekat SEBELUM n.
int prima_bawah(int n) {
    int num = n - 1;
    while (num > 1) {
        if (is_prima(num)) {
            return num;
        }
        num--;
    }
    return 2; // Fallback jika tidak ada prima yang lebih kecil (misal: input n=3)
}


void tambah_double_hashing(int n) {
    cout << "===========================================================" << endl;
    cout << "double hashing......." << endl;
    int hash;
    // FIX: Menggunakan fungsi prima_bawah yang sudah benar
    int hash2_prime = prima_bawah(hdt_boundary);
    bool inserted = false;
    int i = 0;
    
    while ((!inserted) && (i < hdt_boundary)) {
        int h1 = n % hdt_boundary;
        // h2 dibuat agar tidak pernah 0
        int h2 = hash2_prime - (n % hash2_prime); 
        hash = (h1 + i * h2) % hdt_boundary;

        if (storage[hash] == 0) {
            storage[hash] = n;
            inserted = true;
        } else {
            ++i;
            cout << "Terjadi tabrakan di " << hash << endl;
        }
    }

    if (i == 0) {
        cout << "Langsung" << endl;
    }
    
    if (!inserted) {
        cout << "Gagal memasukkan " << n << ". Tabel mungkin sudah penuh." << endl;
    } else {
        cout << "Isi Hash [" << hash << "] dengan " << n << endl;
    }
    cout << "=========================================================" << endl;
}

// ===== FUNGSI UTAMA & PEMBANTU LAINNYA =====

void cetak(int n) {
    cout << endl;
    cout << "Output Program : " << endl;
    // Mencetak seluruh isi hash table, bukan hanya 'n' elemen pertama
    for (int a = 0; a < hdt_boundary; a++) {
        cout << "Hash[" << a << "] = " << storage[a] << endl;
    }
}

int getRandomNumberFromRange(int min, int max) {
    if (min > max) return 0;
    return min + (rand() % (max - min + 1));
}

int main() {
    int n, random_number;
    char pilihan;
    string cara;

    srand((unsigned)time(0));

    cout << "Masukkan jumlah data : ";
    cin >> n;

    // Tentukan batas |T| sebagai bilangan prima terdekat di atas n
    // Ini adalah praktik umum untuk mengurangi tabrakan
    hdt_boundary = prima_atas(n);
    // Inisialisasi storage dengan ukuran yang tepat
    storage.assign(hdt_boundary, 0); 

    cout << "Ukuran Tabel Hash diatur ke: " << hdt_boundary << " (prima terdekat di atas " << n << ")" << endl;
    cout << "Kami menggunakan metode addressing ada 3 cara, pilih salah satu dengan memilih a, b, atau c : " << endl;
    cout << "a. linear probing" << endl;
    cout << "b. quadric probing" << endl;
    cout << "c. double hashing" << endl;
    cout << "Pilih a, b, atau c? ";
    cin >> pilihan;
    cout << endl << endl << "Proses pemasukan data ke hashtable " << endl;

    for (int a = 0; a < n; ++a) {
        // Generate angka random yang lebih bervariasi
        random_number = getRandomNumberFromRange(1, n * 10);
        
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
            cara = "Double Hashing";
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            return 1; // Keluar jika pilihan salah
        }
    }

    cetak(n);
    cout << "\nDiatas adalah hasil output hashtable dengan cara \"" << cara << "\"" << endl;
    
    // Menampilkan rumus yang digunakan dengan lebih akurat
    switch (pilihan) {
    case 'a':
        cout << "h(k, i) = ((k mod " << hdt_boundary << ") + i) mod " << hdt_boundary << endl;
        break;
    case 'b':
        cout << "h(k, i) = ((k mod " << hdt_boundary << ") + i*i) mod " << hdt_boundary << endl;
        break;
    case 'c':
        cout << "h1(k) = k mod " << hdt_boundary << endl;
        cout << "h2(k) = " << prima_bawah(hdt_boundary) << " - (k mod " << prima_bawah(hdt_boundary) << ")" << endl;
        cout << "h(k, i) = (h1(k) + i * h2(k)) mod " << hdt_boundary << endl;
        break;
    }
    
    return 0;
}
