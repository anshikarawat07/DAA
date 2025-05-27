#include <bits/stdc++.h>
using namespace std;

void makeSet(int parent[], int rank[], int V) {
    for (int i = 0; i <= V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}
int find(int parent[], int u) {
    if (parent[u] == u)
        return u;
    return parent[u] = find(parent, parent[u]);
}

void unionSets(int u, int v, int parent[], int rank[]) {
    int s1 = find(parent, u);
    int s2 = find(parent, v);
    if (s1 != s2) {
        if (rank[s1] < rank[s2])
            parent[s1] = s2;
        else if (rank[s1] > rank[s2])
            parent[s2] = s1;
        else {
            parent[s2] = s1;
            rank[s1]++;
        }
    }
}

vector<vector<int>> kruskalsMST(int V, vector<vector<int>> &edges) {
    vector<vector<int>> mst;
    int parent[V + 1], rank[V + 1];
    int cost = 0;

    makeSet(parent, rank, V);

    sort(edges.begin(), edges.end()); 

    for (auto edge : edges) {
        int wt = edge[0];
        int u = edge[1];
        int v = edge[2];

        if (find(parent, u) != find(parent, v)) {
            unionSets(u, v, parent, rank);
            cost += wt;
            mst.push_back({wt, u, v});
            if (mst.size() == V - 1)
                break;
        }
    }

    cout << "\nTotal cost of MST: " << cost << "\n";
    return mst;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> edges;

    cout << "Enter edges as: weight u v (for undirected graph)\n";
    for (int i = 0; i < E; ++i) {
        int wt, u, v;
        cin >> wt >> u >> v;
        edges.push_back({wt, u, v});
    }

    vector<vector<int>> mst = kruskalsMST(V, edges);

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (auto edge : mst) {
        cout << edge[1] << " - " << edge[2] << " with weight " << edge[0] << "\n";
    }

    return 0;
}
