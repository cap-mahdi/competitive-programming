#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    Cycle detection using DSU
    suppose we have a graph with e edges
    we can detect cycle in O(e) time using DSU
    for each edge we union the sets in which the two vertices are present,if they are already in same set then cycle is present
    for the union and find operations we use union by rank and path compression optimizations explained below in findSet and union_set functions
    for further explanation: https://www.geeksforgeeks.org/union-by-rank-and-path-compression-in-union-find-algorithm/

    IMPORTANT: this method works only for UNDIRECTED graphs
    why it works for undirected graph?
    we each set of vertices is a connected component in the graph
    each pair of node in a set is connected by a single path
    so if we union the sets in which the two vertices of an edge are present then we are actually adding
    these 2 paths will create a cycle
    Example:
    set = {1,2,3,4}
    (1,3) there is only one path (1-2-3 for example) (we union 1 and 2 then 2 and 3 )
    if we union 5 and 2 then we are adding a direct path between 5 and 2 (5-2) and a path between 5  and with every node in set
    set = {1,2,3,4,5}
    if we union 3 and 1 then we are adding a direct path between 3 and 1 (1-3)
    so at the end we have a cycle 1-2-3-1

    why it doesn't work for directed graph?
    because
    1- we change the direction with our our optimization:union by rank and path compression
    even without optimization it doesn't work because we link the leader of 2 nodes in an arbitrary way
    2- we see a set as all the nodes in it are connected by a single path which is not the case in directed graph
*/

class Graph {
    int V;
    list<pair<int, int>> l;
public:
    Graph(int V) {
        this->V = V;
    }
    void addEdge(int u, int v) {
        l.push_back({ u,v });
    }
    int findSet(int i, int parent[]) {
        //return the root of the set in which element i is present
        //O(height of tree)
        //O(logV) as average 
        //it can be O(V) in worst case (chain of V nodes)
        if (parent[i] == -1) {
            return i;
        }
        //path compression optimization:all nodes in path will point directly to parent
        return parent[i] = findSet(parent[i], parent);
    }
    bool union_set(int x, int y, int parent[], int rank[]) {
        //combine the sets in which x and y are present
        //return false if x and y are in same set
        //O(1): it needs a proof 
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);
        if (s1 != s2) {
            //union by rank optimization:attach smaller rank tree under root of higher rank tree
            //rank of set is number of nodes in that set
            //we make that choice so that height of tree is minimized
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
            return true;
        }
        return false;
    }
    bool contains_cycle() {
        //DSU logic to check if UNDIRECTED  graph contains cycle or not
        //O(Edges)
        int* parent = new int[V];
        int* rank = new int[V];
        for (int i = 0;i < V;i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
        for (auto edge : l) {
            int i = edge.first;
            int j = edge.second;
            if (!union_set(i, j, parent, rank)) {
                return true;
            }
        }
        delete[] parent;
        delete[] rank;
        return false;
    }
};

void solve() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 0);
    if (g.contains_cycle()) {
        cout << "Cycle is present";
    }
    else {
        cout << "Cycle is not present";
    }
}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}