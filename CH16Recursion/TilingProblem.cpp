#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    Tiling Problem
    Given a wall of size 4 x N and tiles of size (1,4) and (4,1)
    In how many ways you can build the wall?
    Input: N = 4
    Output: 2
    Explanation: We need to find out the number of ways
    in which we can fill up the 4 x N wall using the
    1 x 4 and 4 x 1 tiles.
    For N = 1 = 1
    For N = 2 = 1
    For N = 3 = 1
    For N = 4 = 2
    So, for N = 4, answer = 2.
    Time complexity: O(n)
    Space complexity: O(n)
    Approach: Recursion + Memoization
    formula: f(n) = f(n-1) + f(n-4)
    f(n-1) if we place 1x4 tile vertically
    f(n-4) if we place 4x1 tile horizontally

    Example
    Input: N = 5
    Output: 3
*/
int tilingProblem(int n,int *dp){
    //base case
    if(n<4){
        return 1;
    }
    if(n==4){
        return 2;
    }
    //recursive case
    if(dp[n]!=0){
        return dp[n];
    }
    int ans = tilingProblem(n-1,dp) + tilingProblem(n-4,dp);
    return dp[n] = ans;

}
void solve(){
    int n;
    cin>>n;
    int dp[n+1] = {0};
    cout<<tilingProblem(n,dp)<<endl;
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}