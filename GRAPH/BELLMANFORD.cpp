#include <iostream>
#include <vector>
using namespace std;

#define INF 1e9

void bellman(vector<vector<int>> graph, int V) {
    vector<int> dist(V, INF);
    vector<int> parent(V, -1);
    dist[0] = 0; 

    for (int i = 0; i < V - 1; i++) {
        for (auto it : graph) {
            int wt = it[2];
            int x = it[0];
            int y = it[1];
            if (dist[x] != INF && dist[x] + wt < dist[y]) {
                dist[y] = dist[x] + wt;
                parent[y] = x;
            }
        }
    }

    for (auto it : graph) {
        int wt = it[2];
        int x = it[0];
        int y = it[1];
        if (dist[x] != INF && dist[x] + wt < dist[y]) {
            cout << "Negative cycle detected\n";
            return;
        }
    }

    // Print distances
    cout << "\nShortest distances from source 0:\n";
    for (int i = 0; i < V; i++) {
        cout << "To vertex " << i << " : ";
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> graph;

    cout << "Enter edges in format: from to weight\n";
    for (int i = 0; i < E; i++) {
        int from, to, wt;
        cin >> from >> to >> wt;
        graph.push_back({from, to, wt});
    }

    bellman(graph, V);

    return 0;
}
