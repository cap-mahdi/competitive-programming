#include <bits/stdc++.h>
#define int long long int
using namespace std;

//sqrt decomposition for the range sum query
struct sqrtDecompostion {
    //sqrt decomposition is used to perform range queries in O(sqrt(n)) time complexity
    //use segment tree or fenwick tree if you want to perform range queries
    //this is used for Mo's algorithm
    vector<int> blocks;
    vector<int> arr;
    int n;
    int len;
    sqrtDecompostion(vector<int> arr) {
        //O(n) time complexity
        n = arr.size();
        len = sqrt(n) + 1;//at most sqrt(n) + 1 blocks
        blocks.assign(len, 0);//initially all blocks are 0 (NETURAL ELEMENT OF OPERATION)
        for (int i = 0;i < n;i++) {
            //each block will have sqrt(n) elements and will contain SUM of those elements
            blocks[i / len] += arr[i];
        }
        this->arr = arr;

    }
    void update(int idx, int val) {
        //O(1) time complexity (if we use prefix sum array then it will take O(n) time complexity)
        //Replace the value at idx with val
        int blockNumber = idx / len;
        blocks[blockNumber] += val - arr[idx];
    }
    int query(int l, int r) {
        //O(sqrt(n)) time complexity
        //There will be at most 2 blocks which are partially included in the range
        //O(sqrt(n)) + O(2*sqrt(n)) = O(sqrt(n))
        //O(sqrt(n)) -> for completely included blocks
        //O(2*sqrt(n)) -> for the two  partially included blocks
        int sum = 0;//NETURAL ELEMENT OF OPERATION
        for (int i = l;i <= r;) {
            if (i % len == 0 && i + len - 1 <= r) {
                //if i is starting of a block and the block is completely inside the range
                sum += blocks[i / len];
                i += len;
            }
            else {
                //else add elemnt
                sum += arr[i];
                i++;
            }
        }
        return sum;
    }
};

void solve() {
    vector<int> arr = { 1,2,3,4,5,6,7,8,9,10 };
    int n = arr.size();
    sqrtDecompostion sd(arr);
    cout << sd.query(0, 9) << endl;
    sd.update(0, 10);
    cout << sd.query(0, 9) << endl;
    cout << sd.query(0, 4) << endl;
}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}