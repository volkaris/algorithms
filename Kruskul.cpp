#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TupleComparator {
	bool operator()(const std::tuple<int, int, int>& a, const std::tuple<int, int, int>& b) const {
		return std::get<2>(a) > std::get<2>(b); // compare based on third element
	}
};


int Kruskal() {
	int V, E;
	cin >> V >> E;
	int cost_Of_mst = 0;
	std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, TupleComparator> edges;
	std::vector<std::tuple<int, int, int>> MST;
	MST.reserve(V - 1);

	std::vector<int> colors(V + 1);

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges .push(std::make_tuple(u, v, w));
	}

	for (int i = 1; i <= V; i++) {
		colors[i] = i;
	}

	int idx = 0;
	while (!edges.empty()) {
		const int start = std::get<0>(edges.top());
		const int end = std::get<1>(edges.top());

		if (colors[start] != colors[end]) {

			MST.emplace_back(edges.top());
			cost_Of_mst += std::get<2>(edges.top());

			++idx;
			if (idx == V - 1) {
				break;
			}

			const int end_color = colors[end];
#

			for (int i = 0; i < colors.size(); ++i) {
				if (colors[i] == end_color) {
					colors[i] = colors[start];
				}
			}

		}
		
		edges.pop();
	}
	return cost_Of_mst;

}


int main() {

	cout<<Kruskal();
}
