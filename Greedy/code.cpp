#include <bits/stdc++.h>
#define int long long int
using namespace std;

void no() {
    cout << "NO" << "\n";
}
void yes() {
    cout << "YES" << "\n";
}
vector<vector<int>> dp(100, vector<int>(100, 0));

int drop(int row, int col, vector<vector<int>>& grid) {
    cout << "row " << row << " col " << col << endl;
    if (row >= grid.size()) return col + 1;
    cout << "here" << endl;
    if (dp[row][col] != 0) return dp[row][col];
    if (col == 0 && grid[row][col] == -1) return dp[row][col] = -1;
    if (col == grid[0].size() - 1 && grid[row][col] == 1) return dp[row][col] = -1;
    if (grid[row][col] == -1 && grid[row][col - 1] == -1) return dp[row][col] = drop(row + 1, col - 1, grid);
    if (grid[row][col] == 1 && grid[row][col + 1] == -1) return dp[row][col] = drop(row + 1, col + 1, grid);
    return dp[row][col] = -1;
}
vector<int> findBall(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> ans;
    for (int i = 0;i < m;i++) {
        cout << " i " << i << endl;

        ans[i] = drop(0, i, grid);
    }
    return ans;
}
void solve() {
    vector<vector<int>> grid = { {1, 1, 1, -1, -1}, {1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1}, {1, 1, 1, 1, -1}, {-1, -1, -1, -1, -1} };
    vector<int> ans = findBall(grid);
    for (int a : ans) {
        cout << a << " ";
    }
}

int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif


    solve();
    return 0;
}