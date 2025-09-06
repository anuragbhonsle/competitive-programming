#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    long long a = 56, b = 98;
    cout << "gcd(" << a << "," << b << ") = " << gcd(a, b) << "\n";
    cout << "lcm(" << a << "," << b << ") = " << lcm(a, b) << "\n";
    return 0;
}

