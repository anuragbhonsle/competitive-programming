#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(vector<int> &arr) {
        n = arr.size();
        tree.resize(4*n);
        build(arr, 1, 0, n-1);
    }

    void build(vector<int> &arr, int node, int l, int r){
        if(l==r){
            tree[node] = arr[l];
            return;
        }
        int mid = (l+r)/2;
        build(arr, 2*node, l, mid);
        build(arr, 2*node+1, mid+1, r);
        tree[node] = min(tree[2*node], tree[2*node+1]); // change operation if needed
    }

    void update(int node, int l, int r, int idx, int val){
        if(l==r){
            tree[node] = val;
            return;
        }
        int mid = (l+r)/2;
        if(idx <= mid) update(2*node, l, mid, idx, val);
        else update(2*node+1, mid+1, r, idx, val);
        tree[node] = min(tree[2*node], tree[2*node+1]);
    }

    int query(int node, int l, int r, int ql, int qr){
        if(qr < l || r < ql) return INT_MAX;
        if(ql <= l && r <= qr) return tree[node];
        int mid = (l+r)/2;
        return min(query(2*node, l, mid, ql, qr), query(2*node+1, mid+1, r, ql, qr));
    }
};

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];

    SegmentTree st(arr);

    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if(type==1){
            int idx, val; cin >> idx >> val;
            st.update(1,0,n-1,idx,val);
        } else {
            int l,r; cin >> l >> r;
            cout << st.query(1,0,n-1,l,r) << "\n";
        }
    }
}
