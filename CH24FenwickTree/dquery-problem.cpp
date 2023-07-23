#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
Problem:https://www.spoj.com/problems/DQUERY/
Statement: Given an array of n numbers and q queries of the form l r, find the number of distinct elements in the subarray a[l..r]

Solution: We can use fenwick tree to solve this problem (or segment tree but with fenwick tree it is easier to code and more efficient)
1-we sort the queries in increasing order of their right end point
2-for each index i:
    -if a[i] has appeared before, we substract 1 from its last occurence in the fenwick tree (so it becomes 0)
    -we add 1 to the current index i in the fenwick tree (so it becomes 1)
    -we update the last occurence of a[i] to be i
    -if the current index i is equal to the right end point of the current query, we calculate the answer for this query by calculating the sum from l to r in the fenwick tree.(we do that for all queries that have the same right end point)


Example:
a = {1,1,2,3,3,4,1,2,3,4}
we are now at index 4
a[4]=3
last_occurence[3]=3
we substract 1 at position 3 in the fenwick tree(it becomes 0)
we add 1 at position 4 in the fenwick tree(it becomes 1)
the array in the fenwick tree will be : {0,1,1,0,1,0,0,0,0,0}


Complexity: for each index we do at most 2 updates --> O(2*logn*n)
            for each query we do one fenwick query --> O(logn*q)
            total complexity: O( (n+q) * logn)



*/

const int N = 1e6 + 1;
int last_occurence[N];


struct Query {
    int l, r, ans, id;
    bool operator<(Query other) {
        return r < other.r;
    }
};
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
        //calulate the sum from l to r(0 based indexing)
        //O(logn) at most
        return sum(r) - sum(l - 1);
    }

};

void solve() {
    vector<int> a = { 1, 1,2,3,3,4,1,2,3,4 };
    vector<pair<int, int>> q = { {0,4},{1,3},{2,4},{0,9},{5,9},{6,9},{7,9},{8,9},{0,9} };
    vector<Query> queries(q.size());
    for (int i = 0;i < q.size();i++) {
        queries[i].l = q[i].first;
        queries[i].r = q[i].second;
        queries[i].id = i;
    }

    sort(queries.begin(), queries.end());

    fenwick tree;
    tree.init(a.size());
    int k = 0;
    for (int i = 0;i < a.size();i++) {
        if (last_occurence[a[i]]) {
            int j = last_occurence[a[i]];
            tree.add(j - 1, -1);
        }
        tree.add(i, 1);
        last_occurence[a[i]] = i + 1;

        while (k < q.size() && queries[k].r == i) {
            queries[k].ans = tree.sum(queries[k].l, queries[k].r);
            k++;
        }

        if (k == q.size())
            break;


    }
    sort(queries.begin(), queries.end(), [](Query a, Query b) {
        return a.id < b.id;
        });

    for (int i = 0; i < queries.size(); i++) {
        cout << queries[i].l << "->" << queries[i].r << " " << queries[i].ans << endl;
    }

}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}