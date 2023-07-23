#include <bits/stdc++.h>
#define int long long int
using namespace std;
/*
    problem statement: find the maximum of a parabola in the range [s,e]
    approach: ternary search (like binary search but we divide the range into three parts instead of two) 

    Binary search: n --> n/2 --> n/4 --> n/8 --> ... --> 1
    Ternary search: n --> 2n/3 --> 4n/9 --> 8n/27 --> ... --> 1

    time complexity: O(log(3/2)n)
    space complexity: O(1)
    approach: divide and conquer
    1- divide the range into three parts [l,mid1] [mid1,mid2] [mid2,r]
    2- if f(mid1) < f(mid2) then the maximum is in the range [mid1,r]
    3- else the maximum is in the range [l,mid2]
    4- repeat the process until the range is small enough
    5- return the maximum of the range


*/

double parabola(double x)
{
    return x * x - 12 * x + 11;
}

double ternarySeachForMax(double s, double e)
{
    // find the maximum of the parabola in the range [s,e]
    // O(log(3/2)n)
    double eps = 1e-6;
    while (e - s > eps)
    {
        double mid1 = s + (e - s) / 3;
        double mid2 = e - (e - s) / 3;
        if (parabola(mid1) < parabola(mid2))
        {
            s = mid1;
        }
        else
        {
            e = mid2;
        }
    }
    return s;
}

double ternarySeachForMin(double s, double e)
{
    // find the minimum of the parabola in the range [s,e]
    // O(log(3/2)n)
    double eps = 1e-6;
    // cout<< setprecision(10)<<fixed; if you fixed it to 10 decimal places you won't get 6 
    while (e - s > eps)
    {
        // cout << s << " " << e << " " << e-s << " " << (e-s)/3 << endl;
        double mid1 = s + (e - s) / 3;
        double mid2 = e - (e - s) / 3;
        if (parabola(mid1) < parabola(mid2))
        {
            e = mid2;
        }
        else
        {
            s = mid1;
        }
    }
    return s;
}

int ternarySeach(vector<int> arr, int s, int e)
{
    // find the maximum of the array in the range [s,e],this array should increase then decrease
    // O(log(3/2)n)
    while(s <= e){
        int mid1 = s + (e - s) / 3;
        int mid2 = e - (e - s) / 3;
        if(arr[mid1] < arr[mid2]){
            s = mid1 + 1;
        }
        else{
            e = mid2 - 1;
        }
    }
    return arr[s];
}

void solve()
{
    vector<int> arr = {0, 5, 10, 8, 7, 6, 4, 3, 2, 1};
    vector<int> arr2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 10};
    vector<int> arr3 = {10, 8, 7, 6, 4, 3, 2, 1, 0};
    
    cout << ternarySeach(arr, 0, arr.size() - 1) << endl;
    cout << ternarySeach(arr2, 0, arr2.size() - 1) << endl;
    cout << ternarySeach(arr3, 0, arr3.size() - 1) << endl;

    cout << ternarySeachForMax(0, 10) << endl;
    cout << ternarySeachForMin(0, 10) << endl;
}
int32_t main()
{
    // fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}