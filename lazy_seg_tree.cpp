



#include <bits/stdc++.h>
#define ll long long 
using namespace std;


/*lazy seg tree: range updates and range queries*/
struct SegTree {
    //everything is 0 indexed
    /*building segtree
      SegTree st(n);
      st.build(v, 0, 0, n-1);
      v->vector , n= lenght  */
    /* query; st.query(0, 0, n-1,l,r)
       update: st.update(0, 0, n-1,l,r, value)
    */
    int n;
    vector<long long> seg, lazy;
    SegTree(int n) : n(n) {
        seg.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }
    // build from array
    void build(vector<long long> &a, int cur, int l, int r) {
        if(l == r){
            seg[cur] = a[l];
            return;
        }
        int mid = (l+r)/2;
        build(a, 2*cur+1, l, mid);
        build(a, 2*cur+2, mid+1, r);
        seg[cur] = seg[2*cur+1] + seg[2*cur+2];
    }
    // push lazy values down
    void push(int cur, int l, int r) {
        if(lazy[cur] != 0){
            seg[cur] += (r - l + 1) * lazy[cur];
            if(l != r){
                lazy[2*cur+1] += lazy[cur];
                lazy[2*cur+2] += lazy[cur];
            }
            lazy[cur] = 0;
        }
    }
    // range update: add val to [ql, qr]
    void update(int cur, int l, int r, int ql, int qr, long long val) {
        push(cur, l, r);

        if(r < ql || qr < l) return;           // no overlap
        if(ql <= l && r <= qr){                // full overlap
            lazy[cur] += val;
            push(cur, l, r);
            return;
        }
        int mid = (l+r)/2;
        update(2*cur+1, l, mid, ql, qr, val);
        update(2*cur+2, mid+1, r, ql, qr, val);
        seg[cur] = seg[2*cur+1] + seg[2*cur+2];
    }
    // range query: sum of [ql, qr]
    long long query(int cur, int l, int r, int ql, int qr) {
        push(cur, l, r);
        if(r < ql || qr < l) return 0;         // no overlap
        if(ql <= l && r <= qr) return seg[cur]; // full overlap
        int mid = (l+r)/2;
        return query(2*cur+1, l, mid, ql, qr)  
             + query(2*cur+2, mid+1, r, ql, qr);
    }
};




//****************minimum range query with range addition update**************** */


/*lazy seg tree: range add updates and range MIN queries*/
struct SegTree {
    /*  build:
            SegTree st(n);
            st.build(v, 1, 0, n-1);
        query:
            st.query(1,0,n-1,l,r)

        update:
            st.update(1, 0,n-1,l2,r2,value)
        
            that one at query and update are important and also 1 at 2nd index in  build
            all things are 0 indexed
    */
    int n;
    vector<long long> tree, lazy; // tree stores mins, lazy stores pending adds

    SegTree(int n) {
        this->n = n;
        tree.assign(4*n+2, 0);
        lazy.assign(4*n+2, 0);
    }

    void build(vector<long long> &a, int node, int l, int r) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(a, node<<1, l, mid);
        build(a, node<<1|1, mid+1, r);
        tree[node] = min(tree[node<<1], tree[node<<1|1]);
    }

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node];
            if (l != r) {
                lazy[node<<1] += lazy[node];
                lazy[node<<1|1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, long long val) {
        push(node, l, r);
        if (r < ql || qr < l) return;

        if (ql <= l && r <= qr) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }

        int mid = (l + r) >> 1;
        update(node<<1, l, mid, ql, qr, val);
        update(node<<1|1, mid+1, r, ql, qr, val);
        tree[node] = min(tree[node<<1], tree[node<<1|1]);
    }

    long long query(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (r < ql || qr < l) return LLONG_MAX;

        if (ql <= l && r <= qr) return tree[node];

        int mid = (l + r) >> 1;
        return min(
            query(node<<1, l, mid, ql, qr),
            query(node<<1|1, mid+1, r, ql, qr)
        );
    }
};
















