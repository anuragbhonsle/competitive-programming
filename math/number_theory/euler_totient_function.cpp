#include <bits/stdc++.h>
using namespace std;

// Euler's Totient Function, implementation using factorization in O(sqrt(n))
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            result -= result / i;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}

// This approach is basically identical to the Sieve of Eratosthenes, the complexity will also be the same: O(n log log n)
void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

int main() {
    int n;
    cin >> n;
    cout << phi(n) << "\n"; // prints φ(n)
    return 0;
}
