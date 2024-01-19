#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;

void no() {
    cout << "NO" << "\n";
}
void yes() {
    cout << "YES" << "\n";
}
const int N = 8;
vector<int> rows(N);
vector<bool> taken(N, false);
vector<bool> d1(2 * N - 2, false);
vector<bool> d2(2 * N - 2, false);
void backTrack(int c, int a, int b, int& tot) {
    if (c == N) {
        // cout << "here\n";
        tot++;
        if (tot < 10)
            cout << " " << tot << "      ";
        else
            cout << tot << "      ";
        for (int i = 0;i < N;i++) {
            cout << rows[i] + 1;
            if (i != N - 1) cout << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0;i < N;i++) {
        if (i == a && b != c) continue;
        if (!taken[i] && !d1[c + i] && !d2[c - i + N - 1]) {
            taken[i] = true;
            d1[c + i] = true;
            d2[c - i + N - 1] = true;
            rows[c] = i;
            backTrack(c + 1, a, b, tot);
            taken[i] = false;
            d1[c + i] = false;
            d2[c - i + N - 1] = false;
        }
    }

}

void solve() {
    string s;
    getline(cin, s);
    cout << "SOLN       COLUMN\n";
    cout << " #      1 2 3 4 5 6 7 8\n";
    int a, b;
    cin >> a >> b;
    cout << "\n";
    int tot = 0;
    backTrack(0, a - 1, b - 1, tot);

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


    int t;
    cin >> t;


    while (t--) {
        solve();
        if (t != 0)cout << "\n";
    }
    return 0;
}