#include <iostream>
#include <vector>
#include <list>
#include <queue>  
#include <stack>  
 
class UndirectedGraph {
private:
    int V;  
    std::vector < std::list < int < < adj;  

public:
 
    UndirectedGraph(int V) {
        this->V = V;
        adj.resize(V);  
    }
 
    void addEdge(int u, int v) {
        
        adj[u].push_back(v);
        adj[v].push_back(u);  
    }
 
    void printGraph() {
        std::cout << "Representasi Graf Tidak Berarah (Adjacency List):" << std::endl;
        for (int i = 0; i < V; ++i) {
            std::cout << "Vertex " << i << ":";
            for (int neighbor : adj[i]) {
                std::cout << " -- " << neighbor;
            }
            std::cout << std::endl;
        }
    }

    // --- Contoh Traversal Graf (Opsional) ---
 
    void BFS(int startNode) {
        std::cout << "\nBFS Traversal (mulai dari Vertex " << startNode << "):" << std::endl;
        std::vector<bool> visited(V, false);   
        std::queue<int> q; / 

        visited[startNode] = true;
        q.push(startNode);

        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();
            std::cout << currentNode << " ";

            for (int neighbor : adj[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        std::cout << std::endl;
    } 
 
    void DFSUtil(int currentNode, std::vector<bool>& visited) {
        visited[currentNode] = true;
        std::cout << currentNode << " ";

        for (int neighbor : adj[currentNode]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    // DFS (Depth-First Search)
    void DFS(int startNode) {
        std::cout << "\nDFS Traversal (mulai dari Vertex " << startNode << "):" << std::endl;
        std::vector<bool> visited(V, false); // Tandai semua vertex belum dikunjungi
        DFSUtil(startNode, visited);
        std::cout << std::endl;
    }
};

int main() {
    
    UndirectedGraph g(5);
 
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    
    g.printGraph(); 
     
    g.BFS(0);  
    g.DFS(0);  

    return 0;
}

