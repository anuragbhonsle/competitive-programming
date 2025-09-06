#include <bits/stdc++.h>
using namespace std;

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) result *= i;
    return result;
}

long long nCr(int n, int r) {
    if (r > n) return 0;
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int n = 5, r = 2;
    cout << "nCr(" << n << "," << r << ") = " << nCr(n, r) << "\n";
    return 0;
}
