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
    while (cin >> n) {
        cout << "here " << n << endl;
        vector<int> pos(n);
        vector<int> s(n);
        for (int i = 0;i < n;i++) {
            cin >> s[i];
            pos[s[i]] = i;
        }
        vector<int> f(n);
        for (int i = 0;i < n;i++) {
            cin >> f[i];
        }
        int ans = 0;
        for (int i = n - 1;i >= 0;--i) {
            int person = s[i];
            bool ok = true;
            for (int j = n - 1;j > pos[person];j--) {
                if (f[j] == person) { ok = false;break; }
            }
            if (!ok) continue;
            for (int j = pos[person];j >= 0 && f[j] != person;j--) {
                ans++;
                pos[f[j]]++;
            }
            cout << "hereeee" << endl;

        }
        cout << "the answer is " << endl;
        cout << ans << "\n";
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