#include <algorithm>
#include <iostream>
#include <vector>
#include <tuple>
#include <ranges>

using namespace std;

int main() {
	int V, E;
	cin >> V >> E;

	std::vector<std::tuple<int, int, int>> edges(E);
	std::vector<std::tuple<int, int, int>> MST;
	MST.reserve(V - 1);

	std::vector<int> colors(V + 1);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges[i] = std::make_tuple(u, v, w);
	}

	std::ranges::sort(edges, [](const auto& a, const auto& b) {
		return std::get<2>(a) < std::get<2>(b);});

	for (int i = 1; i <= V; i++) {
		colors[i] = i;
	}
	int idx = 0;

	for (const auto& edge : edges) {
		int start = std::get<0>(edge);
		int end = std::get<1>(edge);

		if (colors[start] != colors[end]) {

			MST.emplace_back(edge);

			int old_color = colors[end];

			ranges::transform(colors, colors.begin(),[&](int c) {
				return c == old_color ? colors[start] : c;
			});
			++idx;
			if (idx == V - 1) {
				break;
			}

		}
	}


}
