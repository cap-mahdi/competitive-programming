#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    Problem: Given a ladder of size n, and a person has the ability to climb k steps at a time.
    Find the number of ways the person can reach the top of the ladder.

    example : n = 4, k = 3
    ans = 7
    1 1 1 1
    1 1 2
    1 2 1
    2 1 1
    1 3
    3 1
    2 2



    This problem has:
        - optimal substructure: dp[i] = dp[i-1] + dp[i-2] + ... + dp[i-k]
        - overlapping subproblems: dp[i] is calculated multiple times
    ==> Dynamic Programming
    dp[i] : represents the number of ways to reach the ith step

    Approaches:
        - Recursion:
            - Base Case: n < 0, return 0 | n == 0, return 1 0 is like the ground
            - Recursive Case: for i = 1 to k, ans += top_down(n - i, k)
            - Time Complexity: O(k^n)
            - Space Complexity: O(n)

            - Bad Approach because of exponential time complexity and overlapping subproblems
        - Top Down DP: (recursion + memoization)
            - Initialize dp[n] = 0 and dp[0] = 1 0 is like the ground
            - Base Case: n < 0, return 0
            - Check if dp[n] is already calculated, if yes return dp[n]
            - Recursive Case: for i = 1 to k, ans += top_down(n - i, k)
            - Time Complexity: O(n*k)
            - Space Complexity: O(n)

        - Bottom Up DP: iterative approach
            - Initialize dp[0] = 1 0 is like the ground
            -  for i = 1 to n, for j = 1 to k, dp[i] += dp[i - j] if i - j >= 0
            - Time Complexity: O(n*k)
            - Space Complexity: O(n)
        - Bottom Up Optimised DP: iterative approach
            - Initialize dp[0] = dp[1] = 1 0 is like the ground
            -  for i = 2 to n, if i <= k, dp[i] = 2 * dp[i - 1]
            -  else dp[i] = 2 * dp[i - 1] - dp[i - k - 1]
            - Time Complexity: O(n)
            - Space Complexity: O(n)

        Explanation of Bottom Up optimised:
        With a simple obervation we can compute dp[i] in O(1) instead of O(k)

        for i <= k
            we know that dp[i] = dp[i - 1] + dp[i - 2] + ... + dp[0]
            or dp[i-1]= dp[i-2] + dp[i - 3] + ... + dp[0]
            so dp[i] = 2 * dp[i - 1]
        for i > k
            we know that dp[i] = dp[i - 1] + dp[i - 2] + ... + dp[i - k ]
            or dp[i-1]= dp[i-2] + dp[i - 3] + ... + dp[i - k - 1]
            so dp[i] = 2 * dp[i - 1] - dp[i - k - 1]


*/

int recrusive(int n, int k) {
    //O(k^n)
    //Base Case
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }
    //Recursive Case
    int ans = 0;
    for (int jump = 1;jump <= k;jump++) {
        ans += recrusive(n - jump, k);
    }
    return ans;
}

int  top_down(int n, int k, vector<int>& dp) {
    //O(n*k)
    //Base Case
    if (n < 0)
        return 0;

    if (dp[n] != 0) {
        return dp[n];
    }
    //Recursive Case
    int ans = 0;
    for (int jump = 1;jump <= k;jump++) {
        ans += top_down(n - jump, k, dp);
    }
    return dp[n] = ans;
}

int bottom_up(int n, int k) {
    //iterative approach
    //O(n*k)
    vector<int> dp(n + 1, 0);
    dp[0] = 1;//base case become an assignment
    for (int i = 1;i <= n;i++) {
        for (int jump = 1;jump <= k;jump++) {
            if (i - jump >= 0) {
                dp[i] += dp[i - jump];
            }
        }
    }
    return dp[n];
}

int bottom_up_optimised(int n, int k) {
    //iterative approach
    //O(n)
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1; //base case become an assignment
    for (int i = 2;i <= n;i++) {
        if (i <= k) {
            dp[i] = 2 * dp[i - 1];
        }
        else
        {
            dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
        }
    }

    return dp[n];
}

void solve() {
    int n, k;
    cin >> n >> k;

    //recursive approach
    cout << recrusive(n, k) << "\n";

    //top down approach
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    cout << top_down(n, k, dp) << "\n";

    //bottom up approach
    cout << bottom_up(n, k) << "\n";

    //bottom up optimised approach
    cout << bottom_up_optimised(n, k) << "\n";
}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}