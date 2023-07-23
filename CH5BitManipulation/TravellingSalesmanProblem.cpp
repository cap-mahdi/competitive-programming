#include <bits/stdc++.h>

using namespace std;
/*
    Statement: Given a set of cities and distance between every pair of cities, the problem is to find the shortest possible route that visits every city exactly once and returns to the starting point.
    Approach:
        1. Brute force approach: Find all the permutations of the cities and find the minimum distance.
            a. Time complexity: O((n-1)!*n)
            b. Space complexity: O(1)
        2. DP approach: 
            a. Create a dp array of size 2^n * n.
            b. dp[i][j] represents the minimum distance to travel all the cities in the set i and ending at city j.
            c. dp[0][0] = 0;
    Complexity:
        Time: O(n^2 * 2^n)
        Space: O(n * 2^n)
    Example:
        Input: 
            0 20 42 25
            20 0 30 34
            42 30 0 10
            25 34 10 0
        Output: 85
            

*/

// int tsp(vector<vector <int> > dist , int setOfCities,int  city, int n){
//     if(setOfCities == (1<<n) - 1)
//         return dist[city][0];
    
//     int ans = INT_MAX;
//     for(int choice=0;choice<n;choice++){
//         if( ( setOfCities & (1<<choice) ) == 0){

//             int subProb = dist[city][choice] + tsp(dist,setOfCities | (1<<choice),choice,n);
//             ans = min(ans,subProb);
            
//         }
//     }
//     return ans;
    
// }

//DP approach 
int tsp(vector<vector <int> > dist , int setOfCities,int  city, int n, vector<vector<int>> &dp){
    if(setOfCities == (1<<n) - 1)
        return dist[city][0];
    
    if(dp[setOfCities][city] != -1)
        {
            return dp[setOfCities][city];
        }
    
    int ans = INT_MAX;
    for(int choice=0;choice<n;choice++){
        if( ( setOfCities & (1<<choice) ) == 0){

            int subProb = dist[city][choice] + tsp(dist,setOfCities | (1<<choice),choice,n,dp);
            ans = min(ans,subProb);
            
        }
    }
    return dp[setOfCities][city] = ans;
    
}

int main(){
    vector <vector <int>> dist ={
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}
    };
    int n=4;
    vector<vector<int>> dp((1<<n),vector<int>(n,-1));
    cout<<tsp(dist,1,0,n,dp);
    return 0;
}