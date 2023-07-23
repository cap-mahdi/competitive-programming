#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
Problem:https://www.spoj.com/problems/DQUERY/
Statement: Given an array of n numbers and q queries of the form l r, find the number of distinct elements in the subarray a[l..r]

Solution: We can use Mo's algorithm to solve this problem

1-we sort the queries in increasing order of their block number and then increasing order of their right end point
2-for each query we move the left and right pointers to the required positions and with that we are constructing the answer for this query
the left pointer (x) can move at most 2*sqrt(n) times (because the sorting is based on the block number)
the right pointer (y) can move at most n times (because the sorting is based on the right end point)
3-we store the answer for each query in the query structure
4-we sort the queries again based on their id
5-we print the answer for each query


Complexity: O( (n+q) * sqrt(n))



*/

// Mo's algorithm is a technique to process offline queries in O( (n+q) * sqrt(n)) time
// offline queries means that we have all the queries before hand and we want to process them all at once
// online queries means that we have to process each query as soon as we get it

// Structure for the query
struct Query {
    int l, r, ans, block, id;
    bool operator<(const Query& other) const {
        return make_pair(block, r) < make_pair(other.block, other.r);
    }
};

// Global variables
int N = 1e6;
vector<Query> queries;
vector<int> cnt(N, 0);
int distinct = 0;

// Add val to the answer
void add(int val) {
    if (cnt[val] == 0) distinct++; // The answer goes from 0 to 1, so the element is now present
    cnt[val]++;
}

// Remove val from the answer
void remove(int val) {
    cnt[val]--;
    if (cnt[val] == 0) distinct--; // The answer goes from 1 to 0, so the element is no longer present
}

// Mo's algorithm
void MoAlgorithm(vector<int> a, vector<pair<int, int>> q) {
    // O( (n+q) * sqrt(n))
    // q: number of queries, n: size of the array (explained below)
    // a: the actual array
    // q: the queries
    int lengthOfBlock = sqrt(a.size()); // sqrt decomposition
    queries.resize(q.size());
    for (int i = 0; i < q.size(); i++) {
        queries[i].l = q[i].first;
        queries[i].r = q[i].second;
        queries[i].block = queries[i].l / lengthOfBlock;
        queries[i].id = i;
    }
    // Sorting the queries based on the block first and then the right index
    // The query with the lesser block will be processed first
    // The query with the same block and lesser right index will be processed first
    sort(queries.begin(), queries.end());

    int x = 0, y = 0; // 2 pointers

    for (int i = 0; i < queries.size(); i++) {
        int l = queries[i].l, r = queries[i].r;
        // Our goal here is to make x = l and y = r+1 (because x is inclusive and y is exclusive)
        while (x < l) {
            remove(a[x]);
            x++;
        }
        while (x > l) {
            x--;
            add(a[x]);
        }
        while (y <= r) {
            add(a[y]);
            y++;
        }
        while (y > r + 1) {
            y--;
            remove(a[y]);
        }
        queries[i].ans = distinct; // Calculate the answer
    }

    // Sorting the queries based on the id
    sort(queries.begin(), queries.end(), [](Query a, Query b) {
        return a.id < b.id;
        });

    // Printing the answer
    for (int i = 0; i < queries.size(); i++) {
        cout << queries[i].l << "->" << queries[i].r << " " << queries[i].ans << endl;
    }
}

void solve() {
    /*
    1 1 2 3 3 4 1 2 3 4
    0 1 2 3 4 5 6 7 8 9

    */
    vector<int> a = { 1, 1,2,3,3,4,1,2,3,4 };
    vector<pair<int, int>> q = { {0,4},{1,3},{2,4},{0,9},{5,9},{6,9},{7,9},{8,9},{0,9} };
    MoAlgorithm(a, q);

}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}



/*
Explanation of time complexity
Let n be the size of the array and q be the number of queries
The time complexity of the algorithm is O( (n+q) * sqrt(n))
O(2* q * logq) for sorting the queries 2 times

y pointer
for each block y will begin from the smallest right index of a query to the biggest right index of a query
so for each block y will move at most n times (the benefit of sorting queries based on the right index)
and sqrt(n) is the number of blocks
so y will move at most n * sqrt(n) times



x pointer
for 2 consecutive queries the x pointer will move at most 2*sqrt(n) times (the benefit of sorting queries based on the block first )
(worst case is that the l of the first query is at the beginning of the block and the r of the second query is at the end of the block)
we have q queries so x will move at most sqrt(n) * q times


final complexity is O(2* q * logq + n * sqrt(n) + sqrt(n) * q + sqrt(n) * q) = O( (n+q) * sqrt(n))


*/