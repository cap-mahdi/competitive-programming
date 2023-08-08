#include <bits/stdc++.h>
#define int long long int
using namespace std;


/*
    Dijkstra's Algorithm:
    1. Only works for +ve weighted graph
    2. returns the shortest distance of all the nodes from the src node (Single Source Shortest Path)

    Explanation:
    1. We will use a set to store the pair of distance and node
    2. At first we will insert the src node with distance = 0
    3. At the first iteration,we will insert all neighbours of the src node with distance = wt of the edge and we delete the src node from the set
    4. At the second iteration,we will get the top of set which will be the node with minimum distance from the src node,this distance will be the shortest distance of this node from the src node because all edges are +ve,from this node we will insert
    all the neighbours of this node with distance = distance of this node from src node + wt of the edge if this distance is less than the distance of the node in the set or if the node is not present in the set
    5.we will keep on doing this until the set is empty

    Djikestra's Algorithm is a Greedy Algorithm:
    At each moment the set will contains {distance,node} pair of all the nodes that aren't finalized yet and visited,and the distance of the node will be the shortest distance of this node from the src node till now.
    The top of the set will be the node with minimum distance from the src node from all the nodes that aren't finalized yet.
    So the top most set will held the min distance from source to that node.

    Complexity:
    O(ElogV):
    At worst case we will be visiting all edges and every edge will be inserted and deleted from the set once.
    The set at worst case will contains all the nodes of the graph,so insertion and deletion will take logV time.

    Example:
    5 nodes
    0 1 1
    1 2 1
    0 2 4
    0 3 7
    3 2 2
    3 4 3

    first iteration:
    set = {0,0} : the set contains only 0,it is finalized and the only node visited till now
    we take the top of the set which is {0,0}
    we push all the neighbours of 0 in the set with distance = 0 + wt of the edge

    second iteration:
    set = {1,1},{4,2},{7,3} : the set contains all the nodes that aren't finalized yet and visited
    Is it clear that till now the shortest distance of 1 from 0 is 1,2 from 0 is 4 and 3 from 0 is 7
    The top of the set is {1,1},it is finalized, that is because any other node will have distance more than 1 from 0.(There is only positive edges)
    we take the top of the set which is {1,1}
    we push all the new neighbours of 1 in the set with distance = 1 + wt of the edge and we update the other neighbours of 1 in the set with distance = 1 + wt of the edge if this distance is less than the distance of the node in the set

    third iteration:
    set = {2,2},{7,3}
    Is it clear that till now the shortest distance of 2 from 0 is 2 and 3 from 0 is 7
    The top of the set is {2,2},it is finalized, that is because any other node will have distance more than 2 from 0.(There is only positive edges)
    we take the top of the set which is {2,2}
    we push all the neighbours of 2 in the set with distance = 2 + wt of the edge

    fourth iteration:
    ....


*/


class Graph {
    int V;
    list<pair<int, int>>* l;
public:
    Graph(int v) {
        V = v;
        l = new list<pair<int, int>>[V];
    }
    void addEdge(int u, int v, int wt, bool bidir = true) {
        l[u].push_back({ v,wt });
        if (bidir) {
            l[v].push_back({ u,wt });
        }
    }
    void printAdjList() {
        for (int i = 0;i < V;i++) {
            cout << i << "->";
            for (auto node : l[i]) {
                cout << "(" << node.first << "," << node.second << ")";
            }
            cout << endl;
        }
    }
    void dijkstra(int src) {
        // Only works for +ve weighted graph
        // returns the shortest distance of all the nodes from the src node
        //O(ElogV)
        // Data Structures
        // 1. Set
        set<pair<int, int>> s;//this set will contains the pair of distance and node
        // 2. Distance array
        vector<int> dist(V, INT_MAX);
        // 3. Insert src node with distance = 0
        dist[src] = 0;
        s.insert({ 0,src });
        while (!s.empty()) {
            // Find the pair at the front
            auto it = s.begin();
            int node = it->second;
            int distTillNow = it->first;
            s.erase(it);
            // Iterate over the neighbours of the current node
            for (auto nbrPair : l[node]) {
                int nbr = nbrPair.first;
                int currentEdge = nbrPair.second;
                if (distTillNow + currentEdge < dist[nbr]) {
                    // In the set updation of a particular is not possible
                    // we have to remove the old pair and insert the new pair to simulate updation
                    auto f = s.find({ dist[nbr],nbr });
                    if (f != s.end()) {
                        s.erase(f);
                    }
                    // Insert the new pair
                    dist[nbr] = distTillNow + currentEdge;
                    s.insert({ dist[nbr],nbr });
                }
            }
        }
        // Print the distance array
        for (int i = 0;i < V;i++) {
            cout << "Node " << i << " Dist from src " << dist[i] << endl;
        }
    }
};

void solve() {
    Graph g(5);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(0, 3, 7);
    g.addEdge(3, 2, 2);
    g.addEdge(3, 4, 3);
    g.dijkstra(0);

}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}