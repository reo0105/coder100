#include <bits/stdc++.h>
using namespace std;

vector< vector < int > > G(102);
vector<int> dist_d(102, -1);
vector<int> dist_f(102, -1);
int t = 1;

void dfs(int from)
{
    dist_d.at(from) = t;

    for (int next : G.at(from)) {
        if (dist_d.at(next) != -1) continue;
        t++;
        dfs(next);
    }

    t++;
    dist_f.at(from) = t;

}

int main()
{
    int n, k, u, v;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            cin >> v;
            G.at(u).push_back(v);
        }
    }

    for (int i = 0; i < n; i++) {
        sort(G.at(i).begin(), G.at(i).end());
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << i << " " << dist_d.at(i) << " " << dist_f.at(i) << endl;
    }

    return 0;

}
