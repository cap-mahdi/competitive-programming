#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*
    problem statement: sort an array using merge sort
    time complexity: O(nlogn)
    space complexity: O(n) and O(logn) for the recursive stack space
    approach: divide and conquer
    1- divide the array into two parts
    2- sort the two parts
    3- merge the two parts

    merge function:
    1- create a temp array
    2- compare the elements of the two parts and push the smaller one into the temp array
    3- copy the remaining elements of the two parts into the temp array
    4- copy the temp array into the original array

*/

void merge(vector<int> &arr,int s,int e){
    //O(n)
    vector<int> temp;
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    while(i <= mid && j <= e){
        if(arr[i] < arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }
    }

    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= e){
        temp.push_back(arr[j]);
        j++;
    }
    
    int k = 0;
    for(int idx = s; idx <= e; idx++){
        arr[idx] = temp[k++];
    }

}

void mergeSort(vector<int> &arr,int s,int e){
    //sort the array in the range [s,e]
    //O(nlogn)
    //base case
    if(s >= e){
        return;
    }

    //recursive case
    //divide
    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}

void solve(){
    vector<int> v = {5, 4, 3, 2, 1};
    
    mergeSort(v, 0, v.size() - 1);

    for(int x : v){
        cout << x << " ";
    }
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}