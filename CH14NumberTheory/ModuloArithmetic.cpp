#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int P = 1e9 + 7 ;//it shoud be prime number because we are using fermat's little theorem whichi is only applicable for prime numbers
//the theoreme is : a^(p-1) = 1 (mod p) where p is prime number and a is any number so  we can write a^(p-2) = a^(-1) (mod p) which is the inverse of a
const int N = 1e5 ;
int fact[N];

int addmod(int a, int b){
    return (a + b) % P;
}

int submod(int a, int b){
    return (a - b + P) % P;// to make sure the remainder is in the range [0, P-1]
}

int multiplymod(int a, int b){
    return (a * b) % P;//a and b must be long long int because at worst case a*b can be 1e18 which cannot be stored in int
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

int modInverse(int a){
    ///O(log(P))
    // if P is prime then you can directly find the modulo inverse of a using fermat's little theorem
    //using fermat's little theorem
    return powermod(a, P - 2);
}

int divideMod(int a, int b){
    //O(log(P))
    //a/b = a * (b^(-1)) (mod p) = a * (b^(p-2)) (mod p)
    return multiplymod(a, modInverse(b));
}

int calculateFactorialMod(){
    //O(N) 
    fact[0] = 1;
    for(int i = 1; i <= N; i++){
        fact[i] = multiplymod(fact[i - 1], i);
    }
}

int nCr(int n, int r){

    //O(log(P))
    //nCr = n! / (r! * (n - r)!)
    //nCr = n! * (r! * (n - r)!)^(-1) (mod p)
    //nCr = n! * (r! * (n - r)!)^(p - 2) (mod p)
    int numerator = fact[n];
    int denominator = multiplymod(fact[r], fact[n - r]);
    return multiplymod(numerator, modInverse(denominator));
}

int nPr(int n, int r){
    //O(log(P))
    //nPr = n! / (n - r)! because nPr = n * (n - 1) * (n - 2) * ... * (n - r + 1)
    //nPr = n! * (n - r)!^(-1) (mod p)
    //nPr = n! * (n - r)!^(p - 2) (mod p)
    int numerator = fact[n];
    int denominator = fact[n - r];
    return multiplymod(numerator, modInverse(denominator));
}

void solve(){
    cout<<addmod(3,5)<<endl;
    cout<<submod(3,5)<<endl;
    cout<<multiplymod(324,234)<<endl;
    cout<<divideMod(56,2)<<endl;//56/2 should be an integer

    calculateFactorialMod();
    cout<<fact[5]<<endl;
    cout<< nCr(5,2)<<endl;
    cout<<nCr(5778,123)<<endl;
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}