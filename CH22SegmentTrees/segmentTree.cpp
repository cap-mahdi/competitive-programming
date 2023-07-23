#include <bits/stdc++.h>
#define int long long int
using namespace std;

//example of segment tree for sum of range
struct segmenttree {
    int n;
    vector<int> st;

    void init(int _n) {
        this->n = _n;
        st.resize(4 * n, INT64_MAX);//TODO: fill it with NEUTRAL ELEMENT(in this case it is 0 for sum)
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

        st[node] = min(st[node * 2 + 1], st[node * 2 + 2]);//TODO: change the operation according to the question (in this case it is sum)
    }

    int query(int start, int ending, int l, int r, int node) {
        // non overlapping case
        if (start > r || ending < l) {
            return INT64_MAX;//TODO: return the NEUTRAL ELEMENT (in this case it is 0 for sum)
        }

        // complete overlap
        if (start >= l && ending <= r) {
            return st[node];
        }

        // partial case
        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return min(q1, q2);//TODO: change the operation according to the question (in this case it is sum)
    }

    void update(int start, int ending, int node, int index, int value) {
        // base case
        if (start == ending) {
            st[node] = value;
            return;
        }

        int mid = (start + ending) / 2;
        if (index <= mid) {
            // left subtree
            update(start, mid, 2 * node + 1, index, value);
        }
        else {
            // right
            update(mid + 1, ending, 2 * node + 2, index, value);
        }

        st[node] = min(st[node * 2 + 1], st[node * 2 + 2]);//TODO: change the operation according to the question (in this case it is sum)

        return;
    }

    void build(vector<int>& v) {
        //build the segment tree from the vector
        //O(n) (4*n is the size of st)
        build(0, n - 1, 0, v);
    }

    int query(int l, int r) {
        //query in range [l,r]
        //O(logn)
        return query(0, n - 1, l, r, 0);
    }

    void update(int x, int y) {
        //update the value at index x to y
        //O(logn) (because logn is the height of the tree)
        update(0, n - 1, 0, x, y);
    }
};


void solve() {
    vector<int> v = { 10,8,5,6,11,26,9,0,3,2,1,4,7 };
    segmenttree st;
    st.init(v.size());
    st.build(v);
    cout << st.query(0, 3) << endl;
    cout << st.query(0, 5) << endl;
    cout << st.query(0, 7) << endl;
    st.update(0, -100);
    st.update(5, 0);
    cout << st.query(0, 3) << endl;
    cout << st.query(4, 5) << endl;
    cout << st.query(0, 7) << endl;


}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}