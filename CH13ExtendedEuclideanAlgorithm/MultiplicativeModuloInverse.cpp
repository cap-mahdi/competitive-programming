#include <bits/stdc++.h>
#define int long long int
using namespace std;
vector<int> extendedGCD(int a,int b){
    if(b==0){
        return {1,0,a};
    }
    vector <int> result = extendedGCD(b,a%b);
    int x1 = result[0];
    int y1 = result[1];
    int gcd = result[2];
    return {y1, x1 - (a/b)*y1,gcd};
    
}
/*
    Multiplicative modulo inverse of a modulo m is a number x such that (a*x)%m = 1
    if a and m are coprime then there exists a multiplicative modulo inverse of a modulo m
    if a and m are not coprime then there does not exist a multiplicative modulo inverse of a modulo m
    if a and m are coprime then we can use extended euclidean algorithm to find x and y such that ax + my = gcd(a,m) = 1 which indeed has a solution
    if we take modulo m on both sides we get ax = 1 (mod m)
    so x is the multiplicative modulo inverse of a modulo m
    Complexity: O(log(min(a,b))) same as gcd
*/
void MMI(int a,int m){
    //! if m is prime then we can use fermat's little theorem to find the multiplicative modulo inverse of a modulo m call the snippet ModuloArithmetic.cpp
    vector<int> result = extendedGCD(a,m);
    int x = result[0];
    int gcd = result[2];
    if(gcd!=1){
        cout<<"Multiplicative modulo inverse does not exist"<<endl;
    }
    else{
        int ans = (x%m + m)%m;//to make sure that ans is in the range [0,b-1]
        cout<<"Multiplicative modulo inverse is "<<ans<<endl;
    }
}

void solve(){
    int a,m;
    cin>>a>>m;
    MMI(a,m);
    
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}