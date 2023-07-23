#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
    problem :https://www.spoj.com/problems/DEFKIN/

    statement: Given the dimensions of a rectangle in which a king lives
    and n towers,each of them is defined by the coordinates of its cell
    each tower can protect all cells that lie inside the rectangle defined by the leftmost and rightmost tower in the row and the topmost and bottommost tower in the column.
    find the largest unprotected rectangle.

    Input:
    1
    15 8 3
    3 8
    11 2
    8 6

    Output:
    12
    see the problem : https://www.spoj.com/problems/DEFKIN/ to more understand the problem.

    Approach: Greedy Approach.
    the greedy approach is to find the maximum difference between the x coordinates and y coordinates of the towers and multiply them to get the answer.
    1. Sort the x coordinates and y coordinates of the towers including the edges(0 and w+1,h+1)
    2. Find the maximum difference between the x coordinates and y coordinates of the towers.( we will get sizeOfX * sizeOfY of possible udefeated rectangles    )
    3. The answer will be (max_x)*(max_y)

    Time Complexity: O(N) because we use COUNTING SORT to sort the x and y coordinates of the towers.
    Space Complexity: O(N)

*/

void countingSort(int a[], int size, int m, int n)
{
    // sorting the array in O(N) time.
    // assuming the range of the elements in the array is [m,n]

    int freq[n - m + 1] = {0};
    // frequency of each element in the array.
    for (int i = 0; i < size; i++)
    {
        freq[a[i] - m]++;
    }

    // prefix sum array of freq
    for (int i = 1; i <= n - m; i++)
    {
        freq[i] += freq[i - 1];
    }
    int ans[size];
    // from the end of the array to maintain stability,we are using freq[a[i]-m]-1 as the index then decrementing freq[a[i]-m]
    for (int i = size - 1; i >= 0; i--)
    {
        ans[freq[a[i] - m] - 1] = a[i];
        freq[a[i] - m]--;
    }
    // copying the sorted array to the original array.
    for (int i = 0; i < size; i++)
    {
        a[i] = ans[i];
    }
}
void solve()
{
    int w, h, n;
    cin >> w >> h >> n;
    int x[n + 2], y[n + 2];
    x[0] = y[0] = 0;
    x[n + 1] = w + 1;
    y[n + 1] = h + 1;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> x[i] >> y[i];
    }
    countingSort(x, n + 2, 0, w + 1);
    countingSort(y, n + 2, 0, h + 1);
    int maxX = 0;
    int maxY = 0;
    for (int i = 1; i < n + 2; i++)
    {
        maxX = max(maxX, x[i] - x[i - 1] - 1);
        maxY = max(maxY, y[i] - y[i - 1] - 1);
    }

    cout << maxX * maxY << "\n";
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