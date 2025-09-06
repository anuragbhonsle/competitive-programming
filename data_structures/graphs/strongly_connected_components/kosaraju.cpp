#include <bits/stdc++.h>
using namespace std;

void dfs1(int u, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st){
    visited[u] = true;
    for(size_t i=0;i<adj[u].size();i++){
        int v = adj[u][i];
        if(!visited[v]) dfs1(v, adj, visited, st);
    }
    st.push(u);
}

void dfs2(int u, vector<vector<int>> &revAdj, vector<bool> &visited){
    visited[u] = true;
    cout << u << " ";
    for(size_t i=0;i<revAdj[u].size();i++){
        int v = revAdj[u][i];
        if(!visited[v]) dfs2(v, revAdj, visited);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1), revAdj(n+1);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }

    vector<bool> visited(n+1,false);
    stack<int> st;
    for(int i=1;i<=n;i++) if(!visited[i]) dfs1(i, adj, visited, st);

    fill(visited.begin(), visited.end(), false);
    cout << "SCCs:\n";
    while(!st.empty()){
        int u = st.top(); st.pop();
        if(!visited[u]){
            dfs2(u, revAdj, visited);
            cout << "\n";
        }
    }
}
