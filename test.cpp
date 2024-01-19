#include <bits/stdc++.h>
#define int long long int
using namespace std;

void no() {
    cout << "NO" << "\n";
}
void yes() {
    cout << "YES" << "\n";
}

const int N = 1e6;

// factorise a number into its prime factors
// used if you have to factorise a number for multiple times (test cases)
// precomputation: O(nloglogn)
// the factorisation of a number can be done in O(logn) time
// space complexity: O(n)
vector<int> sieve(N + 1, 0);


void primeSieveFactorisation() {
    for (int i = 2;i <= N;i += 2) {
        sieve[i] = 2;
    }
    for (int i = 3;i <= N;i++) {
        if (sieve[i] == 0) {
            sieve[i] = i;
            for (int j = i * i;j <= N;j += i) {
                if (sieve[j] == 0)
                    sieve[j] = i;
            }
        }
    }
}


vector<pair<int, int>> factoriseSieve(int n) {
    vector<pair<int, int>> res;
    while (n != 1) {
        int count = 0;
        int prime = sieve[n];
        while (n % prime == 0) {
            count++;
            n /= prime;
        }
        res.push_back({ prime,count });
    }
    return res;
}

void solve() {
    int p;
    cin >> p;
    if (p > N)
        cout << -1 << "\n";
    vector<pair<int, int>> res = factoriseSieve(p);
    int sum = 0;
    int n = 0;
    for (auto p : res) {
        sum += p.first * p.second;
        n += p.second;
    }
    int left = 41 - sum;
    if (sum > 41 || n + left > 100) {
        cout << -1 << "\n";
        return;
    }
    vector<int> answer;
    while (left--)
    {
        answer.push_back({ 1 });

    }
    for (auto p : res) {
        for (int i = 0;i < p.second;i++)
            answer.push_back({ p.first });
    }
    vector <int> answer2;
    int N = answer.size();
    for (int i = N - 1;i >= 0;i--) {
        int curr = 0;
        while ()
    }

    cout << "\n";
}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    primeSieveFactorisation();
    int t;
    cin >> t;
    for (int i = 1;i <= t;i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}