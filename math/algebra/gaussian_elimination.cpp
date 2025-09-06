#include <bits/stdc++.h>
using namespace std;

// Solve Ax = b using Gaussian elimination
vector<double> gaussianElimination(vector<vector<double>> A, vector<double> b) {
    int n = A.size();

    for (int i = 0; i < n; i++) {
        // Pivot
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(A[k][i]) > fabs(A[maxRow][i])) maxRow = k;
        }
        swap(A[i], A[maxRow]);
        swap(b[i], b[maxRow]);

        // Eliminate
        for (int k = i + 1; k < n; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j < n; j++) {
                A[k][j] -= factor * A[i][j];
            }
            b[k] -= factor * b[i];
        }
    }

    // Back substitution
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
    return x;
}

int main() {
    vector<vector<double>> A = {{2, 1}, {5, 7}};
    vector<double> b = {11, 13};

    vector<double> x = gaussianElimination(A, b);

    cout << "Solution: ";
    for (double val : x) cout << val << " ";
    cout << "\n";
    return 0;
}
