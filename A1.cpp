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

const int N = 1e6 + 5;
vector<int> S(N, 0);
vector<int> B(N, INT_MAX);
void sieve() {
    S[0] = S[1] = 1;
    for (int i = 2;i < N;i++) {
        if (S[i] != 0) continue;
        for (int j = i;j < N;j += i) {
            S[j] = i;
        }
    }
}
void best() {
    for (int i = 2;i < N;i++) {
        int loc = i;
        for (int j = S[i];j > 1;j = j / S[j]) {
            loc = min(loc, i / j + 2 * j);
        }
        B[i] = loc;
    }
    B[1] = 1;

}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
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

    sieve();
    best();
    for (int i = 1;i < 20;i++) {
        cout << B[i];
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}