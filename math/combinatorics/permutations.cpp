#include <bits/stdc++.h>
using namespace std;

// nPr = n! / (n-r)!
long long nPr(int n, int r) {
    if (r > n) return 0;
    long long result = 1;
    for (int i = 0; i < r; i++) {
        result *= (n - i);
    }
    return result;
}

int main() {
    int n = 5, r = 3;
    cout << "nPr(" << n << "," << r << ") = " << nPr(n, r) << "\n";
    return 0;
}
