#include <bits/stdc++.h>
#define int long long int
using namespace std;


class Graph {

    // DFS and BFS in O(V + E) time
    // O(V + E) : V = number of vertices, E = number of edges
    // complexity is O(V + E) because
    // we do vis[node] = true only when we push it in the queue which is done only once for each node so --> V
    // we check the value of vis[node] for every child of the node so --> 2 * E (in the worst case,directed graph)

public:
    int n;
    vector<vector<int>> adj;
    Graph(int n) {
        this->n = n;
        adj.resize(n);
    }
    void addEdge(int u, int v, bool bidir = true) {
        // 0 based indexing
        // O(1)
        // we suppose that the the graph is undirected by default, you can change it by passing false in the third argument
        adj[u].push_back(v);
        if (bidir) adj[v].push_back(u);
    }
    void bfs(int src) {
        // O(V + E)
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(src);
        vis[src] = true;// mark the source node as visited (pushed in the queue)
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (auto child : adj[node]) {
                if (!vis[child]) {
                    q.push(child);
                    vis[child] = true;
                }
            }
        }
    }
    void dfs(int src, vector<bool>& vis) {
        // O(V + E) 
        vis[src] = true;
        cout << src << " ";
        for (auto child : adj[src]) {
            if (!vis[child]) {
                dfs(child, vis);
            }
        }
    }
    void dfs(int src) {
        // O(V + E)
        vector<bool> vis(n, false);
        dfs(src, vis);
    }
    void print() {
        for (int i = 0;i < n;i++) {
            cout << i << " -> ";
            for (auto child : adj[i]) {
                cout << child << " ";
            }
            cout << "\n";
        }
    }
    void shortest_path(int src) {
        //BFS
        //O(V + E)
        //works only in unweighted graphs
        //the first time a node is visited is the shortest path to that node
        //the dist[child] = dist[parent] + 1
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        while (!q.empty()) {
            int parent = q.front();
            q.pop();
            for (auto child : adj[parent]) {
                if (dist[child] == -1) {
                    q.push(child);
                    dist[child] = dist[parent] + 1;
                }
            }
        }
        for (int i = 0;i < n;i++) {
            cout << "Distance from " << src << " to " << i << " is " << dist[i] << "\n";
        }

    }
    void shortest_path(int src, int dest) {
        //BFS
        //O(V + E)
        //works only in unweighted graphs
        //the first time a node is visited is the shortest path to that node
        //the dist[child] = dist[parent] + 1
        vector<int> dis(n, -1);
        queue<int> q;
        vector<int> parent(n, -1);
        q.push(src);
        dis[src] = 0;
        while (!q.empty()) {
            int p = q.front();
            if (p == dest) break;
            q.pop();
            for (auto child : adj[p]) {
                if (dis[child] == -1) {
                    q.push(child);
                    dis[child] = dis[p] + 1;
                    parent[child] = p;
                }
            }
        }

        int temp = dest;
        while (temp != -1) {
            cout << temp << " ";
            temp = parent[temp];
        }


    }
};
void solve() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.print();
    g.bfs(1);
    cout << "\n";
    g.dfs(1);
    cout << "\n";
    g.shortest_path(1);
    cout << "\n";
    g.shortest_path(1, 6);
    cout << "\n";
    g.shortest_path(0, 5);
}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}