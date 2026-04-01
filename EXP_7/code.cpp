#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<vector<vector<int>>> adj(n);

        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int cost = flights[i][2];

            adj[u].push_back({v, cost});
        }

        queue<vector<int>> q;
        vector<int> dist(n, INT_MAX);

        dist[src] = 0;
        q.push({src, 0, 0}); // node, cost, stops

        while (!q.empty()) {
            vector<int> arr = q.front();
            q.pop();

            int u = arr[0];
            int w = arr[1];
            int s = arr[2];

            if (s > k) continue;

            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i][0];
                int wt = adj[u][i][1];

                if (w + wt < dist[v]) {
                    dist[v] = w + wt;
                    q.push({v, dist[v], s + 1});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
