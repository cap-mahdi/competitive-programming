#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*

    problem statement:- given n, find the number of unique BSTs that can be formed using n nodes 
    approach:- we will use the concept of catalan numbers to solve this problem.
    catalan numbers are a sequence of natural numbers that occur in various counting problems.
    catalan numbers can be computed using the formula Cn = (2nCn)/(n+1)
    catalan numbers can also be computed using the formula Cn = (2n)!/(n!*(n+1)!)
    catalan numbers can also be computed using the formula Cn = (4n-2)/(n+1) * Cn-1
    catalan numbers can also be computed using the formula Cn = summation of C(i-1)*C(n-i) for i from 1 to n


    implementation of catalan numbers using:
        -> recursion time complexity:- O(2^n) space complexity:- O(n)
        -> top down dp time complexity:- O(n^2) space complexity:- O(n)
        -> bottom up dp time complexity:- O(n^2) space complexity:- O(n)


*/
int countBST(int n)
{
    if (n == 0 || n == 1)
        return 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += countBST(i - 1) * countBST(n - i);
    }
    return ans;
}
int countBSTtopDown(int n, int *dp)
{
    if (n == 0 || n == 1)
        return dp[n] = 1;
    if (dp[n] != 0)
        return dp[n];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += countBSTtopDown(i - 1, dp) * countBSTtopDown(n - i, dp);
    }
    return dp[n] = ans;
}

int countBSTBottomUp(int n, int *dp)
{
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}

void solve()
{
    int n;
    cin >> n;
    cout << countBST(n) <<endl;

    int d[n+1] = {0};
    cout << countBSTtopDown(n,d) <<endl;

    int d2[n+1] = {0};
    cout << countBSTBottomUp(n,d2) <<endl;
}
int32_t main()
{
    // fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}