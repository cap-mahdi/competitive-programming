#include <bits/stdc++.h>

using namespace std;
/*
    * Time complexity: O(logb)
    * Space complexity: O(1)
    * explication of the algorithm:
        * check if b is odd or even
        * if b is odd, we multiply res by a
        * we multiply a by a and divide b by 2
        * we repeat the process until b is 0
*/

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << binpow(a, b) << endl;
    return 0;
}