#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*
    site: Codechef problem name: DIVSUB
    statement: Given an array of n integers, find a subarray whose sum is divisible by n.
    Approach:
        1. Calculate the cumulative sum of the array.
        2. If the cumulative sum is divisible by n, then we are done.
        3. If not, then we have to find two indices i and j such that cum[i]%n = cum[j]%n.
        4. If we find such indices, then the subarray between i and j will be our answer.
    such subarray exists because of the pigeonhole principle.
    If we have n holes and n+1 pigeons, then there will be atleast one hole with two pigeons.
    in this example there are two cases 
    1. if 0 is present in the cum array then we are done.
    2. if 0 is not present then we have n-1(possbilites of cum[i]%n) and n numbers.so there will be atleast 2 numbers with same remainder.
complexity: O(n)
*/

void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int cum[n],visited[n];
    memset(visited,-1,sizeof(visited));
    memset(cum,0,sizeof(cum) );
    for(int i=0;i<n;i++){
        if(i==0){
            cum[i]=a[i]%n;
        }else{
            cum[i]= (cum[i-1]+a[i]%n)%n;
        }
        if(cum[i]==0){
            cout << i+1 << "\n";
            for(int j=1;j<=i+1;j++){
                cout<<j;
                if(j<=i){
                    cout<<" ";
                }
            }
            cout<<"\n";
            return;
        }else if (visited[cum[i]]==-1){
            visited[cum[i]]=i+1;
        }else{
            cout << i-visited[cum[i]]+1 << "\n";
            for(int j=visited[cum[i]]+1;j<=i+1;j++){
                cout<<j;
                if(j<=i){
                    cout<<" ";
                }
            }
            cout<<"\n";
            return;
        }
    }
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}