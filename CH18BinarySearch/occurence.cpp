#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*
    problem: given a sorted array and a key find the number of occurences of the key in the array
    approach: binary search
    we will find the lower bound and upper bound of the key and then the number of occurences will be upper-lower+1
    time complexity: O(logn)
    space complexity: O(1)

*/
int lowerBound(vector<int> v,int key){
    //lower bound is the first index where the key is present in a sorted array
    //O(logn)
    int n = v.size();
    int start = 0;
    int end = n-1;
    int ans = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(v[mid]==key){
            ans = mid;
            end = mid-1;
        }
        else if(v[mid]>key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int upperBound(vector<int> v,int key){
    //upper bound is the last index where the key is present in a sorted array
    //O(logn)
    int n = v.size();
    int start = 0;
    int end = n-1;
    int ans = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(v[mid]==key){
            ans = mid;
            start = mid+1;
        }
        else if(v[mid]>key){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int occurence(vector<int> v,int key){
    //find the number of occurences of the key in the sorted array
    //O(logn)  
    int lower = lowerBound(v,key);
    int upper = upperBound(v,key);
    if(lower==-1) return 0;
    return upper-lower+1;
}

void solve(){
    vector<int> v = {1,1,1,2,2,3,3,3,3,3,4,4,4,5,5,5,6,6,7,7,7,8};
    int key;
    cin>>key;
    cout<<occurence(v,key);

}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}