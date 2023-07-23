#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    statement: print all the valid brackets for n pairs of brackets
    input: 3
    output: ((())),(()()),(())(),()(()),()()()

    approach: backtracking
    for each index we have two choices either we can put an opening bracket or we can put a closing bracket
    we can put an opening bracket if the number of opening brackets is less than n
    we can put a closing bracket if the number of closing brackets is less than the number of opening brackets

    time complexity: O(4^n) // there are 4^n possible strings of length 2*n
    space complexity: O(n)

*/


void generateBrackets(string output,int open,int close,int n){
    //base case
    if(open==n && close==n){
        cout<<output<<"\n";
        return;
    }

    //recursive case
    if(open<n){
        generateBrackets(output+"(",open+1,close,n);
    }
    if(close<open){
        generateBrackets(output+")",open,close+1,n);
    }
}

void solve(){
    int n;
    cin>>n;
    generateBrackets("",0,0,n);
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}