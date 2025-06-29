#include <iostream>
using namespace std;

class DoubleHashingHashTable {
private:
    int *table;
    int size;
    int count;
    const int DELETED = -1;

    int hash1(int key) {
        return key % size;
    }

    int hash2(int key) {
        // Pastikan hash2 tidak nol, gunakan bilangan prima lebih kecil dari size
        return 7 - (key % 7);
    }

public:
    DoubleHashingHashTable(int s) {
        size = s;
        count = 0;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = -2; // -2 artinya slot kosong
    }

    ~DoubleHashingHashTable() {
        delete[] table;
    }

    void insert(int key) {
        if (count == size) {
            cout << "Hash table penuh, tidak bisa insert key: " << key << endl;
            return;
        }

        int idx = hash1(key);
        int step = hash2(key);

        int i = 0;
        while (table[(idx + i * step) % size] != -2 && table[(idx + i * step) % size] != DELETED && table[(idx + i * step) % size] != key) {
            i++;
            if (i == size) {
                cout << "Tidak bisa menemukan slot kosong untuk key: " << key << endl;
                return;
            }
        }

        if (table[(idx + i * step) % size] != key) {
            table[(idx + i * step) % size] = key;
            count++;
        }
    }

    int search(int key) {
        int idx = hash1(key);
        int step = hash2(key);

        int i = 0;
        while (table[(idx + i * step) % size] != -2) {
            if (table[(idx + i * step) % size] == key) {
                return (idx + i * step) % size;
            }
            i++;
            if (i == size) break;
        }
        return -1;
    }

    void remove(int key) {
        int idx = search(key);
        if (idx != -1) {
            table[idx] = DELETED;
            count--;
        }
        else {
            cout << "Key tidak ditemukan: " << key << endl;
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            if (table[i] == -2) cout << "Kosong";
            else if (table[i] == DELETED) cout << "Deleted";
            else cout << table[i];
            cout << endl;
        }
    }
};

int main() {
    DoubleHashingHashTable hashTable(13);

    int keysToInsert[] = {18, 41, 22, 44, 59, 32, 31, 73};
    int n = sizeof(keysToInsert) / sizeof(keysToInsert[0]);

    for (int i = 0; i < n; i++) {
        hashTable.insert(keysToInsert[i]);
    }

    cout << "Hash Table setelah insert:" << endl;
    hashTable.display();

    int keySearch = 44;
    int idx = hashTable.search(keySearch);
    if (idx != -1)
        cout << "Key " << keySearch << " ditemukan di index " << idx << endl;
    else
        cout << "Key " << keySearch << " tidak ditemukan" << endl;

    // Hapus key
    hashTable.remove(22);
    cout << "Hash Table setelah menghapus key 22:" << endl;
    hashTable.display();

    return 0;
}

