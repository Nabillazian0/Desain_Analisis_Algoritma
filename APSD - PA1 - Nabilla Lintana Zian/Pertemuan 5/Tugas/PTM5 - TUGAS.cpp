#include <iostream>
#include <string>

using namespace std;
class Mahasiswa {   
public:
string nama;
string umur;
string jurusan;
string fakultas;
string statusMahasiswa;

virtual void tampilkanData () {
    cout << "Data Mahasiswa" << endl;
    cout << "Nama " << nama << endl;
    cout << "Umur " << umur << endl;
    cout << "Jurusan " << jurusan << endl;
    cout << "Fakultas " << fakultas << endl;
    cout << "Status mahasiswa " << statusMahasiswa << endl;
    
}

};

class MahasiswaB : public Mahasiswa
{
    public:
    void tampilkanData () {
    cout << "Data Mahasiswa" << endl;
    cout << "Nama " << nama << endl;
    cout << "Umur " << umur << endl;
    cout << "Jurusan " << jurusan << endl;
    cout << "Fakultas " << fakultas << endl;
    cout << "Status mahasiswa " << statusMahasiswa << endl;
}

};

int main()
{
MahasiswaB siswaB;
siswaB.nama = "Tito";
siswaB.umur = "20";
siswaB.jurusan ="TI";
siswaB.fakultas = "Informatika";
siswaB.statusMahasiswa = "mahasiswaAktif"; 
MahasiswaB siswaC;
siswaC.nama = "ipul";
siswaC.umur = "97";
siswaC.jurusan ="";
siswaC.fakultas = "Informatikaa";
siswaC.statusMahasiswa = "mahasiswaAktif";
siswaB.tampilkanData();
siswaC.tampilkanData();
return 0;
}
