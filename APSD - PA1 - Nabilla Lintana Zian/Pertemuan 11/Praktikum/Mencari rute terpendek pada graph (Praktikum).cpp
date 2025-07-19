#include <bits/stdc++.h>
#define MAX 100005
#define INF INT_MAX

using namespace std;

vector<pair<int, int> > adj[MAX];
bool vis[MAX];                   
int dist[MAX];                  

void dijkstra(int start) {
    memset(vis, false, sizeof(vis));

    for (int i = 0; i < MAX; i++)
        dist[i] = INF;

    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, start});

    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();

        int x = p.second;
        if (vis[x]) continue;
        vis[x] = true;

        for (int i = 0; i < adj[x].size(); i++) {
            int e = adj[x][i].first;
            int w = adj[x][i].second;

            if (dist[x] + w < dist[e]) {
                dist[e] = dist[x] + w;
                pq.push({dist[e], e});
            }
        }
    }
}

int main() {
    // Membuat graph
	adj[1].push_back({2, 5});
	adj[2].push_back({1, 5});
	adj[1].push_back({3, 10});
	adj[3].push_back({1, 10});
	adj[2].push_back({4, 12});
	adj[4].push_back({2, 12});
	adj[3].push_back({4, 7});
	adj[4].push_back({3, 7});
	
	dijkstra(1);
	
	cout << "Jarak terpendek dari node 1 ke node 4 adalah " << dist[4] << endl;

	return 0;
}
