#include <iostream>
#include <vector>
#include <list>

// Kelas untuk merepresentasikan graf berarah
class DirectedGraph {
private:
    int V; // Jumlah vertex (simpul) dalam graf
    std::vector<std::list<int > > adj; // Adjacency list

public:
    // Konstruktor
    DirectedGraph(int V) {
        this->V = V;
        adj.resize(V); // Mengatur ukuran vector 'adj' sesuai jumlah vertex
    }

    // Fungsi untuk menambahkan edge (panah) dari vertex 'u' ke vertex 'v'
    void addEdge(int u, int v) {
        // Karena ini graf berarah, kita hanya menambahkan 'v' ke list tetangga 'u'.
        adj[u].push_back(v);
    }

    // Fungsi untuk mencetak representasi graf (adjacency list)
    void printGraph() {
        std::cout << "Directed Graph:" << std::endl;
        for (int i = 0; i < V; ++i) {
            std::cout << "Node " << i << " -->";
            // Cetak tetangga untuk setiap node
            for (int neighbor : adj[i]) {
                std::cout << " " << neighbor;
            }
            std::cout << std::endl; // Pindah baris untuk node berikutnya
        }
    }
};

int main() {
    // Buat objek graf berarah dengan 4 vertex (dinomori 0 sampai 3)
    DirectedGraph g(4);

    // Tambahkan edges (panah) sesuai dengan output yang diinginkan
    g.addEdge(0, 1); // Panah dari Node 0 ke Node 1
    g.addEdge(0, 2); // Panah dari Node 0 ke Node 2
    g.addEdge(1, 2); // Panah dari Node 1 ke Node 2
    g.addEdge(2, 3); // Panah dari Node 2 ke Node 3

    // Cetak struktur graf
    g.printGraph();

    // Output tambahan Dev-C++ (akan otomatis muncul)
    // ------------------------------------------
    // Process exited after X.XXXX seconds with return value 0
    // Press any key to continue . . .

    return 0; // Program berakhir dengan sukses
}
