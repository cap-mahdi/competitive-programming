#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*
    Problem: Given an array of integers, find the length of the longest increasing subsequence in the array.
    example : arr = {50,4,10 ,8,30,100}
    ans = 4
    4 -> 8 -> 30 -> 100

    This problem has:
        - optimal substructure: dp[i] = max(dp[i], dp[j]+1) //for all j < i and arr[j] < arr[i]
        - overlapping subproblems: dp[i] is calculated multiple times
    ==> Dynamic Programming
    dp[i] : represents the length of the longest increasing subsequence starting from the ith element
    (dp[i] can represent the length of the longest increasing subsequence ending at the ith element depending on from where you start your loop,see below to understand)

    Complexity:
        - Time Complexity: O(n^2) :
            - Top Down: O(n^2)
            - Bottom Up: O(n^2)

            i = n-2 we iterate 1 time
            i = n-3 we iterate 2 times
            ...
            i = 0 we iterate n-1 times
            so total = 1 + 2 + ... + n-1 = n*(n-1)/2 = O(n^2)

        - Space Complexity: O(n)

*/


int bottom_up(vector<int> arr) {
    int  n = arr.size();
    vector<int> dp(n, 1);
    int ans = 1;
    //we can start from index 1 to n-1
    //and for each index we can go from 0 to i-1 and check if arr[i] > arr[j] then dp[i] = max(dp[i], dp[j]+1)
    // in this case dp[i] represents the length of the longest increasing subsequence ending from the ith element
    for (int i = n - 2;i >= 0;i--) {
        for (int j = i + 1;j < n;j++) {
            if (arr[i] <= arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
    }
    return ans;
}
vector<int> v;

bool compareIndexes(int i, int j) {
    return v[i] < v[j];

}



void solve() {
    vector<int> arr = { 50,4,10 ,8,30,100 };
    cout << bottom_up(arr) << endl;
}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}