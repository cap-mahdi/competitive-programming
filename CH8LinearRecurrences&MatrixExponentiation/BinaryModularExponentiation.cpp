#include <bits/stdc++.h>

using namespace std;


/*
    * Time complexity: O(logb)
    * Space complexity: O(1)
    * use the property a*b mod c = (a mod c * b mod c) mod c
    The desired result int the end is (a^b) mod c
    But instead of calulating the result a^b and then taking mod c
        we take mod c at every step
        This is done to avoid overflow
    So instead of res = a^b1 * a^b2 * ... * a^bn
        we calculate res = [ [(a^b1 mod c) * (a^b2 mod c)] mod c ] * (a^b3 mod c) mod c ] * ...
        which is equal to (a^b1 * a^b2 * ... * a^bn) mod c
    We take MOD = 1e9 + 7 because it is a prime number
    and it is the largest prime number that can be stored in a 32 bit integer
    We ensure that when multiplying two numbers, the result is not greater than 1e18 so long long int is used 

*/
const int MOD = 1e9 + 7;

long long int binpow(long long int a, long long int b){
    long long int res = 1;
    while(b > 0){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main(){
    long long int a, b;
    cin >> a >> b;
    cout << binpow(a, b) << endl;
    return 0;
}