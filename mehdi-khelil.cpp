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

class St {
public:
    vector<int> a;
    vector<int> lazy;
    int NEUTRE = 0;//TOCHANGE
    int operation(int a, int b) {
        return a ^ b;//TOCHANGE
    }
    int N;
    St(int v) {
        a.resize(4 * v, NEUTRE);
        lazy.resize(4 * v, NEUTRE);
        N = v;
    };
    int left_child(int node) {
        return 2 * node + 1;
    }
    int right_child(int node) {
        return 2 * node + 2;
    }
    void push(int node) {
        if (left_child(node) < 4 * N)
            lazy[left_child(node)] += lazy[node];
        if (right_child(node) < 4 * N)
            lazy[right_child(node)] += lazy[node];
        a[node] += lazy[node];
        lazy[node] = 0;
    }
    //if not passing as refrence you will get TLE
    void build(vector<int>& b, int node, int l, int r) {
        if (r == l) {
            a[node] = b[l];
            return;
        }
        int m = (l + r) / 2;
        build(b, left_child(node), l, m);
        build(b, right_child(node), m + 1, r);
        a[node] = operation(a[left_child(node)], a[right_child(node)]);
        return;
    }
    int query(int node, int l, int r, int index) {
        if (index > r || index < l)
            return NEUTRE;

        push(node);
        if (l == r)
        {
            return a[node];
        }
        int m = (l + r) / 2;
        if (index <= m)
            return query(left_child(node), l, m, index);
        else
            return query(right_child(node), m + 1, r, index);

    }

    void update(int node, int l, int r, int start, int end, int value) {
        if (end<l || start>r)
            return;

        if (l >= start && r <= end)
        {
            lazy[node] += value;
            return;
        }
        push(node);
        int m = (l + r) / 2;
        update(left_child(node), l, m, start, end, value);
        update(right_child(node), m + 1, r, start, end, value);
        return;
    }

    void build(vector<int>& b) {
        //O(n)
        build(b, 0, 0, N - 1);
    }
    int query(int index) {
        //O(logn)
        return  query(0, 0, N - 1, index);
    }
    void update(int start, int end, int value) {
        //O(logn)
        update(0, 0, N - 1, start, end, value);
    }

};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    St st(n);
    st.build(a);
    while (q--) {
        int b;
        cin >> b;
        if (b == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            l--, r--;
            st.update(l, r, val);
        }
        else {
            int index;
            cin >> index;
            index--;
            cout << st.query(index) << "\n";
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