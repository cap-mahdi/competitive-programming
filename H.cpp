#include <bits/stdc++.h>
#define int long long int
using namespace std;

void no() {
    cout << "NO" << "\n";
}
void yes() {
    cout << "YES" << "\n";
}
string s, t;
int b[1005];

void kmpProcess() {
    int i = 0, j = -1; b[0] = -1;
    int m = (int)t.length();
    while (i < m) {
        while (j >= 0 && t[i] != t[j]) j = b[j];
        j++; i++; b[i] = j;
    }
}

int kmpSearch(string compareto) {
    int ans = 0;
    int i = 0, j = 0;
    int n = compareto.size(), m = t.size();
    while (i < n) {
        while (j >= 0 && compareto[i] != t[j]) j = b[j];
        i++; j++;
        if (j == m) {
            ans++;
        }
    }
    return ans;
}

void solve() {
    int n, m, q; cin >> n >> m >> q;
    cin >> s >> t;
    kmpProcess();
    // for (auto p : ans) cout << p << " ";
    // cout << endl;
    int len = s.size();
    vector<int> dp(len, 0);
    int curr = 0;
    for (int i = 0;i < len;i++) {
        if (s.substr(i, t.size()) == t) {
            curr++;
        }
        dp[i] = curr;
    }
    int maxx = dp[len - 1];
    for (int i = 0;i < len;i++) {
        dp[i] = maxx - dp[i];
    }

    int change = maxx;
    for (int i = 1;i < len;i++) {
        if (dp[i] != change) {
            change = dp[i];
            dp[i] = dp[i - 1];
        }

        // cout << "dp[i ]" << i << " " << dp[i] << "\n";
    }
    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        if (r - l + 1 < t.size()) { cout << 0 << "\n";continue; }
        int ans = kmpSearch(s.substr(l, r - l + 1));
        cout << ans << endl;
        // cout << "l: " << l << " r; " << r << endl;
        // int index = lower_bound(ans.begin(), ans.end(), l) - ans.begin();
        // int fin = lower_bound(ans.begin(), ans.end(), max(r - t.size() + 1, l)) - ans.begin();
        // cout << "aa " << max(r - t.size() + 1, l) << "\n";
        // cout << index << " " << fin << endl;
        // cout << "after: " << endl;
        // if (fin == ans.size()) fin--;
        // else if (fin != ans.size() && ans[fin] > r) fin--;
        // cout << index << " " << fin << endl;
        // cout << fin - index + 1 << endl;
        // cout << fin - index << "\n";
        // cout << dp[l] - dp[max(r - t.size() + 2, l)] << "\n";



        // if (r + 1 < s.size())
        //     cout << dp[l] - dp[r + 1] << "\n";
        // else
        //     cout << dp[l] << "\n";



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