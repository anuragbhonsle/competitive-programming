#include <bits/stdc++.h>
using namespace std;

// nth Catalan number = C(2n, n) / (n+1)
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) result *= i;
    return result;
}

long long nCr(int n, int r) {
    if (r > n) return 0;
    return factorial(n) / (factorial(r) * factorial(n - r));
}

long long catalan(int n) {
    return nCr(2 * n, n) / (n + 1);
}

int main() {
    int n = 5;
    cout << "Catalan(" << n << ") = " << catalan(n) << "\n";
    return 0;
}
