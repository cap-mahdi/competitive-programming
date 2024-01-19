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
    string s;
    cin >> s;
    if (s.substr(0, 6) == "$GPGGA") {
        cout << "signal void GGA(void){\n";
    }
    else {
        cout << "signal void RMC(void){\n";
    }

    for (char c : s) {
        cout << "swatch(0.01);" << "S1IN='" << c << "';" << "\n";
    }
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "\n";

    cout << "}" << "\n";


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
        if (t) {
            cout << "\n";
        }
    }
    return 0;
}