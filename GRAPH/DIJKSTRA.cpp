#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void dijkstra(int V, vector<pair<int, int>> graph[], int source) {
    vector<int> dist(V, INF);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int node = pq.top().second;
        int currentDist = pq.top().first;
        pq.pop();

        if (currentDist > dist[node])
            continue;  

        for (auto edge : graph[node]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "To node " << i << " = ";
        if (dist[i] == INF)
            cout << "∞ (unreachable)";
        else
            cout << dist[i];
        cout << endl;
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<pair<int, int>> graph[V];

    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt}); 
    }

    int source;
    cout << "Enter source node: ";
    cin >> source;

    dijkstra(V, graph, source);
    return 0;
}
