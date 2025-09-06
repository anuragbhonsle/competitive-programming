#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited){
    visited[node] = true;
    cout << node << " ";
    for(int nbr: adj[node]){
        if(!visited[nbr]) dfs(nbr, adj, visited);
    }
}

int main() {
    int n,m; cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n+1,false);
    dfs(1, adj, visited);
    cout << "\n";
}
