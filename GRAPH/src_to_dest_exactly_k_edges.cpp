#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int to;
    int weight;
};

int minDist = INT_MAX;

// DFS to find shortest path with exactly k edges
void dfs(int u, int dest, int k, int currWeight, const vector<vector<Edge>>& graph) {
    if (k == 0) {
        if (u == dest) {
            if (currWeight < minDist)
                minDist = currWeight;
        }
        return;
    }
    for (const Edge& e : graph[u]) {
        if (currWeight + e.weight >= minDist) continue; // prune longer paths
        dfs(e.to, dest, k - 1, currWeight + e.weight, graph);
    }
}

int main() {
    int V;
    cin >> V;

    vector<vector<int>> adj(V, vector<int>(V));
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> adj[i][j];

    int src_input, dest_input, k;
    cin >> src_input >> dest_input >> k;

    int src = src_input - 1;  // convert to zero-based index
    int dest = dest_input - 1;

    // Build adjacency list
    vector<vector<Edge>> graph(V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j] != 0) {
                graph[i].push_back({j, adj[i][j]});
            }
        }
    }

    dfs(src, dest, k, 0, graph);

    if (minDist == INT_MAX)
        cout << "No path with exactly " << k << " edges from (" << src_input << "," << dest_input << ")\n";
    else
        cout << "Weight of shortest path from (" << src_input << "," << dest_input << ") with " << k << " edges : " << minDist << "\n";

    return 0;
}
