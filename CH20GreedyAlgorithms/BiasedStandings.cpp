#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    problem :https://www.spoj.com/problems/BAISED/
    statement: In a competition, each team will choose a rank between 1 and N (inclusive), many teams may choose the same rank.
    hte badness of a rank is the absolute value of the difference between the chosen rank and the actual rank of the team.
    The total badness of the competition is the sum of the badness of the ranks chosen by each team.
    The organizers want a competition with a minimum total badness.
    Given the actual ranks of the teams, what is the minimum total badness that can be achieved?

    Input:
    1
    3
    ThreeHeadedMonkey 1
    MoscowSUx13 1
    NeedForSuccess 1
    output:
    3

    Approach: Greedy Approach
    for each team we will choose the rank which is closest possible rank to the actual rank of the team.

    1. Sort the ranks of the teams in ascending order.
    2. in crementing the answer by the absolute difference between the actual rank and the rank we are assigning to the team.

    Time Complexity: O(N)
    Space Complexity: O(N)

    We will use counting sort to sort the ranks of the teams in ascending order. in O(N) time.

*/

void countingSort(int a[],int n,int size){
    //sorting the array in O(N) time.
    
    int freq[n+1] = {0};


    for(int i = 0;i<size;i++){
        freq[a[i]]++;
    }

    for(int i=1;i<=n;i++){
        freq[i]+=freq[i-1];
    }

    int ans[size];
    for(int i = size-1;i>=0;--i){
        ans[freq[a[i]]-1] = a[i];
        freq[a[i]]--;
    }
    for(int i = 0;i<size;i++){
        a[i] = ans[i];
    }
}

void solve(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i<n;i++){
        string ch;
        cin>>ch>>a[i];
    }


    countingSort(a,n+1,n);
    // for(int i = 0;i<n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans+=abs(a[i]-(i+1));
    }
    cout<<ans<<"\n";
}
int32_t main(){
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
/*
2
7
noobz 1
llamas 2
Winn3rz 2
5thwheel 1
NotoricCoders 5
StrangeCase 7
WhoKnows 7
3
ThreeHeadedMonkey 1
MoscowSUx13 1
NeedForSuccess 1



*/