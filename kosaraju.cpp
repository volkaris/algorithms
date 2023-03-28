#include <iostream>
#include <vector>

using namespace std;



bool dfs(size_t current_vertex, size_t current_depth, size_t num_visited, vector<bool>& visited, const vector<vector < size_t >>& graph, size_t n) {
    visited[current_vertex] = true;
    ++num_visited;
    if (num_visited == n) {
        return true;
    }
    for (size_t i = 0; i < graph[current_vertex].size(); ++i) {
        const size_t to = graph[current_vertex][i];
        if (!visited[to]) {
            if (dfs(to, current_depth + 1, num_visited, visited, graph, n)) {
                return true;
            }
        }
    }
    visited[current_vertex] = false;
    return false;
}

void dfs_count_components(size_t current_vertex, vector<bool>& visited, const vector<vector < size_t >>& graph) {
    visited[current_vertex] = true;
    for (size_t i = 0; i < graph[current_vertex].size(); ++i) {
        const size_t to = graph[current_vertex][i];
        if (!visited[to]) {
            dfs_count_components(to, visited, graph);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    size_t n, m;
    cin >> n >> m;
   
    vector<vector < size_t >> graph;
    vector<bool> visited;
    graph.resize(n + 1);
    visited.assign(n + 1, false);
    for (size_t i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    for (size_t i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs_count_components(i, visited, graph);
           
        }
    }

   


    visited.assign(n + 1, false);
    for (size_t i = 1; i <= n; ++i) {
        if (!visited[i]) {
            if (dfs(i, 1, 0, visited, graph, n)) {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
}