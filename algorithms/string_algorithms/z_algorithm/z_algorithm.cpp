#include <bits/stdc++.h>
using namespace std;

// Z-function: computes length of longest substring starting at i
// which is also prefix of s
vector<int> Zfunction(const string& s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    string s = "aabxaabxcaabxaabxay";
    auto z = Zfunction(s);
    for (int i = 0; i < s.size(); i++) cout << z[i] << " ";
    cout << "\n";
}
