#include <bits/stdc++.h>
#define int long long int
using namespace std;


/*
    Problem: Given an array of n integers, find the longest increasing subsequence in the array.

    Approach: Binary search
    video: https://www.youtube.com/watch?v=S9oUiVYEq7E

    complexity: O(nlogn)
    space complexity: O(n)



*/


vector<int> v;

bool compareIndexes(int i, int j) {
    return v[i] < v[j];

}

vector<int> LIS() {
    //O(nlogn)
    //returns the longest increasing subsequence
    int n = v.size();
    vector<int> T(n, -1), R(n, -1);
    int length = 1;
    T[0] = 0;
    for (int i = 1; i < n; i++) {
        if (v[i] < v[T[0]]) {
            T[0] = i;
        }
        else if (v[i] > v[T[length - 1]]) {//the subsequence is increasing strictly
            R[i] = T[length - 1];
            T[length++] = i;
        }
        else {
            int index = lower_bound(T.begin(), T.begin() + length, i, compareIndexes) - T.begin();
            R[i] = T[index - 1];
            T[index] = i;
        }
    }
    vector<int> result;
    for (int i = T[length - 1]; i >= 0; i = R[i]) {
        result.push_back(v[i]);
    }
    reverse(result.begin(), result.end());
    return result;

}

void solve() {
    v = { 3,4,-1 ,5,8 ,2,3,12 ,7,9,10 };
    int n = v.size();
    vector<int> result = LIS();
    for (auto x : result) {
        cout << x << " ";
    }
}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}