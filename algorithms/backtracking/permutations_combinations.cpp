#include <bits/stdc++.h>
using namespace std;

// Generate all permutations of a vector
void permute(vector<int>& a, int l, int r) {
    if (l == r) {
        for (int x : a) cout << x << " ";
        cout << "\n"; return;
    }
    for (int i = l; i <= r; i++) {
        swap(a[l], a[i]);
        permute(a, l + 1, r);
        swap(a[l], a[i]);
    }
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    permute(a, 0, n - 1);
}
