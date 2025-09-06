#include <bits/stdc++.h>
using namespace std;

// Example: subtree sizes
int n;
vector<vector<int>> adj;
vector<int> sub;

void dfs(int u, int p) {
    sub[u] = 1;
    for (int v : adj[u]) if (v != p) {
        dfs(v, u);
        sub[u] += sub[v];
    }
}

int main() {
    cin >> n;
    adj.assign(n+1, {});
    sub.assign(n+1, 0);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) cout << sub[i] << " ";
    cout << "\n";
}
