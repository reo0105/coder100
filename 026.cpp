#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> tree(200002);

void dfs(vector<int> &counter, int from, int par = -1)
{
    for (auto x : tree.at(from)) {
        if (x == par) continue;
        counter.at(x) += counter.at(from);
        dfs(counter, x, from);
    }
}


int main()
{
    int n, q;
    vector<int> counter(200002, 0);

    cin >> n >> q;

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        tree.at(a).push_back(b);
        tree.at(b).push_back(a);
    }

    for (int i = 0; i < q; i++) {
        int p, x;
        cin >> p >> x;
        counter.at(p) += x;
    }

    dfs(counter, 1);

    for (int i = 1; i <= n; i++) {
        cout << counter.at(i);
        if (i != n) cout << " ";
        else cout << endl;
    }

    return 0;
}