#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    lowest common ancestor
    LCA using binary lifting and sparse table(explained in paper)
    This is like the 2 pointers approach but optimised we dont have to climb one by one we can climb in powers of 2
    A/precompute the depths and the parents of each node using dfs in O(nlogn) time. parent[i][j] is 2^j th parent of i (DP BOTTOM UP APPROACH)
    B/ now in lca
        1/pick the node with greater depth
        2/climb until both are at same depth (calculate the difference in depth and climb in powers of 2)
        EX: if diff is 13 then climb to 8th parent then climb to its 4th parent then climb to its 1st parent
        !NOTE: we must begin M-1 to 0
        3/For M-1 to 0 if parent of u and v are not same then climb both by 2^i
        (hardest part but it can be proved that if climb whenever parent of u and v are not same then we will reach the child of lca)
        4/return parent of u or v
*/


const int N = 1e5 + 5;
const int M = 20;//log2(N)
vector<int> gr[N];
int depth[N];
int parent[N][M];//parent[i][j] is 2^j th parent of i

void dfs(int cur, int par) {
    //O(nlogn) time complexity
    //1-based indexing
    //precompute the parents
    parent[cur][0] = par;
    for (int i = 1;i < M;i++) {
        parent[cur][i] = parent[parent[cur][i - 1]][i - 1];//2^i th parent of cur is 2^(i-1)th parent of 2^(i-1)th parent of cur
    }

    for (auto x : gr[cur]) {
        if (x != par) {
            depth[x] = depth[cur] + 1;
            dfs(x, cur);
        }
    }
}

int lca(int u, int v) {
    //O(logn) time complexity
    //1-based indexing
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    int diff = depth[u] - depth[v];
    //make both at same depth using binary lifting in O(log diff ) time
    for (int i = M - 1;i >= 0;i--) {
        if (diff & (1 << i)) {
            u = parent[u][i];
        }
    }
    //now both are at same depth
    if (u == v)return u;
    for (int i = M - 1;i >= 0;i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int LengthFromUtoV(int u, int v) {
    //O(logn) time complexity
    //1-based indexing
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    //we should subtract 2*depth[lca(u,v)] because we counted the depth of lca(u,v) twice
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

    cout << LengthFromUtoV(10, 11) << endl;




}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}