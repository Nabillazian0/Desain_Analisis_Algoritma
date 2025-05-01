#include <iostream>
#include <string>

using namespace std;

class Mahasiswa {
public:
    Mahasiswa(string nama, int umur) 
        : nama_(nama), umur_(umur) {
        cout << "Constructor Mahasiswa" << endl;
    }

    ~Mahasiswa() {
        cout << "== Contoh Destructor Mahasiswa ==" << endl;
    }

    void TampilkanBiodata() {
        cout << "Nama: " << nama_ << endl; 
        cout << "Umur: " << umur_ << endl;
    }

private:
    string nama_;
    int umur_;
};

int main() {
    Mahasiswa mhs("Katarina", 20); 
    mhs.TampilkanBiodata(); 

    return 0; 
}
