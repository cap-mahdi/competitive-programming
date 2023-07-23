#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*
    problem: you have k friends and n coins with you. 
    you have to divide the coins among you and your friends.
    your friends are greedy and they will always choose the partition with the minimum sum.
    you will be left with the partition with the minimum sum.
    you have to maximize the minimum sum of the partition.

    approach: binary search
    our search space is again monotonic; it is the range of the minimum sum of the partition.
    it is in the range [min(coins),sum(coins)]

    time complexity: O(nlog(sum(coins)-min(coins)))//O(log(sum(coins)-min(coins)) for binary search and O(n) for canHaveKPartitions function
    space complexity: O(1)

*/

bool canHaveKPartitions(vector<int> coins,int friends,int min_sum){
    //can we have k partitions such that each partition has sum<=min_sum
    //O(n)
    int n = coins.size();
    int sum = 0;
    int count = 0;
    for(int i=0;i<n;i++){
        sum+=coins[i];
        if(sum>=min_sum){
            count++;
            sum = coins[i];
        }
    }
    return count>=friends;
}


int maximizeMinmumPartitions(vector<int> coins,int friends){
    //find the maximum value of the minimum partition 
    //O(nlog(sum(coins)-min(coins)))
    int n = coins.size();

    int start = coins[0];
    int end=0;

    for(int i=0;i<n;i++){
        start = min(start,coins[i]);
        end += coins[i];
    }

    int ans = 0;
    while(start<=end){
        int mid = (start+end)/2;
        
        if(canHaveKPartitions(coins,friends,mid)){
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
    vector<int> coins = {1,2,3,4};
    int friends = 4;
    cout<<maximizeMinmumPartitions(coins,friends)<<"\n";
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}