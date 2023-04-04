#include <iostream>
#include <vector>
#include <utility>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void bellman_ford(vector<vector<pair<int, int>>> graph, int src) {
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<int> pred(n, -1);
    vector<int> neg_cycle;
    vector<vector<int>> shortest_path(n + 1);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (auto [v, weight] : graph[u]) {
                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;


                }
            }
        }
    }


    for (int u = 1; u < n; u++) {
        for (auto& [v, weight] : graph[u]) {
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                throw std::runtime_error("Negative cycle lol");
            }
        }


    }
}

int main() {
    int n, m, src;
    cin >> n >> m >> src;
    vector<vector<pair<int, int>>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

     bellman_ford(std::move(graph), src);

    
}