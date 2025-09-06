#include <bits/stdc++.h>
using namespace std;

const int LOG = 20;
vector<vector<int>> up;
vector<int> depth;
vector<vector<int>> adj;

void dfs(int u, int p){
    up[u][0] = p;
    for(int i=1;i<LOG;i++) up[u][i] = up[up[u][i-1]][i-1];
    for(size_t i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(v != p){
            depth[v] = depth[u]+1;
            dfs(v,u);
        }
    }
}

int lca(int u, int v){
    if(depth[u]<depth[v]) swap(u,v);
    for(int i=LOG-1;i>=0;i--) if(depth[u]-(1<<i) >= depth[v]) u = up[u][i];
    if(u==v) return u;
    for(int i=LOG-1;i>=0;i--){
        if(up[u][i] != up[v][i]){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int main(){
    int n; cin>>n;
    adj.assign(n+1, vector<int>());
    depth.assign(n+1,0);
    up.assign(n+1, vector<int>(LOG));

    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,1);

    int q; cin>>q;
    while(q--){
        int u,v; cin>>u>>v;
        cout << lca(u,v) << "\n";
    }
}
