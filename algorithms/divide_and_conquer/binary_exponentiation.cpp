#include <bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long e, long long mod) {
    long long res = 1 % mod;
    a %= mod;
    while (e > 0) {
        if (e & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return res;
}

int main() {
    long long a, e, m; cin >> a >> e >> m;
    cout << binpow(a, e, m) << "\n";
}
