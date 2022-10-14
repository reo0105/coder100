#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int inf = 1 << 29;
typedef pair<int, int> P;
struct edge {
    int to;
    int cost;
};
vector<vector<edge>> G(100002);
vector<int> dist(100002, inf);


void Dijkstra(int start)
{
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace((dist[start] = 0), start);

    while(!que.empty()) {
        int distance = que.top().first;
        int from = que.top().second;
        que.pop();

        if (dist[from] < distance) {
            continue;
        }

        for (auto edge : G[from]) {
            int new_d = (dist[from] + edge.cost);

            if (new_d < dist[edge.to]) {
                que.emplace((dist[edge.to] = new_d), edge.to);
            }
        }
    }
}

int main()
{
    int v, e, r;
    int s, t, d;
    struct edge tmp;
    cin >> v >> e >> r;

    for (int i = 0; i < e; i++) {
        cin >> s >> t >> d;
        tmp.to = t; tmp.cost = d;
        G.at(s).push_back(tmp);
    }

    Dijkstra(r);

    for (int i = 0; i < v; i++) {
        if (dist.at(i) == inf) {
            cout << "INF" << endl;
        } else {
            cout << dist.at(i) << endl;
        }
    }

    return 0;
}