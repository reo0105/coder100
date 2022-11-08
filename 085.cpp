#include <iostream>
#include <vector>
using namespace std;

struct UnionFind
{
    vector<int> pair;

    UnionFind(int n) {
        pair.assign(n, -1);
    }
    
    int root(int x) {
        return pair.at(x) < 0 ? x : (pair.at(x) = root(pair.at(x)));
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (pair.at(x) > pair.at(y)) swap(x, y); //サイズ？高さ？による更新らしい
        pair.at(x) += pair.at(y);
        pair.at(y) = x;
    }

    bool equal(int x, int y) {
        return root(x) == root(y);
    }
};

int main()
{
    int n, q;
    int com, x, y;

    cin >> n >> q;

    struct UnionFind uf(n);

    for (int i = 0; i < q; i++) {
        cin >> com >> x >> y;

        if (com == 0) {
            uf.unite(x, y);
        } else {
            cout << uf.equal(x, y) << endl;
        }

    }

    return 0;
}