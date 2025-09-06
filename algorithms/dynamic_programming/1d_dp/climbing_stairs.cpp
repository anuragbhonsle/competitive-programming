#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    if (n <= 2) { cout << n << "\n"; return 0; }
    long long a = 1, b = 2;
    for (int i = 3; i <= n; i++) {
        long long c = a + b;
        a = b; b = c;
    }
    cout << b << "\n";
}
