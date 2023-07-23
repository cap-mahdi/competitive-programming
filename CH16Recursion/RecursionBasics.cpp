#include <bits/stdc++.h>
#define int long long int
using namespace std;

int factorial(int n){
    //Time complexity: O(n)
    //Space complexity: O(n) because of call stack VIEW PAPER
    //base case
    if(n==0){
        return 1;
    }
    //recursive case
    int smallAns = factorial(n-1);
    return n*smallAns;
}

int fibonnaci(int n,int * dp){
    //Time complexity: O(n) without memoization it is O(2^n)
    //Space complexity: O(n) because of call stack (max depth of tree is n if it without dp VIEW PAPER)
    //base case
    if(n==0 || n==1){
        return n;
    }
    //recursive case
    if(dp[n]!=0){
        return dp[n];
    }
    int ans = fibonnaci(n-1,dp) + fibonnaci(n-2,dp);
    return dp[n] = ans;
}

bool isSorted(int * arr,int n){
    //Time complexity: O(n)
    //Space complexity: O(n) 
    //base case
    if(n==0 || n==1){
        return true;
    }
    //recursive case
    return (arr[0]<=arr[1] && isSorted(arr+1,n-1));
}

//understand recursion directions
//Bottom to top
void printInc(int n){
    //Time complexity: O(n)
    //Space complexity: O(n)
    //base case
    if(n==0){
        return;
    }
    //recursive case
    printInc(n-1);
    cout<<n<<" ";
}
//Top to bottom
void printDec(int n){
    //Time complexity: O(n)
    //Space complexity: O(n)
    //base case
    if(n==0){
        return;
    }
    //recursive case
    cout<<n<<" ";
    printDec(n-1);
}


int power(int a,int n){
    //Time complexity: O(n)
    //Space complexity: O(n)
    //base case
    if(n==0){
        return 1;
    }
    //recursive case
    return a*power(a,n-1);
}

int fastPower(int a,int n){
    //Time complexity: O(logn)
    //Space complexity: O(logn)
    //base case
    if(n==0){
        return 1;
    }
    //recursive case
    //a^n = a^(n/2) * a^(n/2) if n is even
    //a^n = a^(n/2) * a^(n/2) * a if n is odd
    int smallAns = fastPower(a,n/2);
    smallAns*=smallAns;
    if(n&1){
        return a*smallAns;
    }
    return smallAns;
}



void solve(){
    int n = 6;
    cout<<factorial(n)<<endl;

    int dp[100] = {0};
    cout<<fibonnaci(n,dp)<<endl;

    int sortedArray[5] = {1,2,3,4,5};
    cout<<isSorted(sortedArray,5)<<endl;
    int nonSortedArray[5] = {1,2,3,5,4};
    cout<<isSorted(nonSortedArray,5)<<endl;

    printInc(n);
    cout<<endl;
    printDec(n);
    cout<<endl;

    cout<<power(2,5)<<endl;
    cout<<fastPower(2,5)<<endl;
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}