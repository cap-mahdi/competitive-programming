#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    Problem: return the minimum possible last number of a increasing sequence of length L.
    if no such sequence exists return -1.
    Link: https://www.spoj.com/problems/NDS/

*/

int LIS(int a[], int n, int l) {
    //returns the maximum possible last number of a increasing sequence of length L.
    //O(nlogn)
    vector<int> T;
    T.push_back(a[0]);
    for (int i = 1;i < n;i++) {
        if (a[i] > T.back()) {
            T.push_back(a[i]);
        }
        else {
            int index = lower_bound(T.begin(), T.end(), a[i]) - T.begin();
            //the commented code is for strictly increasing subsequence
            // if (index > 0 && T[index - 1] == a[i]) {
            //     continue;
            // }
            T[index] = a[i];
        }
    }

    if (T.size() < l) {
        return -1;
    }
    return T[l - 1]; //return the e minimum possible last number of a increasing sequence of length L.
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l;
    cin >> l;
    cout << LIS(a, n, l) << "\n";
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