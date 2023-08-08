#include <bits/stdc++.h>
#define int long long int
using namespace std;


/*
    Find LCA of two nodes in a tree using 2 pointers approach
    A/precompute the depths and the parents of each node using dfs in O(n) time
    B/
        1/pick the node with greater depth
        2/climb until both are at same depth
        3/climb until both are same
    */

const int N = 1e5 + 5;
vector<int> gr[N];
int depth[N];
int parent[N];

void dfs(int cur, int par) {
    //1-based indexing
    parent[cur] = par;
    for (auto x : gr[cur]) {
        if (x != par) {
            depth[x] = depth[cur] + 1;
            dfs(x, cur);
        }
    }
}

int lca(int u, int v) {
    //O(n) time complexity
    //the brute force approach (2 pointers)
    // make u with greater depth
    //1-based indexing
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    int diff = depth[u] - depth[v];
    // make both at same depth
    while (diff--) {
        u = parent[u];
    }
    //climb until both are same
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }
    return u;
}

void solve() {
    int n = 12;

    gr[1].push_back(2);
    gr[2].push_back(1);

    gr[1].push_back(3);
    gr[3].push_back(1);

    gr[2].push_back(4);
    gr[4].push_back(2);

    gr[2].push_back(5);
    gr[5].push_back(2);

    gr[2].push_back(6);
    gr[6].push_back(2);

    gr[5].push_back(8);
    gr[8].push_back(5);

    gr[8].push_back(9);
    gr[9].push_back(8);

    gr[8].push_back(11);
    gr[11].push_back(8);

    gr[4].push_back(10);
    gr[10].push_back(4);

    gr[3].push_back(7);
    gr[7].push_back(3);

    gr[7].push_back(12);
    gr[12].push_back(7);

    dfs(1, 0);//0 as a virtual parent of root

    cout << lca(10, 11) << endl;
    cout << lca(8, 11) << endl;
    cout << lca(12, 12) << endl;
    cout << lca(1, 1) << endl;
    cout << lca(6, 12) << endl;


}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}