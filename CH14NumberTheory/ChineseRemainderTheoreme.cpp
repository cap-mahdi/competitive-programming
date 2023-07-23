#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*
    Chinese Remainder Theorem
    Given n integers a1, a2, a3, ..., an and n coprime integers m1, m2, m3, ..., mn
    Find x such that:
        x = a1 (mod m1)
        x = a2 (mod m2)
        x = a3 (mod m3)
        .
        .
        .
        x = an (mod mn)
    The solution is unique modulo M = m1 * m2 * m3 * ... * mn
    x = a1 * M1 * inv(M1, m1) + a2 * M2 * inv(M2, m2) + ... + an * Mn * inv(Mn, mn) (mod M)
    where Mi = M / mi
    and inv(Mi, mi) is the multiplicative modulo inverse of Mi modulo mi
    Complexity: O(n * log(M))

    Example:
    x = 2 (mod 3)
    x = 3 (mod 5)
    x = 4 (mod 7)
    Input 
    3
    3 2
    5 3
    7 4
    Output
    56 + k*105
*/


const int mod = 1e9 + 7;
int multiplymod(int a, int b){
    return (a * b) % mod ;//a and b must be long long int because at worst case a*b can be 1e18 which cannot be stored in int
}


int powermod(int a, int b){
    //fast exponentiation in O(log(b))
    int res = 1;
    while(b){
        if(b & 1){
            res = multiplymod(res, a);
        }
        a = multiplymod(a, a);
        b >>= 1;
    }
    return res;
}

int modInverse(int a, int p){
    ///O(log(P))
    // if P is prime then you can directly find the modulo inverse of a using fermat's little theorem
    //using fermat's little theorem
    return powermod(a, p-2);
}
void ChineseRemainderTheorem(int * primes ,int * remainders,int n){
    int N = 1;
    for(int i = 0; i < n; i++){
        N *= primes[i];
    }
    int result = 0;
    for(int i = 0; i < n; i++){
        int Ni = (N / primes[i]);
        int x = multiplymod(remainders[i], modInverse(Ni % primes[i], primes[i]));
        result += multiplymod(x, Ni);
    }
    cout << result % N << " + k*" << N  << endl;
}

void solve(){
    int n;
    cin>>n;
    int primes[n];
    int remainders[n];
    for(int i = 0; i < n; i++){
        cin >> primes[i];
        cin>>remainders[i];
    }
    ChineseRemainderTheorem(primes,remainders, n);
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}