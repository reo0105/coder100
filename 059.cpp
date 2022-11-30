#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1<<29

typedef pair<int, int> p;
struct edge{
    edge (int x, int y) {
        to = x;
        cost = y;
    }
    int to;
    int cost;
};

vector<vector<edge>> G(5002);
vector<int> charge(5002, INF);

void dijkstra(int from)
{
    priority_queue<p, vector<p>, greater<p>> que;
    charge.at(from) = 0;
    que.push(make_pair(0, from));

    while (!que.empty()) {
        int c = que.top().first;
        int u = que.top().second;
        que.pop();

        if (charge.at(u) < c) continue;

        for (auto next : G.at(u)) {
            int new_c = charge.at(u) + next.cost;
            if (new_c < charge.at(next.to)) {
                charge.at(next.to) = new_c;
                que.push(make_pair(new_c, next.to));
            }
        }
    }
}

int main()
{
    int n, k;
    vector<int> c(5002), r(5002);
    vector<vector<int>> e(5002);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> c.at(i) >> r.at(i);
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        e.at(x).push_back(y);
        e.at(y).push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        queue<int> que;
        vector<int> dist(5002, -1);
        que.push(i);
        dist.at(i) = 0;
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            if (dist.at(u) >= r.at(i));
            for (int next : e.at(u)) {
                if (dist.at(next) != -1) continue;
                dist.at(next) = dist.at(u) + 1;
                que.push(next);
            }
        }

        for (int j = 1; j <= n; j++) {
            if (i==j) continue;
            if (dist.at(j) != -1) {
                G.at(i).push_back(edge(j, c.at(i)));
            }
        }
    }

    dijkstra(1);

    cout << charge.at(n) << endl;

    return 0;
}