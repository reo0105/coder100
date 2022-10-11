#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<vector< int > > G(102);
vector<int> dist_d(102, -1);
vector<int> dist_f(102, -1);
int t = 0;

int main()
{
    int n, k, u, v;
    cin >> n;
    deque<int> q;

    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            cin >> v;
            G.at(u).push_back(v);
        }
    }

    q.push_back(1);
    dist_d.at(1) = 0;
    while(!q.empty()) {
        u = q.front();
        q.pop_front();
        for (int next : G.at(u)) {
            if (dist_d.at(next) != -1) continue;
            dist_d.at(next) = dist_d.at(u) + 1;
            q.push_back(next);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << i << " " << dist_d.at(i) << endl;
    }

    return 0;

}