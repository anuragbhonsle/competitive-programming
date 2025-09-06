#include <bits/stdc++.h>
using namespace std;

// Euler's Totient Function - returns phi(n)
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

int main() {
    int n;
    cin >> n;
    cout << phi(n) << "\n"; // prints φ(n)
    return 0;
}
