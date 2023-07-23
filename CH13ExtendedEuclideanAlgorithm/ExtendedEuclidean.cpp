#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*
    problem:  find x and y such that ax + by = gcd(a,b), s and y should be integers
    solution: 1. base case: if b==0 then x=1 and y=0(can be any values)
              2. recursive case: x1 and y1 are the solution of b and a%b
              3. x = y1
                 y = x1 - (a/b)*y1
    Demonstration:
        ax + by = gcd(a,b)
        bx1 + (a%b)y1 = gcd(b,a%b)
        bx1 + (a - (a/b)*b)y1 = gcd(b,a%b)
        ay1 + b(x1 - (a/b)*y1) = gcd(b,a%b) = gcd(a,b)
        x = y1
        y = x1 - (a/b)*y1
    This is called a bottom up approach
    Complexity: O(log(min(a,b))) same as gcd

*/
void extendedGCD(int a,int b,int &x ,int &y){
    if( b==0 ){
        x=1;
        y=0;
        return;
    }

    int x1,y1;
    extendedGCD(b,a%b,x1,y1);
    x = y1;
    y = x1 - (a/b)*y1;
}
/*
    This is another way of implementing Extended Euclide Algorithm
    it returns {x,y,gcd(a,b)} 
    
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

void solve(){
    int a,b;
    cin>>a>>b;
    int x,y;
    extendedGCD(a,b,x,y);
    cout<<x<<" "<<y<<endl;

    vector<int> result = extendedGCD(a,b);
    cout<<"x "<<result[0] <<" y "<<result[1]<<" gcd "<<result[2]<<endl;   
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}