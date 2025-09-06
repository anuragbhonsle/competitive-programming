#include <bits/stdc++.h>
using namespace std;

int n, diaAns = 0;
vector<vector<int>> adj;

int dfs(int u, int p) {
    int best1 = 0, best2 = 0;
    for (int v : adj[u]) if (v != p) {
        int h = 1 + dfs(v, u);
        if (h > best1) { best2 = best1; best1 = h; }
        else if (h > best2) best2 = h;
    }
    diaAns = max(diaAns, best1 + best2);
    return best1;
}

int main() {
    cin >> n;
    adj.assign(n+1, {});
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << diaAns << "\n";
}
