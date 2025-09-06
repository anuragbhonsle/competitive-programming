#include <bits/stdc++.h>
using namespace std;

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n = 5;
    cout << "Factorial of " << n << " = " << factorial(n) << "\n";
    return 0;
}
