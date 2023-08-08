#include <bits/stdc++.h>
#define int long long int
using namespace std;



/*
    PROOF: https://www.usna.edu/Users/cs/wcbrown/courses/S17SI335/lec/l22/lec.html#:~:text=Proof%20that%20Prim's%20algorithm%20gives%20a%20minimum%20spanning%20tree&text=Theorem%3A%20If%20T%E2%80%B2%20is%20a,a%20vertex%20not%20in%20T%E2%80%B2.

    WHAT IS A SPANNING TREE?
    MST: Minimum Spanning Tree: It is a subset of the edges of a connected, edge-weighted undirected graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.
    To minimize the total weight we need to minimize the number of edges, so the perfect data structure for this is a tree (n-1 edges for n nodes)
    This is the minimum esdges that we can get in a connected graph

    Prim's Algorithm:
    It is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph.
    Local optimal choice + Global optimal solution = Greedy Algorithm
    Local optimal choice:
                -Our answer as explained above is a tree
                -Suppose we have a tree with k nodes and we want to add a new node to it
                -We have to add an edge to connect the new node to the tree
                -We have to choose the edge with minimum weight
                -So we should not choose the node and then choose the edge, we should choose the edge directly

    HOW IT WORKS?

    1- We start from an arbitrary node
    2- We add the node to the MST
    3- We add all the edges connected to this node to a priority queue if the other node is not already in the MST
    4- We pop the edge with minimum weight from the priority queue
    5- We add node from the edge to the MST
    6 repeat steps 3,4,5 until we have n-1 edges in the MST or the priority queue is empty


    Complexity: O(ElogV)
    At worst case we will push all the edges in the priority queue => O(ElogE*2) = O(ElogE)
    (push and pop operations are O(logE) )

    Suppose we have a graph with n nodes,the maximum number of edges in a graph is V*(V-1)/2
    first node: V-1 edges
    second node: V-2 edges (we can't count the edge between first and second node, it is already counted)
    ...
    last node: 0 edges
    So E = O(V^2)
    So O(ElogE) = O(V^2logV^2) = O(2V^2logV) = O(V^2logV) = O(ElogV)

    !! If it is unweighted graph then a simple DFS tree is a spanning tree
    !! If it is a disconnected graph then it will find a minimum spanning forest (a minimum spanning tree for each connected component)
    !! In this case we need to start the algorithm for every node that is not visited yet



*/

class Graph {
    int V;
    list<pair<int, int>>* l;
public:
    Graph(int V) {
        this->V = V;
        l = new  list<pair<int, int>>[V + 1];
    }

    void addEdge(int u, int v, int w) {
        l[u].push_back({ v,w });
        l[v].push_back({ u,w });
    }

    int prim_mst() {
        //It can bbe used to find the MST itself
        //return the weight of the MST
        //O(ElogV) => O(V^2logV) BE CAREFUL THIS CAN TAKE A LOT OF TIME TLE,CHECK THE CONSTRAINTS
        //we use priority queue to get the edge with minimum weight (it uses heap internally)

        //init a min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        //visited array that denotes whether a node has been included in MST or not
        bool* visited = new bool[V + 1] {false};
        int ans = 0;
        //begin
        Q.push({ 0,1 }); //weight,node
        while (!Q.empty()) {
            //pick out the edge with min weight
            auto best = Q.top();
            Q.pop();
            int to = best.second;
            int weight = best.first;
            if (visited[to]) {
                //this is important as we may have same node with different weights in the queue
                //discard the edge and continue
                continue;
            }
            //otherwise take the current edge
            ans += weight;
            visited[to] = true;
            //add the new edges in the queue
            for (auto x : l[to]) {
                if (visited[x.first] == false) {
                    Q.push({ x.second,x.first });
                }
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

    cout << g.prim_mst() << endl;

}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}