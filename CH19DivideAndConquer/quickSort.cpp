#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*
    problem statement: sort an array using quick sort
    time complexity: O(nlogn) but in worst case it is O(n^2) when the array is already sorted
    space complexity: O(n) and O(logn) for the recursive stack space
    approach: divide and conquer
    1-choose a pivot element (for example the last element)
    2-put all the elements smaller than the pivot element to the left of the pivot element
    3-put all the elements greater than the pivot element to the right of the pivot element
    4-apply the above steps recursively on the left and right parts of the pivot element
    5-when the left and right parts have only one element then the array is sorted
    6-merge the left and right parts


*/

int partition(vector<int> &arr, int s, int e)
{
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
void quickSort(vector<int> &arr, int s, int e)
{
    //sort the array in the range [s,e]
    // O(nlogn) to O(n^2)
    // base case
    if (s >= e)
    {
        return;
    }

    // recursive case
    // divide
    int p = partition(arr, s, e); // return the index of the pivot element placed in the correct position
    // conquer
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

void solve()
{
    vector<int> arr = {10, 5, 2, 0, 7, 6, 4};

    quickSort(arr, 0, arr.size() - 1);
    for (auto x : arr)
    {
        cout << x << " ";
    }
}
int32_t main()
{
    // fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}