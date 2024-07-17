#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
#define int long long int
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;

void no() {
    cout << "NO" << "\n";
}
void yes() {
    cout << "YES" << "\n";
}
//example of segment tree for sum of range
struct segmenttree {
    //we use this structure in case we have an array and multiple queries and after each query we have to update an element of an array 
    int n;
    vector<int> st;
    vector<int> lazySum;
    vector<int> lazyFix;

    void init(int _n) {
        this->n = _n;
        st.resize(4 * n, 0);//TODO: fill it with IDENTITY ELEMENT(in this case it is 0 for sum)
        lazySum.resize(4 * n, 0);//TODO: fill it with IDENTITY ELEMENT(in this case it is 0 for sum)
        lazyFix.resize(4 * n, 0);//TODO: fill it with IDENTITY ELEMENT(in this case it is 0 for sum)
    }

    void build(int start, int ending, int node, vector<int>& v) {
        // leaf node base case
        if (start == ending) {
            st[node] = v[start];
            return;
        }

        int mid = (start + ending) / 2;

        // left subtree is (start,mid)
        build(start, mid, 2 * node + 1, v);

        // right subtree is (mid+1,ending)
        build(mid + 1, ending, 2 * node + 2, v);

        st[node] = st[node * 2 + 1] + st[node * 2 + 2];//TODO: change the operation according to the question (in this case it is sum)
    }

    int query(int start, int ending, int l, int r, int node) {
        // non overlapping case
        if (start > r || ending < l) {
            return 0;//TODO: return the IDENTITY ELEMENT (in this case it is 0 for sum)
        }
        if (lazySum[node] != 0) {
            st[node] += (r - l + 1) * lazySum[node];
            lazySum[2 * node + 1] = lazySum[node];
            lazySum[2 * node + 2] = lazySum[node];
            lazySum[node] = 0;
        }

        // complete overlap
        if (start >= l && ending <= r) {
            return st[node];
        }

        // partial case
        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return q1 + q2;//TODO: change the operation according to the question (in this case it is sum)
    }

    void updateSum(int l, int r, int node, int s, int e, int value) {

        if (lazySum[node] != 0) {
            st[node] += (r - l + 1) * lazySum[node];
            lazySum[2 * node + 1] = lazySum[node];
            lazySum[2 * node + 2] = lazySum[node];
            lazySum[node] = 0;
        }
        // base case
        if (l > e || r < s) return;

        if (l >= s && r <= e) {
            st[node] += (r - l + 1) * value;
            lazySum[2 * node + 1] += value;
            lazySum[2 * node + 2] += value;
            return;
        }
        int m = (l + r) / 2;
        updateSum(2 * node + 1, l, m, s, e, value);
        updateSum(2 * node + 2, m + 1, r, s, e, value);
        st[node] = st[node * 2 + 1] + st[node * 2 + 2];//TODO: change the operation according to the question (in this case it is sum)

        return;
    }
    void updateFixed(int l, int r, int node, int s, int e, int value) {

        if (lazyFix[node] != 0) {
            st[node] += (r - l + 1) * lazySum[node];
            lazySum[2 * node + 1] = lazySum[node];
            lazySum[2 * node + 2] = lazySum[node];
            lazySum[node] = 0;
        }
        // base case
        if (l > e || r < s) return;

        if (l >= s && r <= e) {
            st[node] = (r - l + 1) * value;
            lazyFix[2 * node + 1] = value;
            lazyFix[2 * node + 2] = value;
            return;
        }
        int m = (l + r) / 2;
        updateSum(2 * node + 1, l, m, s, e, value);
        updateSum(2 * node + 2, m + 1, r, s, e, value);
        st[node] = st[node * 2 + 1] + st[node * 2 + 2];//TODO: change the operation according to the question (in this case it is sum)

        return;
    }
    void build(vector<int>& v) {
        // O(n)
        build(0, n - 1, 0, v);
    }

    int query(int l, int r) {
        // O(logn)
        return query(0, n - 1, l, r, 0);
    }

    void updateSum(int l, int r, int x) {
        // O(logn)
        updateSum(0, n - 1, 0, l, r, x);
    }

    void updateFixed(int l, int r, int x) {
        // O(logn)
        updateFixed(0, n - 1, 0, l, r, x);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    segmenttree st;
    st.init(n);
    st.build(a);
    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        type;l--;r--;
        if (type == 3) {
            cout << st.query(l, r) << "\n";
            continue;
        }
        if (type == 1) {
            int x;
            cin >> x;
            st.updateSum(l, r, x);
        }
    }

}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif


    solve();
    return 0;
}