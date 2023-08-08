#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*
    for the union and find operations we use union by rank and path compression optimizations explained below in findSet and union_set functions
    for further explanation: https://www.geeksforgeeks.org/union-by-rank-and-path-compression-in-union-find-algorithm/
*/
class DSU {
    //known as disjoint set union data structure or union find data structure
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
    int findSet(int i) {
        //return the root of the set in which element i is present
        //O(height of tree)
        //O(logV) as average 
        //it can be O(V) in worst case (chain of V nodes)
        if (parent[i] == -1) {
            return i;
        }
        //path compression optimization:all nodes in path will point directly to parent
        return parent[i] = findSet(parent[i]);
    }
    void union_set(int x, int y) {
        //combine the sets in which x and y are present
        //O(1): it needs a proof 
        int s1 = findSet(x);
        int s2 = findSet(y);
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
        }
    }
};


void solve() {
    DSU g(5);
    g.union_set(0, 1);
    g.union_set(2, 3);
    g.union_set(0, 4);
    if (g.findSet(1) == g.findSet(4)) {
        cout << "Same component" << endl;
    }
    else {
        cout << "Different component" << endl;
    }

}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}