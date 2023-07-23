#include <bits/stdc++.h>

using namespace std;

/*
    Statement: Given an array of numbers where all numbers except TWO are present TWICE, find the unique numbers.
    so the array will have 2n + 2 elements.
    Approach:
        1. XOR of a number with itself is 0.
        2. XOR of a number with 0 is the number itself.
        3. XOR of all numbers will give the XOR of the two unique numbers.
        4. Find the rightmost set bit in the XOR of the two unique numbers.
        5. Divide the array into two groups based on the rightmost set bit.
        6. XOR of all numbers in on group will give one unique number.
        7. XOR the first unique number with the XOR of all numbers to get the second unique number.
    Complexity:
        Time: O(n)
        Space: O(1)
    Example:
        Input: 1 2 3 4 1 2 3 5 6 6
        Output: 4 5
        */

int*  uniqueNumber(int arr[], int n){
    int xor_cumulative = 0;
    for(int i=0;i<n;i++){
        xor_cumulative = xor_cumulative ^ arr[i];
    }
    
    int temp = xor_cumulative;
    int pos = 0;
    while((temp & 1) != 1){

        pos++;
        temp = temp >> 1;
    }

    int mask = (1 << pos);
    int firstNo = 0;
    for(int i=0;i<n;i++){
        if((arr[i] & mask) != 0){
            firstNo = firstNo ^ arr[i];
        }
    }
    int secondNo = xor_cumulative ^ firstNo;
    return new int[2]{firstNo, secondNo};
}   

int main(){
    int arr[10] = {1, 2, 3, 4, 1, 2, 3, 5, 6, 6};
    int n= 10;
    int *ans = uniqueNumber(arr, n);
    cout << "Unique numbers are: ";
    cout << ans[0] << " " << ans[1] << endl;

    return 0;   
}