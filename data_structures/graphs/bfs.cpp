#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n+1,false);
    queue<int> q;
    q.push(1); visited[1]=true;

    while(!q.empty()){
        int node = q.front(); q.pop();
        cout << node << " ";
        for(int nbr: adj[node]){
            if(!visited[nbr]){
                visited[nbr] = true;
                q.push(nbr);
            }
        }
    }
    cout << "\n";
}
