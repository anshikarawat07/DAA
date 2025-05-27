#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> bfs;
    vector<int> vis(V, 0); 
    queue<int> q;

    vis[0] = 1;
    q.push(0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<int> adj[V];

    cout << "Enter " << E << " edges (as pairs u v for undirected graph):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    vector<int> bfs = bfsOfGraph(V, adj);

    cout << "BFS Traversal starting from node 0:\n";
    for (int node : bfs)
        cout << node << " ";
    cout << endl;

    return 0;
}
