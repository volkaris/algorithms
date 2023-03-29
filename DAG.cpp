#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;





auto topologicalSort(vector<vector<pair<int64_t, int64_t>>>& graph, vector<int>& inDegree) {
    auto n = graph.size();
    queue<int64_t> q;
    vector<int> result;


    for (size_t i = 1; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }


    while (!q.empty()) {
        int64_t curr = q.front();
        q.pop();
        result.push_back(curr);

        for (const auto& neighbor : graph[curr]) {
            inDegree[neighbor.first]--;
            if (inDegree[neighbor.first] == 0) {
                q.push(neighbor.first);
            }
        }
    }


    return result;

}


void DAG(const vector<vector<pair<int64_t, int64_t>>>& graph, vector<int64_t>& distance, vector<int>& top_sort_order, vector<vector<int>>& shortest_path) {


    for (const auto& u : top_sort_order) {

        for (const auto& v : graph[u]) {
            if (distance[v.first] > distance[u] + v.second) {
                distance[v.first] = distance[u] + v.second;
                if (shortest_path[v.first].empty()) {
                    shortest_path[v.first].emplace_back(u);
                }
                else {
                    shortest_path[v.first].clear();
                    shortest_path[v.first].insert(shortest_path[v.first].begin(), shortest_path[u].begin(), shortest_path[u].end());
                    shortest_path[v.first].emplace_back(u);
                }
            }
        }
    }




}



int main() {
    int n, m, start;
    cin >> n >> m >> start;


    vector<vector<pair<int64_t, int64_t>>> graph(n + 1);
    vector inDegree(n + 1, 0);
    vector visited(n + 1, false);
    vector<vector<int>> shortest_path(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].emplace_back(v, weight);
        inDegree[v]++;
    }

    auto top_sort_order = topologicalSort(graph, inDegree);

    std::vector<int64_t> distance(n + 1, std::numeric_limits<int>::max());

    distance[start] = 0;
    DAG(graph, distance, top_sort_order, shortest_path);

}
//5 8 5
//5 1 7
//5 4 4
//5 2 2
//3 1 6
//3 5 2
//1 2 1
//1 4 - 4
//4 2 - 2
