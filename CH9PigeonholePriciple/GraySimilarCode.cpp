#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*
    site: Codechef problem name: GRAY similar code
    Statement: Given an array of n integers, where 2 consecutive integers differ in only one bit,
    find 4 integers whose xor is 0.
    if such 4 integers exist print "Yes" else print "No".
    Approach:
        if(n>=130) then print "Yes" because if we xor 2 consecutive integers then we will get 64 different values.(1<<63 to 1<<0)
        so we will have 65 pairs of integers with different xor values.At least two pairs will have same xor value.(pigeonhole principle)

        if(n<130) then we will check for every triplet if there is a number in the array with xor value equal to the xor of the triplet.
        if such a number exists then print "Yes" else print "No".
        we will do it in O(n^3) time.because we will store the numbers in a map and check if the number exists in the map or not.
*/
void solve(){
    int n;
    cin>>n;
    int v[n];
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    if(n>=130){
        cout<<"Yes\n";
        return;
    }
    //the following code is for n<130
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            for(int k = j+1;k<n;k++){
                for(int l = k+1;l<n;l++){
                    if((v[i]^v[j]^v[k]^v[l])==0 ){
                        cout<<"Yes\n";
                        return  ;
                    }
                }
            }
        }
    }
    cout<<"No\n";
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
/*
    input:
        4
        1 2 3 4
    output:
        No
    input:
        5
        1 2 3 4 5
    output:
        Yes
    input:
        6
        7 1 0 2 3 7
    output:
        Yes
*/