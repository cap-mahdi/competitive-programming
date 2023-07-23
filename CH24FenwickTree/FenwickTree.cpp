#include <bits/stdc++.h>
#define int long long int
using namespace std;

//example of a fenwick tree for range sum queries
struct fenwick {
    //It used like segment tree but it is more efficient in terms of space and time
    //it is also called binary indexed tree
    //It has limitations
    //It does not support range updates
    //Advantage: easy to understand and code (it takes only 10 lines of code)
    vector<int> fn;
    int n;

    void init(vector<int> v) {
        this->n = v.size() + 1;//1 based indexing
        fn.resize(this->n, 0);//fill it with Neutral element
        for (int i = 0; i < v.size(); i++) {
            this->add(i, v[i]);
        }
    }

    //THE UPDATE FUNCTION
    void add(int x, int y) {
        //O(logn) at most
        x++; // 1 based index
        while (x < n) {
            fn[x] += y;
            //we add the last set bit (going down in the tree)
            x += (x & (-x));// last set bit
        }
    }

    //THE QUERY FUNCTION
    int sum(int x) {
        //O(logn) at most
        x++; // 1 based index
        int ans = 0;//Neutral element
        while (x) {
            ans += fn[x];
            //we delete the last set bit (going up in the tree)
            x -= (x & (-x));//last set bit
        }
        return ans;
    }

    //THE QUERY FUNCTION
    int sum(int l, int r) {
        //O(logn) at most
        return sum(r) - sum(l - 1);
    }

};

void solve() {
    vector<int> v = { 1, 2, 3, 4, 5, 6, 7 };
    fenwick tree;
    tree.init(v);
    cout << tree.sum(3, 5) << '\n';
    tree.add(4, -3);
    tree.add(2, 2);
    cout << tree.sum(3, 5) << '\n';
}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

