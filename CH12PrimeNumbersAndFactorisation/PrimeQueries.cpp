#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    Problem: Prime Queries
    Statement: For each query, print the number of primes in the range [a,b]
    Approach: Sieve of Eratosthenes
        1. create prime sieve array 
        2. create cumulative sum array, cumulativeSum[i] stores the number of primes in the range [0,i], the forumla is cumulativeSum[i]=cumulativeSum[i-1]+sieve[i]
        3. for each query, print cumulativeSum[b]-cumulativeSum[a-1] if a!=0 else print cumulativeSum[b]
    Exemple
        Input
            5
            1 100
            50 100
            1 10
            11 20
            1 20
        Output
            25
            10
            4
            4
            8

*/


const int N = 1e6;

void primeSieve(vector<int> &sieve){
    sieve[2]=1;
    for(int i=3;i<=N;i+=2){
        sieve[i]=1;
    }
    for(int i=3; i<=N;i++){
        if(sieve[i]){
            
            for(int j=i*i;j<=N;j+=i){
                sieve[j]=0;
            }
        }
    }
}

void cumSum(vector<int> &cumulativeSum,vector<int> sieve){
    for(int i=2;i<=N;i++){
        cumulativeSum[i]+=cumulativeSum[i-1] + sieve[i];
    }
}

void solve(vector<int> cumulativeSum){
    int a,b;
    cin>>a>>b;
    if(a){
        cout<<cumulativeSum[b]-cumulativeSum[a-1]<<"\n";
    }else{
        cout<<cumulativeSum[b]<<"\n";
    }
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    vector<int> sieve(N+1,0);
    vector<int> cumulative(N+1,0);

    primeSieve(sieve);
    cumSum(cumulative,sieve);
    while(t--){
        solve(cumulative);
    }
    return 0;
}