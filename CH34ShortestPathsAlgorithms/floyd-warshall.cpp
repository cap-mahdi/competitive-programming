#include <bits/stdc++.h>
#define int long long int
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V, vector<int>(V, INT_MAX));
        for (int i = 0;i < V;i++) {
            adj[i][i] = 0;
        }
    }
    void addEdge(int u, int v, int w) {
        adj[u][v] = w;
    }
    void floydWarshall() {
        //O(V^3)
        //all pair shortest path for directed graph (can be used for undirected graph also)
        //dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j])
        //dp[i][j] = distance from i to j
        //can be used to detect negative cycle
        vector<vector<int>> dist(adj);
        for (int k = 0;k < V;k++) {
            for (int i = 0;i < V;i++) {
                for (int j = 0;j < V;j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                        //avoid a
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        //detect negative cycle
        for (int i = 0;i < V;i++) {
            if (dist[i][i] < 0) {
                cout << "Negative cycle found";
                return;
            }
        }
        for (int i = 0;i < V;i++) {
            for (int j = 0;j < V;j++) {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }


    }

};

void solve() {
    Graph g(4);
    g.addEdge(0, 2, -2);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 1, -1);
    g.addEdge(1, 0, 4);
    g.floydWarshall();
}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}