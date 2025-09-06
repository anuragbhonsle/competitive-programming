#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n+1); // node, weight
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // if undirected
    }

    const int INF = 1e9;
    vector<int> dist(n+1, INF);
    dist[1] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});

    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(d != dist[node]) continue;

        for(size_t i = 0; i < adj[node].size(); i++){
            int nbr = adj[node][i].first;
            int w = adj[node][i].second;
            if(dist[node] + w < dist[nbr]){
                dist[nbr] = dist[node] + w;
                pq.push({dist[nbr], nbr});
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << dist[i] << " ";
    cout << "\n";
}
