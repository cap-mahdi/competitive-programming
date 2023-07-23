#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*
    Problem: Given three numbers a,b,c. Find the integral solution of ax + by = c where x and y are integers 
    Solution: 
        1. Find the solution of ax + by = gcd(a,b) using extended euclidean algorithm
        2. If c % gcd(a,b) != 0 then there is no solution
        3. If c % gcd(a,b) == 0 then there are infinite solutions
            3.1. Find the solution of ax + by = 1 using extended euclidean algorithm
            let g = gcd(a,b) and a1 = a/g and b1 = b/g (a1 and b1 are coprime)
            3.2. Multiply both sides by c/g and to make both of them positive and in the range of 0 to b1  and 0 to  a1
            we do this x0 = ( (x0*c)%b1 + b1) % b1  and y0 = ( (y0*c) %a1 + a1) % a1
            3.3. x = x0 * c/g + k * b1
            3.4. y = y0 * c/g - k * a1
            3.5. k is any integer
            3.6. x and y are integral solution
    complexity: O(log(min(a,b)))
*/
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

void soltuionForLinearDiophantine(int a,int b,int c){
    vector<int> result = extendedGCD(a,b);
    int x0 = result[0];
    int y0 = result[1];
    int gcd = result[2];

    if(c%gcd){
        cout<<"there is no solution";
        return;
    }

    int k = c /gcd;
    int a1 = a / gcd;
    int b1 = b/gcd; 
    x0 = ( (x0*c)%b1 + b1) % b1;
    y0 = ( (y0*c) %a1 + a1) % a1;
    cout<<"x = "<<x0<<" + k*"<<b1<<"\n";
    cout<<"y = "<<y0<<" - k*"<<a1<<"\n";
}

void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    soltuionForLinearDiophantine(a,b,c);
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

