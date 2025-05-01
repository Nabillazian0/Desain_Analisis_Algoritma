// SAYID ARYA (242310007)
// NABILLA  (242310040)
#include <iostream>
#include <string>
using namespace std;

class Produk {
private:
    int id;
    string nama;
    int harga;

public:
    void setId(int i) {
        id = i;
    }
    void setNama(string n) {
        nama = n;
    }
    void setHarga(double h) {
        harga = h;
    }

    int getId() const {
        return id;
    }
    string getNama() const {
        return nama;
    }
    double getHarga() const {
        return harga;
    }

    void tampilkan() const {
        cout << "ID Produk   : " << id << endl;
        cout << "Nama Produk : " << nama << endl;
        cout << "Harga       : Rp " << harga << endl;
    }
};

int cariProdukById(Produk produkList[], int n, int cariId) {
    for (int i = 0; i < n; ++i) {
        if (produkList[i].getId() == cariId) {
            return i;
        }
    }
    return -1;
}

int main() {
    int jumlah;
    cout << "Masukkan jumlah produk : ";
    cin >> jumlah;

    Produk daftarProduk[50]; 

    for (int i = 0; i < jumlah; ++i) {
        int id;
        string nama;
        double harga;

        cout << "\nProduk ke-" << i + 1 << endl;
        cout << "ID    : ";
        cin >> id;
        cout << "Nama  : ";
        cin.ignore();
        getline(cin, nama);
        cout << "Harga : ";
        cin >> harga;

        daftarProduk[i].setId(id);
        daftarProduk[i].setNama(nama);
        daftarProduk[i].setHarga(harga);
    }

    int idCari;
    cout << "\nMasukkan ID produk yang ingin dicari : ";
    cin >> idCari;

    int index = cariProdukById(daftarProduk, jumlah, idCari);
    if (index != -1) {
        cout << "\nProduk ditemukan :\n";
        daftarProduk[index].tampilkan();
    } else {
        cout << "\nProduk dengan ID " << idCari << " tidak ditemukan.\n";
    }

    return 0;
}
