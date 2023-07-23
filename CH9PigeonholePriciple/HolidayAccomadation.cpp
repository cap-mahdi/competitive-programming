#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    site: SPOJ
    problem name: HOLIDAY ACCOMADATION
    statement: read https://www.spoj.com/problems/HOLI/
    approach:
        let's have an edge between two cities if there is a road between them.
        we divide the tree into two parts by removing an edge.
        let's say the size of one part is x and the other is n-x.
        then the maximum persons that can travel between these two parts is 2*min(x,n-x).(pigonhole principle)
        because in the statement preople always take the shortest path.
        we then only mutliply it with the weight of the edge.
        we do it for all the egdes and add it to the answer.
        we can do it by dfs.
    complexity : O(n)
*/

vector<pair<int,int>> adj[100001];

int dfs(int u,int parent,int N,int &ans){
    int currentTreeSize = 1;
    for(auto p : adj[u]){
        int v = p.first;
        int w = p.second;

        if(v==parent)
            continue;
        
        int sizeChildTree = dfs(v,u,N,ans);
        ans += min(sizeChildTree,N-sizeChildTree)*w*2;//2*min(x,n-x)*w, where x is the size of the subtree and n-x is the size of the other part of the tree.
        currentTreeSize+=sizeChildTree;
    }
    return currentTreeSize;
}

void solve(int t){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        adj[i].clear();
    }
    for(int i=0;i<n-1;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int ans=0;
    dfs(1,-1,n,ans);
    cout<<"Case #"<<t<<": "<<ans<<"\n";

}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int currentTest = 1;
    while(t--){
        solve(currentTest);
        currentTest++;
    }
    return 0;
}