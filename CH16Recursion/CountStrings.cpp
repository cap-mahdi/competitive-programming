#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    Problem: Count the number of binary strings of length n, which have no consecutive ones
    Input: n = 3
    Output: 5
    Explanation: 5 strings are (000, 001, 010, 100, 101)
    Approach: Recursion + Memoization
    Recursive formula: f(n) = f(n-1) + f(n-2)
    f(n-1) if we place 0 as the first bit
    f(n-2) if we place 10 as the first two bits

    Time complexity: O(n)
    Space complexity: O(n)

    !!with fast exponentiation we can solve this problem in O(logn) time !!
*/

int countString(int n,int * dp){
    //base case
    if(n==0){
        return 1;
    }
    if(n==1){
        return 2;
    }
    //recursive case
    if(dp[n]!=0){
        return dp[n];
    }
    int ans = countString(n-1,dp) + countString(n-2,dp);
    return dp[n] = ans;
}

void solve(){
    int  n;
    cin>>n;
    int dp[n+1] = {0};
    cout<<countString(n,dp)<<endl;
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}