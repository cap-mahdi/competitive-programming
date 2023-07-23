#include <bits/stdc++.h>

using namespace std;

/*
    Statement:
        Given a list of numbers where every number occurs twice except one, find that unique number.
        so the array will have 2n + 1 elements.
    Approach:
        XOR of a number with itself is 0.
        XOR of a number with 0 is the number itself.
        So, XOR of all numbers will give the unique number.
    Complexity:
        Time: O(n)
        Space: O(1)
    Example:
        Input: 1 2 3 4 1 2 3
        Output: 4
*/
int uniqueNmber(int arr[], int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = ans ^ arr[i];
    }
    return ans;
}
int main(){
    int arr[5] = {1, 2, 3, 4, 1};
    int n= 5;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << "Unique number is: ";
    cout << uniqueNmber(arr, n) << endl;

    return 0;
}