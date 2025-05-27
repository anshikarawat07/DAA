#include <bits/stdc++.h>
using namespace std;

void dfsUtil(int node, vector<int> adj[], vector<bool>& visited, vector<int>& result) {
    visited[node] = true;
    result.push_back(node);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, adj, visited, result);
        }
    }
}

vector<int> dfs(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<int> result;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfsUtil(i, adj, visited, result);
        }
    }
    return result;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<int> adj[V];  

    cout << "Enter " << E << " edges :\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  
    }

    vector<int> result = dfs(V, adj);

    cout << " DFS  :"<<endl;
    for (int node : result)
        cout << node << " ";
    cout << endl;

    return 0;
}
