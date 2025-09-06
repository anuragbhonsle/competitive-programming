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
    int n = 50;
    vector<int> primes = sieve(n);

    cout << "Primes up to " << n << ": ";
    for (int i = 0; i < (int)primes.size(); i++) {
        cout << primes[i] << " ";
    }
    cout << "\n";
    return 0;
}
