#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w}); // undirected
    }

    const int INF = 1e9;
    vector<int> key(n+1, INF), parent(n+1, -1);
    vector<bool> inMST(n+1, false);
    key[1] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});

    long long mstCost = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        if(inMST[u]) continue;
        inMST[u] = true;
        mstCost += key[u];

        for(size_t i=0;i<adj[u].size();i++){
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            if(!inMST[v] && w < key[v]){
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout << "MST cost: " << mstCost << "\n";
}
