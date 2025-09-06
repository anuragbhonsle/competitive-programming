#include <bits/stdc++.h>
using namespace std;

// multinomial(n; k1, k2, ..., km) = n! / (k1! * k2! * ... * km!)
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) result *= i;
    return result;
}

long long multinomial(vector<int> parts) {
    int n = 0;
    for (int x : parts) n += x;

    long long numerator = factorial(n);
    long long denominator = 1;
    for (int x : parts) denominator *= factorial(x);

    return numerator / denominator;
}

int main() {
    vector<int> parts = {2, 2, 1}; // Example: ways to arrange AABBC
    cout << "Multinomial coefficient = " << multinomial(parts) << "\n";
    return 0;
}
