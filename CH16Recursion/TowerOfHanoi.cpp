#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    Problem : Tower of Hanoi
    Given 3 towers and n disks placed on the first tower.
    The task is to move all the disks from the first tower to the third tower in minimum number of moves.
    following these rules:
    1. Only one disk can be moved at a time.
    2. No bigger disk can be placed on the smaller disk.

    Input: N = 2
    Output: move disk 1 from A to B
            move disk 2 from A to C
            move disk 1 from B to C
            3
    
    Approach: Recursion
    how to move n disks from src to dest using helper?
    1. move n-1 disks from src to helper using dest // subproblem that you shoudln't care about
    2. move nth disk from src to dest
    3. move n-1 disks from helper to dest using src



    Time complexity: O(2^n)
    Space complexity: O(n) because of recursion stack and max depth of recursion tree is n


    !!!IMPORTANT!!!
    1. Recursion is a powerful tool but it comes with a cost.
    2. IN THIS EXAMPLE, IT IS CLEAR THAT YOU DON'T CARE ABOUT HOW THE SUBPROBLEM IS SOLVED, AND HOW THE RECURSION IS GONNA WORK

*/

void towerOfHanoi(int n,char src,char helper,char dest){
    //base case
    if(n==0){
        return;
    }
    //recursive case
    towerOfHanoi(n-1,src,dest,helper);
    cout<<src<< "-> "<<dest<<endl;
    towerOfHanoi(n-1,helper,src,dest);
}

void solve(){
    int n;
    cin>>n;
    towerOfHanoi(n,'A','B','C');
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}