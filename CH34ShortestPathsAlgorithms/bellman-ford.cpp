#include <bits/stdc++.h>
#define int long long int
using namespace std;


/*
    Bellman Ford Algorithm: Bottom Up Approach Dynamic Programming
    - Single Source Shortest Path Algorithm
    - Works for negative edges
    - Can detect negative cycle

    Algorithm:
    1- Initialize dist[] = INT_MAX and dist[src] = 0
    2- Relax all edges V-1 times (the order of edges doesn't matter)
    Relaxation: we have u->v with weight w
    if dist[u] + w < dist[v] then dist[v] = dist[u] + w

    Why V-1 times?
    - Because the shortest path can have at most V-1 edges:
        - If it has V edges,that means there is a cycle (if there are V edges, then at least 2 vertices of the path are the same)
            case 1: if the cycle has positive weight, then this is not what we are looking for
            case 2: if the cycle has negative weight, then we can keep going through the cycle to get a shorter path so it is as if the path is - infinity
    - In the ith iteration, we find the shortest path with at most i edges.In other words, in the ith iteration the nodes that can be reached after i edges will be updated if there is a shorter path to them

    3- Check for negative cycle
    - If we can still find a shorter path after V-1 iterations, then there is a negative cycle.Because as it is mentioned above, the shortest path can have at most V-1 edges and if we can still find a shorter path after V-1 iterations, then there is a negative cycle.
    !Positive cycle won't matter because they will only increment the distance so they will be ignored


    Observation:
        If we can find an algorithm that can sort the edges based on their level compared to the source, then we can iterate through the edges only once and we can find the shortest path in O(E + ElogE) = O(ElogE) time complexity
        See the below example to understand what I mean by level

    Complexity: O(VE)

    Example
    0->1 with weight 2
    1->2 with weight 2
    0->2 with weight 3
    2->3 with weight 5
    3->4 with weight 6
    4->5 with weight -7
    3->5 with weight -10

    1st iteration:
    the nodes that will be updated are
    dist[1] = 2
    dist[2] = 3
    dist[3] = 8
    dist[4] = 14
    dist[5] = 1

    From the first iteration we get our answer,that is because the edges are in good order.

    What I meant above by sorting the edges based on their level is that we can sort the edges based on the number of edges from the source to the destination so if we apply that to the example above we will get
    0->1 with weight 2  level 1
    0->2 with weight 3  level 1
    1->2 with weight 2  level 2
    2->3 with weight 5  level 2
    3->4 with weight 6  level 3
    3->5 with weight -10 level 3
    4->5 with weight -7 level 4

    In the above example we get the result from the first time althoug level 1 is at pos 3 and level 2 is at pos 2,because the level 2 that is at pos 2 depend on level 1
    that is at pos 1,so it didn't matter here

    this is the worst order we can get :
    4->5 with weight -7 level 4
    3->4 with weight 6  level 3
    3->5 with weight -10 level 3
    2->3 with weight 5  level 2
    1->2 with weight 2  level 2
    0->1 with weight 2  level 1
    0->2 with weight 3  level 1

    If you apply the algorith on this example you will notice that at the ith iteration, the nodes that will be updated are the nodes that have level i

*/

class Graph {
    int V;
    vector<vector<int>> edges;
public:
    Graph(int V) {
        this->V = V;
    }
    void addEdge(int u, int v, int w) {
        edges.push_back({ u, v, w });
    }
    void bellmanFord(int src) {
        // O(VE) time complexity
        // used for shortest path in a graph with negative edges
        // can also be used to detect negative cycle
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        for (int i = 0; i < V - 1; i++) {
            for (int j = 0; j < edges.size(); j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                if (dist[u] <= INT_MAX - w && dist[u] + w < dist[v]) {

                    //relaxation
                    //we check if dist[u] is not INT_MAX - w because if it is then dist[u] + w will overflow
                    //we suppose that INT_MAX is the maximum distance possible
                    dist[v] = dist[u] + w;
                }
            }
        }
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                cout << "Negative cycle found";
                return;
            }
        }
        for (int i = 0; i < V; i++) {
            cout << i << " " << dist[i] << endl;
        }
    }
};

void solve() {
    Graph g(6);
    g.addEdge(0, 1, 2);
    g.addEdge(1, 2, 2);
    g.addEdge(0, 2, 3);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 6);
    g.addEdge(4, 5, -7);
    g.addEdge(3, 5, -10);

    g.bellmanFord(0);

    g.addEdge(5, 3, -11);
    g.bellmanFord(0);

}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}