#include <bits/stdc++.h>
using namespace std;

struct Edge { int u, v, w; };

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for(int i=0;i<m;i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;

    const int INF = 1e9;
    vector<int> dist(n+1, INF);
    dist[1] = 0;

    for(int i=1;i<=n-1;i++){
        for(int j=0;j<m;j++){
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if(dist[u] != INF && dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
            }
        }
    }

    // Check for negative cycles
    bool hasNegCycle = false;
    for(int j=0;j<m;j++){
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if(dist[u] != INF && dist[u]+w < dist[v]){
            hasNegCycle = true;
            break;
        }
    }

    if(hasNegCycle) cout << "Negative cycle detected\n";
    else for(int i=1;i<=n;i++) cout << dist[i] << " ";
}
