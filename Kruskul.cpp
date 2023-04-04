#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;


int main() {
	int V, E;
	cin >> V >> E;
	int how_much_edges_to_add = V - 1;

	vector<vector<pair<int, int>>> graph(V + 1);

	std::vector<std::tuple<int, int, int>> ordered_edges;
	std::vector<std::tuple<int, int, int>> MST;
	std::vector<int> colours(V + 1);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].emplace_back(v, w);
		graph[v].emplace_back(u, w);
		ordered_edges.emplace_back(u, v, w);
	}

	for (int i = 1; i <= V; i++) {
		colours[i] = i;
	}
	bool found = false;

	ranges::sort(ordered_edges, [](const auto& a, const auto& b) {
		return std::get<2>(a) < std::get<2>(b);
	});


	int idx = 0;
	for (;;) {
		for (int i = 0; i < ordered_edges.size(); ++i) {
			if (colours[std::get<1>(ordered_edges[i])] != colours[std::get<0>(ordered_edges[i])]) {
				MST.emplace_back(ordered_edges[i]);
				colours[std::get<1>(ordered_edges[i])] = colours[std::get<0>(ordered_edges[i])];


				++idx;
				if (idx == how_much_edges_to_add) {
					found = true;
					break;
				}
			}
		}

		if (found) {
			break;
		}
	}
	int x = 10;
}
