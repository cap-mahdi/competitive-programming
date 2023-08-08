#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    PROOF: https://gtl.csa.iisc.ac.in/dsa/node184.html#:~:text=Theorem%3A%20Kruskal's%20algorithm%20finds%20a,number%20of%20edges%20in%20T.

    WHAT IS A SPANNING TREE?
    MST: Minimum Spanning Tree: It is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.
    To minimize the total weight we need to minimize the number of edges, so the perfect data structure for this is a tree (n-1 edges for n nodes)
    This is the minimum esdges that we can get in a connected graph


    Kruskal's Algorithm:
    It is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph.
    Local optimal choice + Global optimal solution = Greedy Algorithm
    Local optimal: after sorting the edges based on their weight, it can be proven that the edge with minimum weight is always in the MST
    (the total weight of the MST is alwways no matter how we choose the edges,but the edges that we choose are not unique)

    HOW IT WORKS?
    1- Sort all the edges based on their weight
    2- Pick the edge with minimum weight if it doesn't form a cycle with the edges that are already in the MST
    We detect the cycle using DSU (Disjoint Set Union) in O(1)

    Complexity: O(ElogE) = O(ElogV^2) = O(2ElogV) = O(ElogV)
    the sorting will takes O(ElogE)

    !! If it is unweighted graph then a simple DFS tree is a spanning tree
    !! This algorithm works also for disconnected graphs


*/



class DSU {
    int* parent;
    int* rank;
public:
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];
        //parent[i] = -1;
        //rank[i] = 1;
        for (int i = 0;i < n;i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    //Find
    int find(int i) {
        //base case
        if (parent[i] == -1) {
            return i;
        }
        //otherwise
        return parent[i] = find(parent[i]);
    }
    //Unite (union is a reserved keyword)
    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);
        if (s1 != s2) {
            //union by rank
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph {
    vector<vector<int>> edgelist;
    int V;
public:
    Graph(int V) {
        this->V = V;
    }
    void addEdge(int x, int y, int w) {
        x--;
        y--;
        //we make 0 based indexing
        edgelist.push_back({ w,x,y });
    }
    int kruksal_mst() {
        //O(ElogV)
        //With this algorithm it is easy to return the MST itself
        //returns weight of MST
        //Main Logic
        //1. Sort all the edges based upon weight
        sort(edgelist.begin(), edgelist.end());
        //Init a DSU
        DSU s(V);
        int ans = 0;
        for (auto edge : edgelist) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            //Take that edge in MST if it doesn't form a cycle
            if (s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
            }
        }
        return ans;
    }
};

void solve() {
    Graph g(9);
    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 12);
    g.addEdge(2, 3, 9);
    g.addEdge(2, 4, 8);
    g.addEdge(3, 5, 3);
    g.addEdge(4, 5, 7);
    g.addEdge(4, 6, 10);
    g.addEdge(5, 6, 3);
    g.addEdge(3, 6, 1);
    g.addEdge(4, 7, 8);
    g.addEdge(4, 8, 5);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 9);
    g.addEdge(7, 9, 2);
    g.addEdge(8, 9, 11);


    cout << g.kruksal_mst() << endl;
}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}