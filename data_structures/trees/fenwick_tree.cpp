#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    int n;
    vector<int> bit;

    FenwickTree(int size){
        n = size;
        bit.assign(n+1, 0);
    }

    void add(int idx, int val){
        idx++; // 1-indexed internally
        while(idx <= n){
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int sum(int idx){
        idx++;
        int res = 0;
        while(idx>0){
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }

    int rangeSum(int l, int r){
        return sum(r) - sum(l-1);
    }
};

int main(){
    int n; cin >> n;
    FenwickTree ft(n);

    int q; cin >> q;
    while(q--){
        int type; cin >> type;
        if(type==1){ // add
            int idx,val; cin >> idx >> val;
            ft.add(idx,val);
        } else { // sum query
            int l,r; cin >> l >> r;
            cout << ft.rangeSum(l,r) << "\n";
        }
    }
}
