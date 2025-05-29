#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Penumpang {
    string nama;
    string noKTP;
    string tujuan;
};

void tampilkanPenumpang(const Penumpang& p, int nomor) {
    cout << nomor << ". Nama     : " << p.nama << endl;
    cout << "   No KTP   : " << p.noKTP << endl;
    cout << "   Tujuan   : " << p.tujuan << endl;
}

int main() {
    queue<Penumpang> antrean;
    int pilihan;

    do {
        cout << "\n=== Sistem Antrean Loket Tiket Kereta ===" << endl;
        cout << "1. Tambah Penumpang ke Antrean" << endl;
        cout << "2. Layani Penumpang" << endl;
        cout << "3. Lihat Antrean Saat Ini" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;
        cin.ignore(); 

        if (pilihan == 1) {
            Penumpang p;
            cout << "Masukkan nama: ";
            getline(cin, p.nama);
            cout << "Masukkan nomor KTP: ";
            getline(cin, p.noKTP);
            cout << "Masukkan tujuan: ";
            getline(cin, p.tujuan);
            antrean.push(p);
            cout << "Penumpang " << p.nama << " berhasil ditambahkan ke antrean." << endl;

        } else if (pilihan == 2) {
            if (antrean.empty()) {
                cout << "Antrean kosong. Tidak ada penumpang yang bisa dilayani." << endl;
            } else {
                Penumpang dilayani = antrean.front();
                cout << "\nMelayani penumpang:" << endl;
                tampilkanPenumpang(dilayani, 1);
                antrean.pop();
            }

        } else if (pilihan == 3) {
            if (antrean.empty()) {
                cout << "Antrean kosong." << endl;
            } else {
                cout << "\nDaftar antrean penumpang:" << endl;
                queue<Penumpang> temp = antrean;
                int nomor = 1;
                while (!temp.empty()) {
                    tampilkanPenumpang(temp.front(), nomor++);
                    temp.pop();
                }
            }

        } else if (pilihan == 4) {
            cout << "Terima kasih telah menggunakan sistem loket tiket kereta." << endl;
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }

    } while (pilihan != 4);

    return 0;
}
