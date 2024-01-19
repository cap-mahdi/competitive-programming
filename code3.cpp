#include <bits/stdc++.h>
#define int long long int
using namespace std;

void no() {
    cout << "NO" << "\n";
}
void yes() {
    cout << "YES" << "\n";
}

bool isSum(int s, vector<int>& c) {
    cout << "s" << s << endl;
    for (int i = 33;i >= 0;i--) {
        if ((s >> i) & 1) {
            if (c[i] > 0) { c[i]--; continue; }
            bool isDoable = isSum(s & (1 << i), c);
            if (!isDoable)
                return false;

        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(30, 0);
    while (n--) {
        int t, s;
        cin >> t >> s;
        if (t == 1) {
            a[s]++;
        }
        else {
            vector<int> c = a;
            if (isSum(s, c)) {
                yes();
            }
            else {
                no();
            }
        }
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