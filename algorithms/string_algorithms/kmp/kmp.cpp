#include <bits/stdc++.h>
using namespace std;

// Build LPS (Longest Prefix Suffix) array
vector<int> buildLPS(const string& pat) {
    int n = pat.size();
    vector<int> lps(n);
    int len = 0, i = 1;
    while (i < n) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
        } else if (len != 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

vector<int> KMPSearch(const string& txt, const string& pat) {
    vector<int> res;
    vector<int> lps = buildLPS(pat);
    int i = 0, j = 0;
    while (i < txt.size()) {
        if (txt[i] == pat[j]) {
            i++, j++;
            if (j == pat.size()) {
                res.push_back(i - j);
                j = lps[j - 1];
            }
        } else if (j > 0) {
            j = lps[j - 1];
        } else i++;
    }
    return res;
}

int main() {
    string txt = "abxabcabcaby", pat = "abcaby";
    auto matches = KMPSearch(txt, pat);
    for (int idx : matches) cout << "Found at index " << idx << "\n";
}
