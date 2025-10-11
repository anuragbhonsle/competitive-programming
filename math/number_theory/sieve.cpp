#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {
    vector<int> primes;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return primes;
}

int main() {
    int n;
    cin >> n;
    vector<int> primes = sieve(n);

    cout << "Primes up to " << n << ": ";
    for (int i = 0; i < (int)primes.size(); i++) {
        cout << primes[i] << " ";
    }
    cout << "\n";
    return 0;
}

// Also The T-prime solution is literally just a Sieve of Eratosthenes + is perfect square check.
// A T-prime is a number that has exactly 3 divisors (1, p, p²).
// So for each number x in the array:
//   1. Check if x is a perfect square → sqrt(x) * sqrt(x) == x.
//   2. Then check if sqrt(x) itself is prime.
// That’s it. That’s the entire trick.

