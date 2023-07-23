#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*
    APPLICATION OF MERGE SORT
    problem statement: count the number of inversions in an array
    inversion: a pair of indices (i,j) such that i < j and arr[i] > arr[j]
    time complexity: O(nlogn) // we are using sth like merge sort
    space complexity: O(n) and O(logn) for the recursive stack space
    approach: divide and conquer
    1- divide the array into two parts
    2- count the number of inversions in the two parts
    3- count the number of cross inversions when merging the two parts:
        if we find an elemnt from the right part that is smaller than an element from the left part
        then we add the number of elements remaining in the left part to the number of inversions
        because the element from the right part is smaller than all of them
    4- return the sum of the three counts


*/

int mergeAndCountCrossInversions(vector<int> &arr, int s, int e)
{
    // merge the two sorted arrays in the range [s,e] and count the number of cross inversions
    // O(n)
    vector<int> temp;
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int inversionCount = 0;
    while (i <= mid && j <= e)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
            inversionCount += mid - i + 1;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= e)
    {
        temp.push_back(arr[j]);
        j++;
    }

    int k = 0;
    for (int idx = s; idx <= e; idx++)
    {
        arr[idx] = temp[k++];
    }
    return inversionCount;
}

int inversionCount(vector<int> &arr, int s, int e)
{
    // sort the array in the range [s,e]
    // O(nlogn)
    // base case
    if (s >= e)
    {
        return 0;
    }

    // recursive case
    // divide
    int mid = (s + e) / 2;
    int leftInversions = inversionCount(arr, s, mid);
    int rightInversions = inversionCount(arr, mid + 1, e);
    int crossinversions = mergeAndCountCrossInversions(arr, s, e);
    return leftInversions + rightInversions + crossinversions;
}

void solve()
{
    vector<int> v = {0,5,2,3,1,5};

    int inversions = inversionCount(v, 0, v.size() - 1);

    cout << inversions << endl;
}
int32_t main()
{
    // fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}