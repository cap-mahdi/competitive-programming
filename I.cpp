#include <bits/stdc++.h>
#define int long long int
using namespace std;

void no() {
    cout << "NO" << "\n";
}
void yes() {
    cout << "YES" << "\n";
}

void output(vector<int> a) {
    for (int nbr : a) {
        cout << nbr << " ";
    }
    cout << endl;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> friends(n);
    vector<int> prices(m);
    vector<int> beauties(m);
    for (int i = 0;i < n;i++) {
        cin >> friends[i];
    }
    for (int i = 0;i < m;i++) {
        cin >> prices[i];
    }
    for (int i = 0;i < m;i++) {
        cin >> beauties[i];
    }
    vector<vector<int>> dp[m + 1];



    dp[0].push_back({});
    dp[0][0].push_back(0);
    for (int i = 1;i <= n;i++) {
        dp[0][0].push_back(friends[i - 1]);
    }

    for (int i = 1;i <= m;i++) {
        // cout << "here" << endl;
        // cout << i << endl;
        // cout << dp[i - 1].size() << endl;
        for (int k = 0;k < dp[i - 1].size();k++) {
            auto pos = dp[i - 1][k];
            dp[i].push_back(pos);
            for (int f = 1;f <= n;f++) {
                if (pos[f] >= prices[i - 1]) {
                    vector<int> loc_pos = { pos[0] + beauties[i - 1] };
                    for (int frien = 1;frien <= n;frien++) {
                        if (frien != f)
                            loc_pos.push_back(pos[frien]);
                        else
                            loc_pos.push_back(pos[f] - prices[i - 1]);
                    }
                    dp[i].push_back(loc_pos);
                }
            }
        }
    }
    // cout << "here" << endl;
    int ans = 0;
    for (int i = 0;i <= m;i++) {
        // cout << "i " << i << endl;
        for (int k = 0;k < dp[i].size();k++) {
            cout << "k " << k << endl;
            auto pos = dp[i][k];
            bool allFalse = true;
            for (int i = 1;i <= n;i++) {
                if (pos[i] != 0)
                {
                    allFalse = false;
                    break;
                }
            }
            if (allFalse) {
                // cout << "here" << endl;
                ans = max(ans, pos[0]);
            }
        }
    }
    cout << ans << "\n";




}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);


    solve();
    return 0;
}