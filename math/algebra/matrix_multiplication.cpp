#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<long long>> Matrix;

Matrix multiply(Matrix &A, Matrix &B) {
    int n = A.size();
    int m = B[0].size();
    int p = B.size();

    Matrix C(n, vector<long long>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main() {
    Matrix A = {{1, 2}, {3, 4}};
    Matrix B = {{5, 6}, {7, 8}};
    Matrix C = multiply(A, B);

    cout << "Result:\n";
    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C[0].size(); j++) {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
