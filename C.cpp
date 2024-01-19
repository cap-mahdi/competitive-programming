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
    map<int, int> count;
    int m = INT_MAX;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        count[a[i]]++;
        m = min(m, a[i]);
    }
    int visit = 0;
    int last = 0;
    for (auto p : count) {
        if (visit + (n * (p.first - last)) > k) {
            break;
        }
        visit += (n * (p.first - last));
        n -= p.second;
        last = p.first;

    }
    cout << "visit" << visit << endl;
    cout << "n " << n << endl;
    cout << "last " << last << endl;
    int p = k - visit;
    int done = p % n;
    int ccurrN = n;
    // for (int i = 0;i < n;i++) {
    //     if (a[i] > last) {
    //         if (p <= 0) {
    //             cout << i + 1 << " ";
    //             ccurrN--;
    //         }
    //         p--;
    //     }
    // }
    // for (int i = 0;i < n && ccurrN != 0;i++) {
    //     if (a[i] > last) {
    //         cout << i + 1 << " ";

    //     }
    // }
    vector<pair<int, int>> rest;
    for (int i = 0;i < a.size();i++) {
        // cout << "a[i ]" << a[i] << endl;
        if (a[i] > last) {
            // cout << "ele " << a[i] - last << endl;
            rest.push_back({ a[i] - last,i });

        }
    }
    int i = 0;
    // for (i = 0;i < rest.size();i++) {
    //     cout << (rest[i].first) << " " << (rest[i].second + 1) << " /";

    // }
    // cout << endl;
    i = 0;
    bool display = false;
    while (p >= 1) {
        for (i = 0;i < rest.size();i++) {
            // cout << "p " << p << " res=" << (rest[i].first) << " ";
            if (rest[i].first >= 1) {
                p--;
            }
            rest[i] = { rest[i].first - 1,rest[i].second };
            if (p == 0) break;

            // cout << (rest[i].first) << " " << (rest[i].second + 1) << "\n";

        }
    }
    cout << "i " << i << endl;


    for (int j = i + 1;j < rest.size();j++) {
        if (rest[j].first >= 1) {
            display = true;
            cout << (rest[j].second + 1) << " ";
        }
    }
    for (int j = 0;j <= i;j++) {
        // cout << "here" << (rest[j].first) << endl;
        if (rest[j].first >= 1) {
            display = true;
            cout << (rest[j].second + 1) << " ";
        }
    }
    if (!display) cout << -1;




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