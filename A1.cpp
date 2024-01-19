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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 2;i < n;i++) {
        if (n % i != 0) continue;
        int d = n / i;
        int candidate = abs(a[0] - a[d]);
        bool ok = true;
        for (int loop = 0;loop < i - 1;loop++) {
            cout << "loop " << loop << " d " << d << endl;
            for (int index = loop;index < loop + d;index++) {
                int possible = abs(a[index] - a[index + d]);
                cout << "possible " << possible << " candidate " << candidate << endl;
                int s = min(possible, candidate);
                int l = max(possible, candidate);
                if (l % s) {
                    ok = false;
                    break;
                }
                candidate = s;
            }
            if (!ok) {
                break;
            }
        }
        if (ok) ans++;
    }
    cout << ans << "\n";

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