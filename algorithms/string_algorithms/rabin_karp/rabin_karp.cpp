#include <bits/stdc++.h>
using namespace std;

const int p = 31;       // prime base
const int m = 1e9 + 9;  // large prime modulus

vector<int> rabinKarp(const string& s, const string& pat) {
    int n = s.size(), mlen = pat.size();
    long long patHash = 0, power = 1;
    for (char c : pat) {
        patHash = (patHash * p + (c - 'a' + 1)) % m;
        power = (power * p) % m;
    }

    vector<int> res;
    long long hash = 0;
    for (int i = 0; i < n; i++) {
        hash = (hash * p + (s[i] - 'a' + 1)) % m;
        if (i >= mlen) {
            hash = (hash - (s[i - mlen] - 'a' + 1) * power % m + m) % m;
        }
        if (i + 1 >= mlen && hash == patHash) {
            res.push_back(i - mlen + 1);
        }
    }
    return res;
}

int main() {
    string txt = "ababcababa";
    string pat = "ababa";
    auto matches = rabinKarp(txt, pat);
    for (int idx : matches) cout << "Match at index " << idx << "\n";
}
