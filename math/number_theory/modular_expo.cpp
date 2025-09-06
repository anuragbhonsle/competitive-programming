#include <bits/stdc++.h>
using namespace std;

long long modPow(long long a, long long b, long long mod) {
    long long result = 1;
    a = a % mod;

    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b = b / 2;
    }
    return result;
}

int main() {
    cout << "3^200 mod 1000000007 = " << modPow(3, 200, 1000000007) << "\n";
    return 0;
}
