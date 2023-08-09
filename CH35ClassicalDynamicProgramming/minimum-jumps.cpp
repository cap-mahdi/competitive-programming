#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*
    Problem: Given an array of integers, where each element represents the maximum number of steps that can be jumped from that position.
    Find the minimum number of jumps to reach the end of the array (starting from the first element).
    If an element is 0, then cannot move through that element.

    example : arr = {3,4,2,1,2,3,7 ,1,1,1,2,5}
    ans = 4
    3 -> 4 -> 2 -> 7 -> 5

    This problem has:
        - optimal substructure: dp[i] = min(dp[i+1], dp[i+2], ... , dp[i+arr[i]]) + 1 //from i we can jump to i+1, i+2, ... , i+arr[i]
        - overlapping subproblems: dp[i] is calculated multiple times
    ==> Dynamic Programming
    dp[i] : represents the minimum number of jumps to reach the end of the array starting from the ith element


    Complexity:
        - Time Complexity: O(n^2) :
            - Top Down: O(n^2)
            - Bottom Up: O(n^2)

            i = n-1 max_jumps = 0
            i = n-2 max_jumps = 1
            i = n-3 max_jumps = 2
            ...
            i = 0 max_jumps = n-1
            so total = n + (n-1) + (n-2) + ... + 1 = n*(n+1)/2 = O(n^2)

        - Space Complexity: O(n)
*/

int top_down(vector<int> arr, vector<int>& dp, int i) {
    //base case
    if (dp[i] != INT_MAX) {
        return dp[i];
    }
    //recursive case
    int max_jumps = arr[i];
    for (int jumps = 1;jumps <= max_jumps && i + jumps < arr.size();jumps++) {
        int next = i + jumps;
        dp[i] = min(dp[i], top_down(arr, dp, next) + 1);

    }
    return dp[i];
}

int bottom_up(vector<int> arr) {
    int n = arr.size();
    vector<int> dp(n, INT_MAX);
    dp[n - 1] = 0;
    for (int i = n - 2;i >= 0;i--) {
        for (int j = 1;j <= arr[i] && j + i < n;j++)
            dp[i] = min(dp[i], dp[i + j] + 1);

    }
    return dp[0];
}


void solve() {
    vector<int> arr = { 3,4,2,1,2,3,7 ,1,1,1,2,5 };
    cout << bottom_up(arr) << endl;

    vector<int> dp(arr.size(), INT_MAX);
    dp[arr.size() - 1] = 0;
    cout << top_down(arr, dp, 0) << endl;
}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}