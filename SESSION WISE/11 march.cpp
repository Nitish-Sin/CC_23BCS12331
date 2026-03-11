#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int u, v, weight;
};

void bellmanFord(int start, int n, vector<Edge>& edges) {
    int e = edges.size();
    vector<int> dist(n + 1, INT_MAX);
    dist[start] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (int j = 0; j < e; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int weight = edges[j].weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains a negative weight cycle" << endl;
            return;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " : ";
        if (dist[i] == INT_MAX) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}

int main() {
    int n = 5;
    vector<Edge> edges;

    edges.push_back({1, 2, -1});
    edges.push_back({1, 3, 4});
    edges.push_back({2, 3, 3});
    edges.push_back({2, 4, 2});
    edges.push_back({2, 5, 2});
    edges.push_back({4, 3, 5});
    edges.push_back({4, 2, 1});
    edges.push_back({5, 4, -3});

    bellmanFord(1, n, edges);

    return 0;
}
