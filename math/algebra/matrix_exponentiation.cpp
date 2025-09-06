#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<long long>> Matrix;

Matrix multiply(Matrix &A, Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

Matrix power(Matrix base, long long exp) {
    int n = base.size();
    Matrix result(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++) result[i][i] = 1; // identity

    while (exp > 0) {
        if (exp % 2 == 1) result = multiply(result, base);
        base = multiply(base, base);
        exp /= 2;
    }
    return result;
}

int main() {
    // Fibonacci using matrix exponentiation
    Matrix fib = {{1, 1}, {1, 0}};
    long long n = 10;
    Matrix res = power(fib, n - 1);

    cout << "Fibonacci(" << n << ") = " << res[0][0] << "\n";
    return 0;
}
