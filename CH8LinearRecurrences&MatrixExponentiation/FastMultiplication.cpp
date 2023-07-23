#include <bits/stdc++.h>

using namespace std;
/*
    Statement:
        * Given three numbers a, b, c
        * Calculate (a*b) mod c
    ! You cannot directly calculate (a*b) mod c because a*b can be very large, so it will overflow
    constarints:
        * 1 <= a, b, c <= 1e15
*/

long long int multiply(long long int a,long long int b,long long int c){
    long long int res = 0;
    while(b){
        if(b & 1) res = (res + a) % c;
        a = (a*2) % c;
        b >>= 1;
    }
    return res;
}

int main(){
    long long int a, b, c;
    cin >> a >> b >> c;
    cout << multiply(a, b, c) << endl;
    return 0;
}