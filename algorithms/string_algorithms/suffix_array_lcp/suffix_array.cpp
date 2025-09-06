#include <bits/stdc++.h>
using namespace std;

// Build suffix array in O(n log n)
vector<int> buildSuffixArray(const string& s) {
    int n = s.size();
    vector<int> sa(n), rank(n);
    for (int i = 0; i < n; i++) sa[i] = i, rank[i] = s[i];
    
    for (int k = 1; k < n; k *= 2) {
        auto cmp = [&](int i, int j) {
            if (rank[i] != rank[j]) return rank[i] < rank[j];
            int ri = i + k < n ? rank[i + k] : -1;
            int rj = j + k < n ? rank[j + k] : -1;
            return ri < rj;
        };
        sort(sa.begin(), sa.end(), cmp);
        vector<int> tmp(n);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        rank = tmp;
        if (rank[sa[n - 1]] == n - 1) break;
    }
    return sa;
}

// Build LCP array in O(n)
vector<int> buildLCP(const string& s, const vector<int>& sa) {
    int n = s.size(), k = 0;
    vector<int> rank(n), lcp(n - 1);
    for (int i = 0; i < n; i++) rank[sa[i]] = i;
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) { k = 0; continue; }
        int j = sa[rank[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[rank[i]] = k;
        if (k) k--;
    }
    return lcp;
}

int main() {
    string s = "banana";
    auto sa = buildSuffixArray(s);
    auto lcp = buildLCP(s, sa);

    cout << "Suffix Array: ";
    for (int idx : sa) cout << idx << " ";
    cout << "\nLCP: ";
    for (int len : lcp) cout << len << " ";
    cout << "\n";
}
