#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*
    problem statement:-for t test cases, given n and k, find the binomial coefficient of n and k
    binomial coefficient of n and k is the number of ways to choose k elements from n elements
    approach:- we can use the formula nCk = n!/(k!*(n-k)!)
    but this approach will give TLE for large values of n and k (because the problem is t queries).
    so we will use the concept of pascal's triangle to solve this problem.
    we will precompute the binomial coefficients for all values of n and k and store them in a 2D vector.
    then we will simply print the value of binomialCoefficients[n][k] for each test case.
    we will use the formula nCk = (n-1)C(k-1) + (n-1)Ck to compute the binomial coefficients. and nC0 = 1 and nCn = 1
    time complexity:- O(n^2)
    space complexity:- O(n^2)

*/

const int N = 1e3;
 vector<vector<int>> binomialCoefficients(N+1, vector<int>(1,0));
void computeBinomialCoefficients(){
   
    for(int i=0; i<=N; i++){
        binomialCoefficients[i][0] = 1;
        for(int j=1; j<i; j++){
            binomialCoefficients[i].push_back(binomialCoefficients[i-1][j-1] + binomialCoefficients[i-1][j]);
        }
        binomialCoefficients[i].push_back(1);
    }
}
/*
int nCr(int n,int k){
    return binomialCoefficients[n][k];
}
const int P = 1e9 + 7;
int fact[N];
int multiplymod(int a, int b){
    return (a * b) % P;//a and b must be long long int because at worst case a*b can be 1e18 which cannot be stored in int
}
int calculateFactorialMod(){
    //O(N) 
    fact[0] = 1;
    for(int i = 1; i <= N; i++){
        fact[i] = multiplymod(fact[i - 1], i);
    }
}
int nPr(int n,int k){
    return binomialCoefficients[n][k]*fact[k];
}


*/
void solve(){
    int n,k;
    cin>>n>>k;
    if(k>n){
        cout<<0<<endl;
        return;
    }
    cout<<binomialCoefficients[n][k]<<endl;
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    computeBinomialCoefficients();
    while(t--){
        solve();
    }
    return 0;
}