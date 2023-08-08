#include <bits/stdc++.h>
#define int long long int
using namespace std;

class Tree {

    // DFS and BFS are in O(V + E) time
    // in tree v = n and e = n - 1 so complexity is O(n)
    // we don't need to use visited array in dfs or bfs 
    // we use the fact that every node in a tree has only one parent except the root node
    // so we check if the node in the adjacency list is not the parent of the current node
public:
    int n;
    vector<vector<int>> adj;
    Tree(int n) {
        this->n = n;
        adj.resize(n);
    }
    void addEdge(int u, int v, bool bidir = true) {
        // 0 based indexing
        // O(1)
        // we suppose that the the tree is undirected by default, you can change it by passing false in the third argument
        adj[u].push_back(v);
        if (bidir) adj[v].push_back(u);
    }
    void bfs(int src) {
        // O(n)

        queue<pair<int, int>> q;// {node,parent}
        q.push({ src,-1 });// -1 is the parent of the root node
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int node = p.first;
            int parent = p.second;
            cout << node << " ";
            for (auto child : adj[node]) {
                if (child != parent) {
                    q.push({ child,node });
                }
            }
        }

    }
    void dfs(int src, int parent) {
        // O(n)
        cout << src << " ";
        for (auto child : adj[src]) {
            if (child != parent) {
                dfs(child, src);
            }
        }
    }
    void dfs(int src) {
        // O(n)
        dfs(src, -1);
    }

    void shortestPath(int src) {
        //for every node print the minimum distance from the source node
        //BFS
        //O(n)
        //works only in unweighted graphs
        //the first time a node is visited is the shortest path to that node
        //the dist[child] = dist[parent] + 1
        vector<int> dist(n, -1);//like the visited array
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
        //print the shortest path from src to dest
        //BFS
        //O(n)
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
    int n = 6;
    Tree t(n);
    t.addEdge(0, 1);
    t.addEdge(0, 2);
    t.addEdge(1, 4);
    t.addEdge(1, 5);
    t.addEdge(2, 3);

    t.bfs(0);
    cout << "\n";
    t.dfs(0);
    cout << "\n";
    t.shortestPath(0);
    cout << "\n";
    t.shortest_path(0, 4);

}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}