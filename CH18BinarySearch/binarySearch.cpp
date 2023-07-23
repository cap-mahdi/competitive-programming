#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    problem: given a sorted array and a key find the index of the key in the array
    approach: binary search

    time complexity: O(logn)
    space complexity: O(1)

*/

int binarySearch(vector<int> v,int key){
    //find the index of the key in the sorted array
    //O(logn)
    int n = v.size();
    int start = 0;
    int end = n-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(v[mid]==key){
            return mid;
        }
        else if(v[mid]>key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1;
}

void solve(){
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    int key;
    cin>>key;
    cout<<binarySearch(v,key);
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}