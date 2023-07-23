#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*
    Euler Totient Function
    Euler Totient Function is also known as phi function
    phi(n) = number of integers from 1 to n inclusive which are coprime to n
    phi(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk)
    where p1, p2, ..., pk are prime factors of n
     it used also to find the number of integers x such that 1 <= x <= n and gcd(x, n) = g

     Input: n = 10, g = 2
        Output: 4
        Explanation: The possible values of x are 2, 4, 6, 8.
*/

const int N = 1e6+5;

int phi[N];
void calcul_totient(){
    //calculating phi for all numbers from 1 to N
    //Complexity: O(NloglogN)
    iota(phi,phi+N,0);
    for(int i=2;i<N;i++){
        if(phi[i]==i){
            for(int j=i;j<N;j+=i){
                phi[j] -= phi[j]/i;
            }
        }
    }
}

int count_numbers_with_gcd(int n,int g){
    if(n%g!=0) return 0;
    return phi[n/g];
}   

void solve(){
    int n,g;
    cin>>n>>g;
    calcul_totient();
    cout<<count_numbers_with_gcd(n,g)<<endl;
    
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}


