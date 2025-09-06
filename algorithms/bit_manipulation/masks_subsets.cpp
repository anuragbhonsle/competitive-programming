#include <bits/stdc++.h>
using namespace std;

// Generate all subsets of {0,1,...,n-1} using bitmasks
vector<vector<int>> generateSubsets(int n) {
    vector<vector<int>> all;
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) subset.push_back(i);
        }
        all.push_back(subset);
    }
    return all;
}

int main() {
    int n = 3;
    auto subsets = generateSubsets(n);

    cout << "Subsets of {0,1,2}:\n";
    for (auto &s : subsets) {
        cout << "{ ";
        for (int x : s) cout << x << " ";
        cout << "}\n";
    }

    return 0;
}
