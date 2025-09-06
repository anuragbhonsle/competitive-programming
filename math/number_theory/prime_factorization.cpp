#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> primeFactorization(int n) {
    vector<pair<int,int>> factors;

    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            int count = 0;
            while (n % p == 0) {
                n /= p;
                count++;
            }
            factors.push_back(make_pair(p, count));
        }
    }
    if (n > 1) {
        factors.push_back(make_pair(n, 1));
    }
    return factors;
}

int main() {
    int n = 360;
    vector<pair<int,int>> factors = primeFactorization(n);

    cout << "Prime factors of " << n << ": ";
    for (int i = 0; i < (int)factors.size(); i++) {
        cout << factors[i].first << "^" << factors[i].second << " ";
    }
    cout << "\n";
    return 0;
}

