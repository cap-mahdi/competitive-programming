#include <bits/stdc++.h>
#define int long long int
using namespace std;


/*
    Statement: Given a number N, print all primes smaller than or equal to N.
    Approach: Sieve of Eratosthenes
        1. create a boolean array of size N+1 and initialize all elements to false
        2. mark all odd numbers as true
        3. start from 3 and unmark all multiples of 3 as false
        4. then redo step 3 for all marked numbers(primes)
        note that we are starting from i*i because all numbers before i*i are already unmarked by their factors
        because suppose p=5 then all numbers before 5*5, if they are not prime, then they have at least on prime factor less than their square root so less than 5, so they are already unmarked by their factors
        
    Time Complexity: O(N*log(log(N))) check this link for proof: https://www.geeksforgeeks.org/how-is-the-time-complexity-of-sieve-of-eratosthenes-is-nloglogn/
    Space Complexity: O(N)

    !!!NOTE: This is the most efficient algorithm to find all primes smaller than or equal to N.
    !!!NOTE: This algorithm is not suitable for large N.
    !!If you work with the range of 10^6 to 10^8, then this algorithm is suitable.
    !!If you work with the range of 10^9 to more, then this algorithm is not suitable beacause it will take more time to create the sieve array and because of the large size of the array, it will take more space. with 10^9 the size of the array would be 4(size of integer)*10^9 bytes which is 4GB.
    for n = 10^8, it will take 0.5 seconds to create the sieve array and for n = 10^9, it will take 5 seconds to create the sieve array.
    !!If you work with the basic method of checking all numbers from 2 to N-1, then it will take O(N * sqrt(N)) time.
    !! if you are demand to check if a number is prime or not for a signle time then the basic method is more efficient.
*/

#define N 10000000

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


int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> sieve(N+1,0);
    primeSieve(sieve);

    for(int i=0;i<=100;i++){
        if(sieve[i]){
            cout<<i<<" ";
        }
    }
    return 0;
}