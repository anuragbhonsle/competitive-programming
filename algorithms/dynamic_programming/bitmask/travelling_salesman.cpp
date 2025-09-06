#include <bits/stdc++.h>
using namespace std;

// TSP DP (n <= ~20). dist[i][j] must be given.
int main() {
    int n; cin >> n;
    const int INF = 1e9;
    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];

    int N = 1 << n;
    vector<vector<int>> dp(N, vector<int>(n, INF));
    dp[1][0] = 0; // start at 0

    for (int mask = 1; mask < N; mask++) {
        for (int u = 0; u < n; u++) if (dp[mask][u] < INF) {
            for (int v = 0; v < n; v++) if (!(mask & (1 << v))) {
                int nmask = mask | (1 << v);
                dp[nmask][v] = min(dp[nmask][v], dp[mask][u] + dist[u][v]);
            }
        }
    }

    int ans = INF;
    for (int u = 0; u < n; u++) ans = min(ans, dp[N-1][u] + dist[u][0]);
    cout << ans << "\n";
}
