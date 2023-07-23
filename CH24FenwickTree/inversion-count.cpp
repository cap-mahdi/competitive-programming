#include <bits/stdc++.h>
#define int long long int
using namespace std;


/*
    Problem: Given an array of n integers, find the number of inversions in the array.
    Inversion Count for an array indicates – how far (or close) the array is from being sorted.
    Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

    Approach: We can solve this problem using fenwick tree.(or even segment tree)
    1- We will sort the array and store the index of each element in the sorted array.//THAT TRICK IS ALWAYS USED IN QUERY PROBLEMS
    2- We will iterate over the sorted array and for each pair we will count the number of elements in the range [i+1,n-1] that are visited (1 for visited and 0 for not visited)[it like counting the number of elements that are samaller than the current element and are on the right side of the current element] and add it to the answer. and then we will mark the current element as visited.

    At each time we will run query to find the sum and then update the tree.That's why we use fenwick tree.(or segment tree)


    Time Complexity: O(nlogn)
    Space Complexity: O(n)


*/

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

    void init(int n) {
        this->n = n + 1;//1 based indexing
        fn.resize(this->n, 0);//fill it with Neutral element
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
        //calculate the sum in the range [l,r] (0 based indexing)
        //O(logn) at most

        return sum(r) - sum(l - 1);
    }

};





int inversion_count(vector <int> input) {
    //O(nlogn)
    vector<pair<int, int>> v;
    for (int i = 0;i < input.size();i++) {
        v.push_back({ input[i],i });
    }
    sort(v.begin(), v.end());
    // for (auto p : v) {
    //     cout << p.first << " " << p.second << endl;
    // }
    fenwick tree;
    tree.init(v.size());
    int ans = 0;
    for (auto p : v) {
        // cout << p.first << " " << tree.sum(p.second) << endl;
        ans += tree.sum(p.second, v.size() - 1);
        tree.add(p.second, 1);
    }
    return ans;
}

void solve() {
    vector<int> v = { 5,2,4,9,1,8,3,10,6,7,5 };
    cout << inversion_count(v) << endl;
}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}