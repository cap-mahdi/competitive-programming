#include <bits/stdc++.h>
#define int long long int
using namespace std;


/*
    Euclidean Algorithm
    gcd(a,b) = gcd(b,a%b)
    gcd(a,0) = a
    gcd(0,b) = b
    Time Complexity: O(log(min(a,b))) proof https://www.geeksforgeeks.org/time-complexity-of-euclidean-algorithm/
    or you can check this : 
        a%b <= a-b
        a%b <= b-1
    => 2* (a%b) <= a-1 < a => a%b < a/2
    So gcd(a,b) = gcd(b,a/2) = gcd(a/2,b/2)
    in 2 steps we reach a/2 in 4 steps we reach a/4 the first from a or b to reach 1 the function will stop so that is why the complexity is O(log(min(a,b))) 
    Space Complexity: O(1)
*/
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

void solve(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a ,b);
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}