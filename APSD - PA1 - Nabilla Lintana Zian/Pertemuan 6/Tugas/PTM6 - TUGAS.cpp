#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Buku {
    string judul;
    string lokasiRak;
};

int binarySearch(Buku daftarBuku[], int jumlah, string target) {
    int kiri = 0, kanan = jumlah - 1;
    while (kiri <= kanan) {
        int tengah = (kiri + kanan) / 2;
        if (daftarBuku[tengah].judul == target) {
            return tengah;
        } else if (daftarBuku[tengah].judul < target) {
            kiri = tengah + 1;
        } else {
            kanan = tengah - 1;
        }
    }
    return -1; 
}

void urutkanBuku(Buku daftarBuku[], int jumlah) {
    sort(daftarBuku, daftarBuku + jumlah, [](Buku a, Buku b) {
        return a.judul < b.judul;
    });
}

int main() {
    const int jumlahBuku = 5;
    Buku daftarBuku[jumlahBuku] = {
        {"Struktur Data", "Rak A2"},
        {"Algoritma Pemrograman", "Rak A1"},
        {"Sistem Operasi", "Rak B1"},
        {"Basis Data", "Rak A3"},
        {"Jaringan Komputer", "Rak B2"}
    };

    urutkanBuku(daftarBuku, jumlahBuku);

    string judulDicari;
    cout << "Masukkan judul buku yang ingin dicari: ";
    getline(cin, judulDicari);

    int index = binarySearch(daftarBuku, jumlahBuku, judulDicari);

    if (index != -1) {
        cout << "Buku ditemukan di " << daftarBuku[index].lokasiRak << endl;
    } else {
        cout << "Buku tidak ditemukan dalam daftar." << endl;
    }

    return 0;
}
