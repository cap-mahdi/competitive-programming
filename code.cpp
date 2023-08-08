#include <bits/stdc++.h>
#define int long long int
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    int ans[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        a.push_back({ b,i });
        sum += b;
    }
    sort(a.begin(), a.end());
    sum += n;
    int t = n;
    for (int i = 0;i < n;i++) {
        // cout << " sum " << sum << endl;
        if (i == 0)
        {
            ans[a[i].second] = sum - a[i].first * t;
            sum = sum - a[i].first * t;
        }
        else
        {
            ans[a[i].second] = sum - (a[i].first - a[i - 1].first) * t;
            sum = sum - (a[i].first - a[i - 1].first) * t;
        }
        // cout << a[i].second << " " << ans[a[i].second] << endl;
        if (i != n - 1) {
            // cout << "we will add " << a[i + 1].first << " - " << a[i].first << " * " << n - t + 1 << endl;
            sum += (n - t + 1) * (a[i + 1].first - a[i].first);
        }
        t--;

    }
    for (int anss : ans) {
        cout << anss << " ";
    }
    cout << "\n";
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
3
1 4 3

*/