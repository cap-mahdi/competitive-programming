#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    problem statement:
    Given N activities with their start and finish times. Select the maximum number of activities that can be performed by a single person,
    assuming that a person can only work on a single activity at a time.
    Note : The start time and end time of two activities may coincide.

    see the problem : https://www.spoj.com/problems/BUSYMAN/

    Input:
    3
    3
    3 9
    2 8
    6 9

    4
    1 7
    5 8
    7 8
    1 8

    6
    7 9
    0 10
    4 5
    8 9
    4 10
    5 7
    output:
    1
    2
    3

    Approach: Greedy Approach
    1. Sort the activities according to their finishing time
    2. Select the first activity from the sorted array  and set it as the previous activity and set the count = 1
    3. Do the following for the remaining activities in the sorted array.
        If the start time of this activity is greater than or equal to the finish time of the previously selected activity then select this activity and increment the count of selected activities.

    Time Complexity: O(NlogN)
    Space Complexity: O(N)


*/

bool compare(pair<int, int> act1, pair<int, int> act2)
{

    int e1 = act1.second;
    int e2 = act2.second;
    if (e1 != e2)
    {
        return (e1 < e2);
    }
    return (act1.first < act2.first);
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> act;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        act.push_back({ s, e });
    }
    sort(act.begin(), act.end(), compare);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << act[i].first << " " << act[i].second << "\n";
    int ans = 1;
    int current_end = act[0].second;
    for (int i = 1; i < n; i++)
    {
        if (act[i].first >= current_end)
        {
            ans++;
            current_end = act[i].second;
        }
    }
    cout << ans << "\n";
}
int32_t main()
{
    // fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*

6
7 9
0 10
4 5
8 9
4 10
5 7
*/

