#include <bits/stdc++.h>
#define int long long int
using namespace std;

void solve() {
    int n;
    cin >> n;
    int cnt[n];
    memset(cnt, 0, n);
    for (int i = 0;i < n;i++) {
        cnt[i] = 0;
        // ans = max(ans, cnt[i]);
    }
    // for (int i = 0;i < n;i++) {
    //     cout << cnt[i] << " ";
    // }
    // cout << endl;
    int temp = n;
    while (n--) {
        int b;
        cin >> b;
        int p = b;
        while (p <= temp) {
            cnt[p - 1]++;
            p += b;
        }
    }
    int ans = cnt[0];
    for (int i = 1;i < temp;i++) {
        ans = max(ans, cnt[i]);
    }
    cout << ans << "\n";
}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
/*
1
5
1 2 3 4 5
*/