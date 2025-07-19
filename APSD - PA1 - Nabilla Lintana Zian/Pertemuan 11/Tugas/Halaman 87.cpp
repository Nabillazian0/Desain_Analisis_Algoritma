#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define V 6 

int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Jarak terpendek dari node 1 ke node 5 adalah " << dist[4] << endl;
}

int main() {
    int graph[V][V] = {
       
        {  0,  7,  9,  0,  0, 14 }, 
        {  7,  0,  0, 10,  0,  0 }, 
        {  9,  0,  0, 11,  0,  2  }, 
        {  0, 10, 11,  0,  6,  0  }, 
        {  0,  0,  0,  6,  0,  9  }, 
        { 14, 0,  2,  0,  9,  0  }  
    };

    dijkstra(graph, 0); 
    return 0;
}

