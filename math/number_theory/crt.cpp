#include <bits/stdc++.h>
using namespace std;

struct Congruence {
    long long a, m;
};

// Extended Euclidean Algorithm
long long extended_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Modular inverse
long long mod_inv(long long a, long long m) {
    long long x, y;
    long long g = extended_gcd(a, m, x, y);
    if (g != 1) throw runtime_error("Modular inverse does not exist");
    return (x % m + m) % m;
}

// Chinese Remainder Theorem
long long chinese_remainder_theorem(vector<Congruence> const& congruences) {
    long long M = 1;
    for (auto const& congruence : congruences) {
        M *= congruence.m;
    }

    long long solution = 0;
    for (auto const& congruence : congruences) {
        long long a_i = congruence.a;
        long long M_i = M / congruence.m;
        long long N_i = mod_inv(M_i, congruence.m);
        solution = (solution + a_i * M_i % M * N_i) % M;
    }
    return (solution % M + M) % M;
}

int main() {
    vector<Congruence> congruences = {
        {2, 3},
        {3, 5},
        {2, 7}
    };

    cout << chinese_remainder_theorem(congruences) << endl; // should print 23
}
