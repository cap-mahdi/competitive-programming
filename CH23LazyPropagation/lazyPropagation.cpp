#include <bits/stdc++.h>
#define int long long int
using namespace std;

struct segmentTreeWithLazyPropagation {
    //we use this structure in case we have an array and multiple queries and after each query we have to update a range of array 
    int n;
    vector<int> st, lazy;

    void init(int _n) {
        this->n = _n;
        st.resize(4 * n, 0);//TODO: fill the st with the ELEMENT NEUTRAL for the operation.(in this case it is 0 for the sum)
        lazy.resize(4 * n, 0);//TODO: fill the lazy with the ELEMENT NEUTRAL for the operation.(in this case it is 0 for the sum)
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

        st[node] = st[node * 2 + 1] + st[node * 2 + 2];//TODO: change the operation according to the problem (in this case it is sum)
    }

    int query(int start, int ending, int l, int r, int node) {
        // non overlapping case
        if (start > r || ending < l) {
            return 0;//TODO: return the ELEMENT NEUTRAL for the operation.(in this case it is 0 for the sum)
        }

        // lazy propagation / clear the lazy update
        if (lazy[node] != 0) {//TODO: compare with the ELEMENT NEUTRAL for the operation.(in this case it is 0 for the sum)
            // pending updates
            // update the segment tree node
            //TODO: change the operation according to what he is doing in the range update (in this case it is adding same value to all the elements in the range)
            st[node] += lazy[node] * (ending - start + 1);//3andou dayn lzem ikahlsou que ce soit ken bech yetla3 houwa complete case wla 9bal mayebaath el wledou
            if (start != ending) {
                // propagate the updated value
                //TODO: change the operation according to the problem (in this case the lazy contains the value to be added to all the elements in the range)
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;//TODO: assign the ELEMENT NEUTRAL for the operation.(in this case it is 0 for the sum)
        }

        // complete overlap
        if (start >= l && ending <= r) {
            return st[node];
        }

        // partial case
        int mid = (start + ending) / 2;

        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, ending, l, r, 2 * node + 2);

        return q1 + q2;//TODO: change the operation according to the problem (in this case it is sum)
    }

    void update(int start, int ending, int node, int l, int r, int value) {
        // lazy propagation / clear the lazy update
        if (lazy[node] != 0) {//TODO: compare with the ELEMENT NEUTRAL for the operation.(in this case it is 0 for the sum)
            // pending updates
            // update the segment tree node
            //TODO: change the operation according to what he is doing in the range update (in this case it is adding same value to all the elements in the range)
            st[node] += lazy[node] * (ending - start + 1);//we can not do this in case of partial case be cause we will update this value at the end of the function
            if (start != ending) {
                // propagate the updated value
                //TODO: change the operation according to the problem (in this case the lazy contains the value to be added to all the elements in the range)
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;//TODO: assign the ELEMENT NEUTRAL for the operation.(in this case it is 0 for the sum)
        }

        // non overlapping case
        if (start > r || ending < l) {
            return;
        }

        // complete overlap
        if (start >= l && ending <= r) {
            // update the segment tree node
            st[node] += value * (ending - start + 1);//TODO: change the operation according to what he is doing in the range update (in this case it is adding same value to all the elements in the range)
            if (start != ending) {
                // propagate the updated value
                //TODO: change the operation according to the problem (in this case the lazy contains the value to be added to all the elements in the range)
                lazy[2 * node + 1] += value;
                lazy[2 * node + 2] += value;
            }
            return;
        }

        // partial case
        int mid = (start + ending) / 2;

        update(start, mid, 2 * node + 1, l, r, value);
        update(mid + 1, ending, 2 * node + 2, l, r, value);

        st[node] = st[node * 2 + 1] + st[node * 2 + 2];//TODO: change the operation according to the problem (in this case it is sum)
    }

    void build(vector<int>& v) {
        //O(n)
        build(0, n - 1, 0, v);
    }

    int query(int l, int r) {
        //O(logn)
        return query(0, n - 1, l, r, 0);
    }

    void update(int l, int r, int value) {
        //O(logn), it is know to close to query implementation not like the simple segment tree
        update(0, n - 1, 0, l, r, value);
    }
};

void solve() {
    vector <int> v = { 2,3,4,5,6,7,8,9 };
    segmentTreeWithLazyPropagation st;
    st.init(v.size());
    st.build(v);
    cout << st.query(0, 7) << endl;
    st.update(2, 5, 6);
    cout << st.query(3, 6) << endl;
    st.update(1, 3, 2);
    cout << st.query(2, 4) << endl;
}
int32_t main() {
    //fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

