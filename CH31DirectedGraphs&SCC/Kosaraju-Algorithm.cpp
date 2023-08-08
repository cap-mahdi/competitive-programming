#include <bits/stdc++.h>
#define int long long int
using namespace std;


const int N = 1e5 + 1;
vector<int> graph[N], revGraph[N];
int vis[N];
vector<int> topOrder;
int n, m;

vector<int> component[N];
int comp = 0;
vector <int> belongToComp(N);

void dfs_top(int curr) {
    vis[curr] = 1;
    for (auto x : graph[curr]) {
        if (!vis[x]) {
            dfs_top(x);
        }
    }
    topOrder.push_back(curr);
}

void toplogicalSort() {
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs_top(i);
        }
    }
    reverse(topOrder.begin(), topOrder.end());
}

void dfs_comp(int curr, int comp) {
    belongToComp[curr] = comp + 1;//the current node belongs to comp component
    component[comp + 1].push_back(curr);//pushing the current node in the comp component
    vis[curr] = 1;
    for (auto x : revGraph[curr]) {
        if (!vis[x]) {
            dfs_comp(x, comp);
        }
    }
}

void determine_components() {
    //Kosaraju's Algorithm:used to find  strongly connected components in a graph
    //1-based indexing
    //O(V+E)
    //When reading the graph, we read the edges in reverse order and store them in a reverse graph.
    toplogicalSort();
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        int v = topOrder[i];
        if (!vis[v]) {
            dfs_comp(v, comp);
            comp++;//each time we find a node that is not visited that means we have found a new component(if it was part of SSc it would have been visited)
        }
    }
    cout << "The number of components are: " << comp - 1 << endl;
    for (int i = 1; i < comp; i++) {
        cout << "Component " << i << " : ";
        for (auto x : component[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << " belongs to component " << belongToComp[i] << endl;
    }
}

void solve() {
    n = 12;
    graph[1].push_back(2);
    graph[2].push_back(3);
    graph[3].push_back(1);

    graph[4].push_back(2);

    graph[4].push_back(5);
    graph[5].push_back(6);
    graph[6].push_back(4);

    graph[7].push_back(3);

    graph[7].push_back(8);
    graph[8].push_back(9);
    graph[9].push_back(7);

    graph[3].push_back(10);

    graph[10].push_back(11);
    graph[11].push_back(12);
    graph[12].push_back(10);

    revGraph[2].push_back(1);
    revGraph[3].push_back(2);
    revGraph[1].push_back(3);

    revGraph[2].push_back(4);

    revGraph[5].push_back(4);
    revGraph[6].push_back(5);
    revGraph[4].push_back(6);

    revGraph[3].push_back(7);

    revGraph[8].push_back(7);
    revGraph[9].push_back(8);
    revGraph[7].push_back(9);

    revGraph[10].push_back(3);

    revGraph[11].push_back(10);
    revGraph[12].push_back(11);
    revGraph[10].push_back(12);

    determine_components();


}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}