#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    statement: print all the subsets of a string
    input: abc
    output: "",a,b,c,ab,ac,bc,abc
    approach: backtracking
    for each character we have two choices either we can include it or we can exclude it
    we first exclude it and find all the subsets of the remaining string
    then we include it and find all the subsets of the remaining string

    time complexity: O(2^n)
    space complexity: O(n)

*/

void subsets(string s,string output,int i,int n){
    //base case
    if(i==n){
        cout<<output<<"\n";
        return;
    }

    //recursive case
    subsets(s,output,i+1,n);
    output.push_back(s[i]);
    subsets(s,output,i+1,n);
}




void solve(){
    string s,output;
    cin>>s;
    subsets(s,output,0,s.size());
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}