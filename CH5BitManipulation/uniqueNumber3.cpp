#include <bits/stdc++.h>

using namespace std;

/*
    Statement:
        Given an array of integers where every integer occurs three(or P) times except for one integer, which only occurs once, find and return the non-duplicated integer.
        so the array will have 3P+ 1 elements.
    Approach:
        1. Create an array of size 64.
        2. Update the array with the sum of the bits of all numbers.
        3. Take the mod of all elements of the array with 3.(P)
        4. Convert the array to decimal.
    Complexity: 
        Time: O(n)
        Space: O(1)
    Example:
        Input: 1 2 3 4 1 2 3 1 2 3
        Output: 4
*/
void updateArray(vector <int> &sumArray, int n){
    int i=0;
    while(n>0){
        sumArray[i] += (n&1);
        i++;
        n = n>>1;
    }
}
int  decimalNumber(vector <int> sumArray){
    int ans = 0;
    for(int i=0;i<64;i++){
        ans += (sumArray[i] * (1<<i));
    }
    return ans;
}

int uniqueNumber(int arr[], int n){
    vector <int> sumArray(64, 0);
    for(int i=0;i<n;i++){
        updateArray(sumArray,arr[i]);
    }
    for(int i=0;i<64;i++){
        sumArray[i] = sumArray[i]%3;//p
    }
    return decimalNumber(sumArray);
}

int main(){
    int arr[10] = {1, 2, 3, 4, 1, 2, 3, 1, 2, 3};
    int n= 10;
    cout << "Unique number is: ";
    cout << uniqueNumber(arr, n) << endl;


    return 0;
}