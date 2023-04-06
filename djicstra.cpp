#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();


vector<int> dijkstra(int start, vector<vector<pair<int, int>>>& graph) {

    size_t n = graph.size();
    vector<int> dist(n, INF);


    dist[start] = 0;

    priority_queue < pair<int, int>, vector<pair<int, int>>, less <pair<int, int>> > pq;

    pq.push(make_pair(start, 0));

    while (!pq.empty()) {
        int cur_vertex = pq.top().first;


        pq.pop();

        for (const auto& neighbor : graph[cur_vertex]) {



            const int weight_of_edge = neighbor.second;

            if (dist[cur_vertex] + weight_of_edge < dist[neighbor.first]) {

                dist[neighbor.first] = dist[cur_vertex] + weight_of_edge;

                pq.push(make_pair(neighbor.first, dist[cur_vertex] + weight_of_edge));

            }
        }
    }

    return dist;
}

int main() {
    int n, m, start;
    cin >> n >> m >> start;
   
    vector<vector<pair<int, int>>> graph(n+1);
    vector<vector<int>> shortest_path(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].emplace_back(v, weight);
        
    }
   

    vector<int> dist = dijkstra(start, graph,shortest_path);

    cout << "Shortest distances from node " << start << ":" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << ": " << dist[i] << endl;
    }

    return 0;
}
