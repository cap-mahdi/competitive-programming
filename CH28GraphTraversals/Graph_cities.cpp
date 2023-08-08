#include <bits/stdc++.h>
#define int long long int
using namespace std;

class Node {
public:
    string name;
    vector<Node*> children;
    Node(string name) {
        this->name = name;
    }
    Node() {}
};

class Graph {

    // You should definetely use node* and not node because
    // (it can work with node(add default constructor)) but it is not recommended)
   // 1- It is easier to manipulate pointers than objects, you can pass them by reference and change them
   // 2- You can use unordered_map<Node*, bool> vis instead of unordered_map<string, bool> vis because node* is unique and string is not
   // 3- It is better for memory management



// IMPORTANT
//  when working with node ,use unordered_map<Node*,type of value you want to store>
//  ex:
//  unordered_map<Node*, bool> vis;
//     unordered_map<Node*, int> dist;
//     unordered_map<Node*, Node*> parent;

public:
    unordered_map<string, Node*> mp;
    Graph(vector<string> cities) {
        for (auto city : cities) {
            mp[city] = new Node(city);
        }
    }
    void addEdge(string u, string v, bool bidir = true) {
        mp[u]->children.push_back(mp[v]);
        if (bidir) mp[v]->children.push_back(mp[u]);
    }
    void print() {
        for (auto node : mp) {
            cout << node.first << " -> ";
            for (auto child : node.second->children) {
                cout << child->name << " ";
            }
            cout << "\n";
        }
    }
    void bfs(string src) {
        // O(V + E)
        queue<Node*> q;
        unordered_map<Node*, bool> vis;
        q.push(mp[src]);
        vis[mp[src]] = true;
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            cout << node->name << " ";
            for (auto child : node->children) {
                if (!vis[child]) {
                    q.push(child);
                    vis[child] = true;
                }
            }
        }
    }
    void dfs(string src) {
        // O(V + E)
        unordered_map<Node*, bool> vis;
        dfs(mp[src], vis);
    }
    void dfs(Node* src, unordered_map<Node*, bool>& vis) {
        // O(V + E)
        vis[src] = true;
        cout << src->name << " ";
        for (auto child : src->children) {
            if (!vis[child]) {
                dfs(child, vis);
            }
        }
    }
    void shortest_path(string src) {
        // O(V + E)
        unordered_map<Node*, bool> vis;
        unordered_map<Node*, int> dist;
        queue<Node*> q;
        q.push(mp[src]);
        vis[mp[src]] = true;
        dist[mp[src]] = 0;
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            for (auto child : node->children) {
                if (!vis[child]) {
                    q.push(child);
                    vis[child] = true;
                    dist[child] = dist[node] + 1;

                }
            }
        }
        for (auto node : dist) {
            cout << node.first->name << " " << node.second << "\n";
        }
    }
    void shortest_path(string src, string dest) {
        // O(V + E)
        unordered_map<Node*, bool> vis;
        unordered_map<Node*, int> dist;
        unordered_map<Node*, Node*> parent;
        queue<Node*> q;
        q.push(mp[src]);
        vis[mp[src]] = true;
        dist[mp[src]] = 0;
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();
            for (auto child : node->children) {
                if (!vis[child]) {
                    q.push(child);
                    vis[child] = true;
                    dist[child] = dist[node] + 1;
                    parent[child] = node;
                }
            }
        }
        while (dest != src) {
            cout << dest << " ";
            dest = parent[mp[dest]]->name;
        }
        cout << src << "\n";
    }
};

void solve() {
    vector<string> cities = { "Delhi", "Mumbai", "Kolkata", "Chennai", "Bangalore" };
    Graph g(cities);
    g.addEdge("Delhi", "Mumbai");
    g.addEdge("Delhi", "Kolkata");
    g.addEdge("Delhi", "Chennai");
    g.addEdge("Delhi", "Bangalore");
    g.addEdge("Mumbai", "Kolkata");
    g.addEdge("Mumbai", "Chennai");
    g.addEdge("Mumbai", "Bangalore");
    g.addEdge("Kolkata", "Chennai");
    g.addEdge("Kolkata", "Bangalore");
    g.addEdge("Chennai", "Bangalore");
    g.print();
    g.bfs("Delhi");
    cout << "\n";
    g.dfs("Delhi");
    cout << "\n";
    g.shortest_path("Delhi");
    cout << "\n";
    g.shortest_path("Delhi", "Bangalore");
}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}