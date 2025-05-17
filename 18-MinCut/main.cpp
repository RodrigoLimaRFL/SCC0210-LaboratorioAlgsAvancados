#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

long long int minCutMaxFlow(int s, int t, vector<vector<long long int>> &graph) {
    int n = graph.size();
    vector<vector<long long int>> rGraph(n, vector<long long int>(n, 0));

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            rGraph[u][v] = graph[u][v];
        }
    }

    long long int maxFlow = 0;

    while (true) {
        vector<int> parent(n, -1);
        vector<bool> visited(n, false);
        visited[s] = true;

        // BFS to find an augmenting path
        vector<int> queue;
        queue.push_back(s);

        while (!queue.empty()) {
            int u = queue.front();
            queue.erase(queue.begin());

            for (int v = 0; v < n; v++) {
                if (!visited[v] && rGraph[u][v] > 0) {
                    queue.push_back(v);
                    visited[v] = true;
                    parent[v] = u;
                }
            }
        }

        if (!visited[t]) {
            break;
        }

        // Find the maximum flow through the path found
        long long int pathFlow = LLONG_MAX;
        for (int v = t; v != s; v = parent[v]) {
            pathFlow = min(pathFlow, rGraph[parent[v]][v]);
        }

        // update residual capacities of the edges and reverse edges
        for (int v = t; v != s; v = parent[v]) {
            rGraph[parent[v]][v] -= pathFlow;
            rGraph[v][parent[v]] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    while (true) {
        int n, m;

        cin >> n >> m;

        if (n == 0 && m == 0) {
            break;
        }

        // grafo nao direcionado
        vector<vector<long long int>> graph(n, vector<long long int>(n, 0));

        for (int i = 0; i < m; i++) {
            int u, v;
            long long int w;
            cin >> u >> v >> w;

            graph[u - 1][v - 1] = w;
            graph[v - 1][u - 1] = w;
        }

        int s = 0;
        int t = 1;

        long long int minCut = minCutMaxFlow(s, t, graph);

        cout << minCut << endl;
    }
}