#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    Every graph has multiple DFS trees(it depends on the starting node)
    A backedge is an edge that connects a node to a node that is already visited and is not its parent
    If a backedge is present in a graph then it has a cycle
    !IMPORTANT
    in the below example
    3-1 and 7-4 are backedges
    1-3 and 4-7 are not backedges

*/

const int N = 1e5 + 1;
vector<int> graph[N];
vector<int> vis(N, 0);
bool cycle = false;
void dfs_and_backedges(int src, int parent) {
    // Print all the backedges and used to check if a graph has a cycle or not
    vis[src] = 1;
    for (auto child : graph[src]) {
        if (vis[child] == 0) {
            dfs_and_backedges(child, src);
        }
        else if (vis[child] == 1 && child != parent) {
            cout << "Backedge found between " << src << " and " << child << "\n";
            cycle = true;
        }
    }
}

void solve() {
    int n = 7;
    int m = 8;

    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[1].push_back(3);
    graph[3].push_back(1);

    graph[2].push_back(3);
    graph[3].push_back(2);

    graph[2].push_back(4);
    graph[4].push_back(2);

    graph[4].push_back(5);
    graph[5].push_back(4);

    graph[5].push_back(6);
    graph[6].push_back(5);

    graph[6].push_back(7);
    graph[7].push_back(6);

    graph[7].push_back(4);
    graph[4].push_back(7);

    dfs_and_backedges(1, -1);
    if (cycle) {
        cout << "Cycle is present\n";
    }
    else {
        cout << "Cycle is not present\n";
    }
}

int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}