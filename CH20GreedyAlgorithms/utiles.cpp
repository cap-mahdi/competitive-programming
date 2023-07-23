//couting Sort
void countingSort(int a[],int size, int m, int n){
    //sorting the array in O(N) time.
    //assuming the range of the elements in the array is [m,n]

    int freq[n-m+1] = {0};
    //frequency of each element in the array.
    for(int i = 0;i<size;i++){
        freq[a[i]-m]++;
    }

    //prefix sum array of freq
    for(int i=1;i<=n-m;i++){
        freq[i]+=freq[i-1];
    }

    int ans[size];
    //from the end of the array to maintain stability,we are using freq[a[i]-m]-1 as the index then decrementing freq[a[i]-m]
    for(int i = size-1;i>=0;--i){
        ans[freq[a[i]-m]-1] = a[i];
        freq[a[i]-m]--;
    }

    //copying the sorted array to the original array.
    for(int i = 0;i<size;i++){
        a[i] = ans[i];
    }

}