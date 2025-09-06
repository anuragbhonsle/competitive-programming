#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

vector<vector<ll>> mul(const vector<vector<ll>>& A, const vector<vector<ll>>& B) {
    int n = (int)A.size();
    vector<vector<ll>> C(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            for (int j = 0; j < n; j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

int main() {
    int n; cin >> n;
    vector<vector<ll>> A(n, vector<ll>(n)), B(n, vector<ll>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> A[i][j];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> B[i][j];
    auto C = mul(A, B);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << C[i][j] << " ";
        cout << "\n";
    }
}
