#include <bits/stdc++.h>
using namespace std;

long long extendedGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

long long modInverse(long long a, long long mod) {
    long long x, y;
    long long g = extendedGCD(a, mod, x, y);
    if (g != 1) {
        return -1; // inverse doesn't exist
    }
    return (x % mod + mod) % mod;
}

int main() {
    long long a = 17, mod = 1000000007;
    cout << "Inverse of " << a << " mod " << mod << " = " << modInverse(a, mod) << "\n";
    return 0;
}
