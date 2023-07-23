#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    Problem : Friend Pairing Problem
    Given n friends, each one can remain single or can be paired up with some other friend.
    Each friend can be paired only once. Find out the total number of ways in which friends
    can remain single or can be paired up.
    Input: n = 5
    Output: 26
    Explanation: {1}, {2}, {3} : all single
                 {1}, {2,3} : 2 and 3 paired but 1 is single.
                 {1,2}, {3} : 1 and 2 are paired but 3 is single.
                 {1,3}, {2} : 1 and 3 are paired but 2 is single.
                 Note that {1,2} and {2,1} are considered same.
    
    Approach: Recursion + Memoization
    Recursive formula: f(n) = f(n-1) + (n-1)*f(n-2)
    f(n-1) if we place 1 as single
    f(n-2) if we place 1 as pair and then we have n-1 options for 1 to pair with
    Time complexity: O(n)
    Space complexity: O(n)

*/

int friendPairing(int n,int *dp){
    //base case
    if(n==0 || n==1 || n==2){
        return n;
    }
    //recursive case
    if(dp[n]!=0){
        return dp[n];
    }
    int ans = friendPairing(n-1,dp) + (n-1)*friendPairing(n-2,dp);
    return dp[n] = ans;
}

void solve(){
    int n;
    cin>>n;
    int dp[n+1] = {0};
    cout<<friendPairing(n,dp)<<endl;
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}