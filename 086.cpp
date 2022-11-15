#include <iostream>
#include <vector>
using namespace std;

class UnionFind
{
public:
    vector<int> par;
    
    UnionFind(int n) {
        par.assign(n, -1);
    }

    int root(int x) {
        return (par.at(x) < 0) ? x : (par.at(x) = root(par.at(x)));
    }

    int unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return 0;
        if (par.at(x) > par.at(y)) swap(x, y);
        par.at(x) += par.at(y); //木のサイズを保持。ただしマイナスの値として保持
        par.at(y) = x; 
    }

    bool equal(int x, int y) {
        return root(x) == root(y);
    }

};

int main()
{
    int n, m, j, ans = 0;
    vector<int> a(50), b(50);

    cin >> n >> m;

    for (int i = 0; i < m ; i++){
        cin >> a.at(i) >> b.at(i);
    } 

    for (int i = 0; i < m; i++) {
        UnionFind uf(n+1);
        for (j = 0; j < m; j++) {
            if (i != j) {
                uf.unite(a.at(j), b.at(j));
            }
        }

        for (j = 2; j <= n; j++) {
            if (!uf.equal(1, j)) break;
        }

        // cout << j << endl;

        if (j != n+1) ans++;
    }

    cout << ans << endl;

    return 0;
}