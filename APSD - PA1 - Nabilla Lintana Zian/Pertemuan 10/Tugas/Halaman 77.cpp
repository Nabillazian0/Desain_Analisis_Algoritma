#include <iostream>
#include <vector>
#include <limits> // Untuk numeric_limits
#include <iomanip> // Untuk setw

const int INF = std::numeric_limits<int>::max(); // Mendefinisikan nilai tak terhingga

// Fungsi untuk mencari jalur terpendek menggunakan Algoritma Dijkstra
// (Ini adalah implementasi dasar, bisa dioptimalkan dengan priority queue untuk graf besar)
void dijkstra(int startNode, int numCities, const std::vector<std::vector<int & costMatrix,
              std::vector<int>& dist, std::vector<int>& prev) {
    
    std::vector<bool> visited(numCities, false);

    for (int i = 0; i < numCities; ++i) {
        dist[i] = INF; // Inisialisasi jarak semua node ke tak terhingga
        prev[i] = -1;  // Inisialisasi predecessor (jalur sebelumnya)
    }
    dist[startNode] = 0; // Jarak node awal ke dirinya sendiri adalah 0

    for (int count = 0; count < numCities - 1; ++count) {
        // Cari vertex dengan jarak minimum yang belum dikunjungi
        int u = -1;
        int minDistance = INF;

        for (int v = 0; v < numCities; ++v) {
            if (!visited[v] && dist[v] < minDistance) {
                minDistance = dist[v];
                u = v;
            }
        }

        // Jika tidak ada vertex yang dapat dijangkau, keluar
        if (u == -1) break;

        visited[u] = true; // Tandai vertex sebagai sudah dikunjungi

        // Perbarui jarak tetangga
        for (int v = 0; v < numCities; ++v) {
            // Jika ada edge dari u ke v dan v belum dikunjungi
            // dan melalui u memberikan jarak yang lebih pendek ke v
            if (!visited[v] && costMatrix[u][v] != INF && dist[u] != INF &&
                dist[u] + costMatrix[u][v] < dist[v]) {
                
                dist[v] = dist[u] + costMatrix[u][v];
                prev[v] = u; // Simpan u sebagai predecessor dari v
            }
        }
    }
}

// Fungsi untuk mencetak jalur dari startNode ke endNode
void printPath(int endNode, const std::vector<int>& prev) {
    if (endNode == -1) return; // Base case: endNode tidak ada predecessor
    printPath(prev[endNode], prev); // Panggil rekursif untuk predecessor
    std::cout << endNode + 1; // Cetak node (ditambah 1 karena output dimulai dari 1)
    if (prev[endNode] != -1) { // Jika bukan node awal, tambahkan panah
        std::cout << "--->";
    }
}

int main() {
    int numCities;

    std::cout << "Masukkan Jumlah Kota : ";
    std::cin >> numCities;

    // Pastikan jumlah kota valid
    if (numCities <= 0) {
        std::cout << "Jumlah kota harus lebih dari 0." << std::endl;
        return 1;
    }

    // Inisialisasi Cost Matrix
    // Gunakan -1 atau nilai besar untuk menandakan tidak ada koneksi langsung
    std::vector<std::vector<int>> costMatrix(numCities, std::vector<int>(numCities, INF));

    std::cout << "Nilai Cost Matrix" << std::endl;

    // Input nilai Cost Matrix
    for (int i = 0; i < numCities; ++i) {
        std::cout << "Cost Element Baris ke-: " << i + 1 << std::endl;
        for (int j = 0; j < numCities; ++j) {
            int cost;
            std::cin >> cost;
            // Jika cost 0 dan i != j, asumsikan tidak ada jalur langsung atau biaya sangat rendah.
            // Untuk Dijkstra, 0 biasanya adalah biaya ke diri sendiri atau biaya nol antar node yang terhubung.
            // Jika input 0 berarti tidak ada koneksi, ganti dengan INF.
            // Berdasarkan contoh output, 0 sepertinya berarti "tidak ada koneksi" atau "biaya sangat tinggi",
            // atau jika ada koneksi biaya 0, maka itu jalur yang bisa dilewati.
            // Kita asumsikan 0 berarti tidak ada koneksi jika i != j, dan untuk i == j adalah 0.
            if (i == j) {
                costMatrix[i][j] = 0; // Biaya ke diri sendiri adalah 0
            } else if (cost == 0) {
                 costMatrix[i][j] = INF; // Jika input 0, anggap tidak ada jalur
            } else {
                 costMatrix[i][j] = cost;
            }
        }
    }

    // Output "Cost Element Baris ke-:" sesuai format gambar
    // Ini sebenarnya mencetak ulang input dengan format yang sedikit berbeda.
    std::cout << "Cost Element Baris ke-: 1" << std::endl;
    // Asumsi contoh output hanya menampilkan baris pertama
    for (int j = 0; j < numCities; ++j) {
        if (costMatrix[0][j] == INF) {
            std::cout << "INF" << std::endl; // Atau 0 sesuai format input
        } else {
            std::cout << costMatrix[0][j] << std::endl;
        }
    }
    // Lanjutkan untuk baris lainnya jika diperlukan, disesuaikan dengan contoh output
    std::cout << "Cost Element Baris ke-: 2" << std::endl;
     for (int j = 0; j < numCities; ++j) {
        if (costMatrix[1][j] == INF) {
            std::cout << "INF" << std::endl;
        } else {
            std::cout << costMatrix[1][j] << std::endl;
        }
    }
    std::cout << "Cost Element Baris ke-: 3" << std::endl;
     for (int j = 0; j < numCities; ++j) {
        if (costMatrix[2][j] == INF) {
            std::cout << "INF" << std::endl;
        } else {
            std::cout << costMatrix[2][j] << std::endl;
        }
    }

    // --- Bagian Kanan Output ---
    std::cout << std::endl; // Baris kosong untuk pemisah

    // Menampilkan Cost List (Matriks Biaya)
    std::cout << "Cost List" << std::endl;
    for (int i = 0; i < numCities; ++i) {
        for (int j = 0; j < numCities; ++j) {
            if (costMatrix[i][j] == INF) {
                std::cout << std::setw(3) << "0"; // Sesuai dengan format output gambar
            } else {
                std::cout << std::setw(3) << costMatrix[i][j];
            }
        }
        std::cout << std::endl;
    }

    // Mencari Jalur Terpendek (dari node 1 ke node 4 sesuai contoh output)
    // Asumsi: Node awal adalah 1, node tujuan adalah 4.
    // Dalam program kita, ini berarti index 0 ke index 3 (karena 0-indexed)
    int startNode = 0; // Node 1 di output (index 0)
    int endNode = 3;   // Node 4 di output (index 3)

    std::vector<int> dist(numCities); // Jarak terpendek dari startNode
    std::vector<int> prev(numCities); // Predecessor node dalam jalur terpendek

    dijkstra(startNode, numCities, costMatrix, dist, prev);

    std::cout << "\nJalur Terpendek:" << std::endl;
    if (dist[endNode] == INF) {
        std::cout << "Tidak ada jalur dari " << startNode + 1 << " ke " << endNode + 1 << std::endl;
    } else {
        printPath(endNode, prev);
        std::cout << std::endl;
        std::cout << "Minimum Cost: " << dist[endNode] << std::endl;
    }

    return 0;
}
