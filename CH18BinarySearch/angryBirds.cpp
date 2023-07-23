#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*
    problem: given n nests and m birds find the largest minimum distance between any two birds
    input: n = 5, m = 3
           nests = {4,8,9,1,2}
    output: 3
    approach: binary search
    *********WHY CHOOSE BINARY SEARCH?*********
    our search space is the possible minimum distances between any two birds so it is between 0 and max-min
    so our search space is MONOTONIC ,at first we have YES YES ... YES NO NO ... NO
    so we can apply binary search and with each mid we can check if we can place the birds with minimum distance mid

    When checking if we can place the birds with minimum distance mid we will begin with the first nest and place the bird there
    then we will check if we can place the next bird at a distance of mid from the first bird if we can then we will place it there

    WHY BEGIN WITH THE FIRST NEST?
    suppose that the best solution is starting at th ith nest then there are two cases if we place the first bird on the first nest and not on the ith nest
    then there are 2 cases:
    -the min distance becomes larger than we find the actual best solution
    -the min distance stays the same, so here another best solution



    time complexity: O(nlog(max-min)  )//logn for binary search and n for canPlaceBirds each time we call it
    space complexity: O(1)


*/
bool canPlaceBirds(vector<int> v,int min_distance,int birds){
    //can we place birds with minimum distance min_distance
    //O(n)


    int n = v.size();
    int birdsPlaced = 1;
    int lastPlaced = v[0];
    for(int i=1;i<n;i++){
        if(v[i]-lastPlaced>=min_distance){
            birdsPlaced++;
            lastPlaced = v[i];
        }
        if(birdsPlaced==birds){
            return true;
        }
    }
    return false;
}

int largestMinimumDistance(vector<int> v,int birds){
    //find the largest minimum distance between any two birds
    //O(nlogmax-min)

    sort(v.begin(),v.end());


    int n = v.size();
    int start = 0;
    int end = v[n-1]-v[0];
    int ans = -1;
    while(start<=end){
        int mid = (start+end)/2;
        int birdsPlaced = 1;
        int lastPlaced = v[0];
        if(canPlaceBirds(v,mid,birds)){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }

    }
    return ans;
}

void solve(){
    vector<int> nests = {4,8,9,1,2}; //it can be not sorted
    int birds = 3;
    cout<<largestMinimumDistance(nests,birds);
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}