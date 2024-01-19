#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int P = 1e9 + 7;//it shoud be prime number because we are using fermat's little theorem whichi is only applicable for prime numbers
//the theoreme is : a^(p-1) = 1 (mod p) where p is prime number and a is any number so  we can write a^(p-2) = a^(-1) (mod p) which is the inverse of a



int multiplymod(int a, int b) {
    return (a * b) % P;//a and b must be long long int because at worst case a*b can be 1e18 which cannot be stored in int
}

int powermod(int a, int b) {
    //it determines a^b (mod p)
    //fast exponentiation in O(log(b))
    int res = 1;
    while (b) {
        if (b & 1) {
            res = multiplymod(res, a);
        }
        a = multiplymod(a, a);
        b >>= 1;
    }
    return res;
}

int modInverse(int a) {
    //it determines  a^(-1) (mod p)
    ///O(log(P ))
    //using fermat's little theorem
    return powermod(a, P - 2);
}



void solve() {

    cout << modInverse(30) << "\n";

}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}