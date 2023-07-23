#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 1000000;
/*
    Problem : Prime Factorisation
    Statement: Given a number n, print its prime factorisation
    Approach: Brute Force, Optimised, Sieve of Eratosthenes
*/

/*
    Brute Force Approach
    we will iterate from 2 to n to find each time the next smallest prime factor of n
    Time Complexity: O(n)
    Space Complexity: O(1)
*/

void factoriseBruteForce(int n){
    for(int i=2;i<=n;i++){
        if(n%i==0){
            int count =0;
            while(n%i == 0){
                count++;
                n/=i;
            }
            cout<<i<<"^"<<count<<",";
        }
    }
    cout<<endl;
}
/*
    Optimised Approach
    we will iterate from 2 to sqrt(n) to find each time the next smallest prime factor of n
    suppose n=99, we will find 3 as a prime factor, then we will divide n by 3, so n=33, now we will again find 3 as a prime factor, then we will divide n by 3, so n=11, the loop will break beacause 4*4>11, the idea here is that the last value of n (=11 in this case) none of the previous values of i (2,3) could divide n, and we reach sqrt(n) so sure that n is a prime number
    Time Complexity: O(sqrt(n))
    Space Complexity: O(1)
*/
void factoriseOpt(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            int count =0;
            while(n%i == 0){
                count++;
                n/=i;
            }
            cout<<i<<"^"<<count<<",";
        }
    }
    if(n!=1){
         cout<<n<<"^"<<1;
    }
    cout<<endl;
}

vector<int> sieve(N+1,0);
/*
    Sieve of Eratosthenes Approach
    we will create a sieve array of size N+1, sieve[i] stores the smallest prime factor of i
    Time Complexity: O(nloglogn)
    Space Complexity: O(n) again problem of space complexity if n>10^7 the sieve array will not fit in memory
*/
void primeSieveFactorisation(){
    for(int i=2;i<=N;i+=2){
        sieve[i]=2;
    }
    for(int i=3;i<=N;i++){
        if(sieve[i]==0){
            sieve[i]=i;
            for(int j=i*i;j<=N;j+=i){
                if(sieve[j]==0)
                    sieve[j]=i;
            }
        }
    }
}
/*
    we will take the smallest prime factor of n from sieve[n] and divide n by it, we will repeat this process until n becomes 1
    Time Complexity: O(logn)
    Space Complexity: O(1)
*/
void factoriseSieve(int n){
    while(n!=1){
        int count =0;
        int prime = sieve[n];
        while(n%prime == 0 ){
            count++;
            n/=prime;
        }
        cout<<prime<<"^"<<count<<",";
    }
}
void solve(){
    int n;
    cin>>n;
    factoriseBruteForce(n);
    factoriseOpt(n);
    factoriseSieve(n);
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    primeSieveFactorisation();
    solve();
    return 0;
}