#include <bits/stdc++.h>
#define int long long int
using namespace std;

void no() {
    cout << "NO" << "\n";
}
void yes() {
    cout << "YES" << "\n";
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int prod = 1;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        prod *= a[i];
    }
    if (2023 % prod != 0) { cout << "NO\n"; return; }
    cout << "YES\n";
    cout << 2023 / prod << " ";
    k--;
    while (k--) cout << "1 ";
    cout << "\n";


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
    }
    return 0;
}