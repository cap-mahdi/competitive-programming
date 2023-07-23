#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    problem statement: find the kth smallest element in the array
    time complexity: O(n) to O(n^2) https://stackoverflow.com/questions/56940793/quickselect-time-complexity-explained
    space complexity: O(n) and O(logn) for the recursive stack space
    approach: divide and conquer
    1-choose a pivot element (for example the last element)
    2-put all the elements smaller than the pivot element to the left of the pivot element
    3-put all the elements greater than the pivot element to the right of the pivot element
    4-if the index of the pivot element is equal to k then return the pivot element
    5-if the index of the pivot element is greater than k then apply the above steps recursively on the left part of the pivot element
    6-if the index of the pivot element is less than k then apply the above steps recursively on the right part of the pivot element    

*/

int partition(vector<int> &arr, int s, int e)
{
    //divide the array into two parts such that all the elements in the left part are smaller than the pivot element and all the elements in the right part are greater than the pivot element
    // O(n)
    int pivot = arr[e];
    int i = s - 1;
    for (int j = s; j < e; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[e]);
    return i + 1;
}

int quickSelect(vector<int> &arr, int s, int e, int k)
{
    //find the kth smallest element in the array
    // O(n) to O(n^2)
    // base case
    if (s >= e)
    {
        return -1;
    }

    // recursive case
    int p = partition(arr, s, e);
    if (p + 1 == k)
    {
        return arr[p];
    }
    else if (p > k)
    {
        return quickSelect(arr, s, p - 1, k);
    }
    else
    {
        return quickSelect(arr, p + 1, e, k);
    }
}

void solve()
{
    vector<int> arr = {10, 5, 2, 0, 7, 6, 4};
    int k = 7;
    cout << quickSelect(arr, 0, arr.size() - 1, k);
}
int32_t main()
{
    // fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}