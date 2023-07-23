#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
  problem statement: print all the permutations of a string
  input: abc
  ouptut: abc,acb,bac,bca,cab,cba

  approach: backtracking
    for each character we have n choices where n is the length of the string
    we swap the current character with all the characters after it and find all the permutations of the remaining string
    then we swap back the current character with all the characters after it // this is called backtracking meaning we are undoing the changes we made to the string

    time complexity: O(n*n!) // n! permutations and for each permutation we are doing n swaps
    space complexity: O(n)  

*/

void permutation(string s,string output,int i,int n){
    //base case
    if(i==n){
        cout<<output<<"\n";
        return;
    }

    //recursive case
    for(int j=i;j<n;j++){
        swap(s[i],s[j]);
        permutation(s,output+s[i],i+1,n);
        swap(s[i],s[j]);
    }
   
}




void solve(){
    string s,output;
    cin>>s;
    permutation(s,output,0,s.size());
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}