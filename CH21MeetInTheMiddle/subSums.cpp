#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*

    Problem Link: https://www.spoj.com/problems/SUBSUMS/
    Statement: Given n numbers and two numbers a and b, find the number of subsets whose sum lies in the range [a,b].
    n<=34
    Approach: Meet in the middle algorithm.
    If we generate all the subsets of the given array and check the sum of each subset, it will take O(2^n) time and O(2^n) space which will give TLE and MLE.
    the idea is to divide the array into two parts and generate all the subsets of each part and store the sum of each subset in two arrays.
    Now sort the second array and for each element in the first array, find the number of elements in the second array whose sum lies in the range [a-x,b-x] where x is the sum of the current subset of the first array.
    we find the number of elements in the second array whose sum lies in the range [a,b] using Upper bound(b-x) - Lower bound(a-x).

    Time Complexity:
    O(2^(n/2)) + O(2^(n/2)) + O(2^(n/2)log(2^(n/2))) = O(2^(n/2)log(2^(n/2)))

*/

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int mid = n / 2;
    int size1 = (1 << (mid + 1)), size2 = 1 << (n - mid - 1);

    int sum1[size1];
    for (int i = 0;i < size1;i++) {
        int val = 0;
        int j = 0;
        int temp = i;
        while (temp) {
            if (temp & 1) val += s[j];
            temp >>= 1;
            j++;
        }
        sum1[i] = val;
    }

    int sum2[size2];
    for (int i = 0;i < size2;i++) {
        int val = 0;
        int j = mid + 1;
        int temp = i;
        while (temp) {
            if (temp & 1) val += s[j];
            temp >>= 1;
            j++;
        }
        sum2[i] = val;
    }
    sort(sum2, sum2 + size2);


    // for (int i : sum1) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // for (int i : sum2) {
    //     cout << i << " ";
    // }

    int ans = 0;
    for (int i : sum1) {
        ans += count_number_of_elements_in_range(sum2, size2, a - i, b - i);
    }
    cout << ans;

}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}


/*
5 1 2
1 5 10 15 63



*/