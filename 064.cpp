#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind
{
    // データiが属する木の親番号
    vector<int> par;

    UnionFind(int n) {
        par.assign(n, -1);
    }

    int root(int x) {
        return par.at(x) < 0 ? x : (par.at(x) = root(par.at(x)));
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (par.at(x) > par.at(y)) swap(x, y);
        par.at(x) += par.at(y);
        par.at(y) = x;
    }

    bool equal(int x, int y) {
        return root(x) == root(y);
    }
};

struct Edge {
    int u, v;
    long long cost;
    bool operator< (Edge const& o) {
        return cost < o.cost;
    }
};

//vector<Edge> minimum_spanning_tree(int N, vector<Edge> edges)
int minimum_spanning_tree(int N, vector<Edge> edges)
{
    //vector<Edge> tree_edges;
    long long weight = 0;
    UnionFind uf(N);
    sort(edges.begin(), edges.end());

    for (auto &e : edges) {
        if (uf.equal(e.u, e.v)) continue;

        uf.unite(e.u, e.v);
        //tree_edges.push_back(e);
        weight += e.cost;
    }

    //return tree_edges;
    return weight;
}

int main()
{
    int v, e;
    int s, t, w;
    vector<Edge> edges(100002);

    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        cin >> s >> t >> w;
        edges.at(i).u = s;
        edges.at(i).v = t;
        edges.at(i).cost = w;
    }

    cout << minimum_spanning_tree(v, edges) << endl;;
}