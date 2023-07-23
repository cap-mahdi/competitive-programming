#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*
    problem: https://www.spoj.com/problems/PRIME1/
    statement: given a range [m,n] find all the prime numbers in the range for t test cases
    solution: segmented sieve
    time complexity: O(nloglogn + (n-m+1)*sqrt(n)) 
    // nloglogn for sieve of eratosthenes and (n-m+1)*sqrt(n) for segmented sieve
    space complexity: O(n-m+1)
*/


#define N 100000
vector<int> sieve(N+1,0);
vector<int> primes;
void primeSieve(){
    sieve[2]=1; 
    primes.push_back(2);

    for(int i=3;i<=N;i+=2){
        sieve[i]=1;
    }
    for(int i=3; i<=N;i++){
        if(sieve[i]){
            primes.push_back(i);
            for(int j=i*i;j<=N;j+=i){
                sieve[j]=0;
            }
        }
    }
}


void segmentedSieve(){
    int n,m;
    cin>>m>>n;

    vector<int>segment(n-m+1,0);

    for(int p : primes){
        if(p*p>n){
            break;
        }

        int start =  (m/p) * p ;

        if(p>=m){
            start = 2*p;
        }
        for(int j=start;j<=n;j = j + p){
            if(j<m){
                continue;
            }
            segment[j-m]=1;
        }

        

    }
    for(int j=m;j<=n;j++){
            if(segment[j-m]==0){
                cout<<j<<"\n";
            }
        }
        cout<<"\n";
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    primeSieve();
    while(t--){
        segmentedSieve();
    }
    return 0;
}

/*
1
999900000 1000000000
*/
