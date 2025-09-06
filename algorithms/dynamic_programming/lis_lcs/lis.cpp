#include <bits/stdc++.h>
using namespace std;

// O(n log n) LIS length
int main() {
    int n; cin >> n;
    vector<int> a(n), d;
    for (int i = 0; i < n; i++) { cin >> a[i]; }
    for (int x : a) {
        auto it = lower_bound(d.begin(), d.end(), x);
        if (it == d.end()) d.push_back(x);
        else *it = x;
    }
    cout << (int)d.size() << "\n";
}
