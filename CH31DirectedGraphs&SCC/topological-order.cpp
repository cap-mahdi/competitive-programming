#include <bits/stdc++.h>
#define int long long int
using namespace std;

// topological sort is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering.
// it is like ordering tasks in the right order

const int N = 1e5 + 1;
vector<int> graph[N];
vector<int> vis(N, 0);
vector<int> topOrder;
int n, m;

void dfs(int curr) {
    vis[curr] = 1;
    for (auto x : graph[curr]) {
        if (!vis[x]) {
            dfs(x);
        }
    }
    //after visiting all the children of curr node(those nodes which are dependent on curr node),we can push curr node in topOrder
    //after we will reverse the topOrder vector to get the correct answer
    topOrder.push_back(curr);
}

void toplogicalSort() {
    //The topological order will be on topOrder
    //1-based indexing
    //O(V+E)
    //works only for DAG(Directed Acyclic Graph)
    //it won't throw error if graph is not DAG but it will not give correct answer
    for (int i = 1; i <= n; i++) {
        //if the node is not visited then we will call dfs on that node
        //if it is not visited that means that node is not dependent on any other node that has been visited
        //and some of the nodes that are dependent on that node has been visited
        if (!vis[i]) {
            dfs(i);
        }
    }
    reverse(topOrder.begin(), topOrder.end());
    for (auto x : topOrder) {
        cout << x << " ";
    }
}
void solve() {
    n = 5, m = 6;

    graph[1].push_back(2);
    graph[1].push_back(5);
    graph[2].push_back(4);
    graph[2].push_back(5);
    graph[3].push_back(1);
    graph[3].push_back(2);

    toplogicalSort();
}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}