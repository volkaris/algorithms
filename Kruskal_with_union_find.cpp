#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TupleComparator {
    bool operator()(const std::tuple<int, int, int>& a, const std::tuple<int, int, int>& b) const {
        return std::get<2>(a) > std::get<2>(b); // compare based on third element
    }
};

class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) {
            return false; // x and y are already in the same set
        }
        if (rank[px] < rank[py]) {
            parent[px] = py;
        }
        else if (rank[px] > rank[py]) {
            parent[py] = px;
        }
        else {
            parent[py] = px;
            ++rank[px];
        }
        return true;
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int Kruskal() {
    int V, E;
    cin >> V >> E;
    int cost_Of_mst = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, TupleComparator> edges;
    vector<tuple<int, int, int>> MST;
    MST.reserve(V - 1);
    UnionFind uf(V + 1);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push(make_tuple(u, v, w));
    }

    int idx = 0;
    while (!edges.empty()) {
        const int start = get<0>(edges.top());
        const int end = get<1>(edges.top());
        const int weight = get<2>(edges.top());

        if (uf.unite(start, end)) {
            MST.emplace_back(edges.top());
            cost_Of_mst += weight;
            ++idx;
            if (idx == V - 1) {
                break;
            }
        }

        edges.pop();
    }

    return cost_Of_mst;
}

int main() {
    cout << Kruskal();
    return 0;
}