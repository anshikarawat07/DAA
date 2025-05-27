#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void prims(vector<pair<int, int>> graph[], int V) {
    vector<int> key(V, INF);
    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});
    key[0] = 0;

    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        if (inMST[node])
            continue;

        inMST[node] = true;

        for (auto edge : graph[node]) {
            int v = edge.first;
            int weight = edge.second;

            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = node;
            }
        }
    }

    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; ++i)
        cout << parent[i] << " - " << i << "\t" << key[i] << endl;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<pair<int, int>> graph[V];

    for (int i = 0; i < E; i++) {
        int x, y, wt;
        cin >> x >> y >> wt;
        graph[x].push_back({y, wt});
        graph[y].push_back({x, wt});
    }

    prims(graph, V);
    return 0;
}
