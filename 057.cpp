#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1<<29
typedef pair<int, int> P;
struct edge{
    int to;
    int cost;
};

vector<vector<edge>> G(102);
vector<int> dist(102, INF);

void init_dist()
{
    for (int i = 0; i < 102; i++) {
        dist.at(i) = INF;
    }
}

void dijkstra(int from)
{
    priority_queue<P, vector<P>, greater<P>> que;
    dist.at(from) = 0;
    que.push(make_pair(0, from));

    while (!que.empty()) {
        int distance = que.top().first;
        int from = que.top().second;
        que.pop();

        if (dist.at(from) < distance) {
            continue;
        }

        for (auto edge : G.at(from)) {
            int new_d = (dist.at(from) + edge.cost);

            if (new_d < dist.at(edge.to)) {
                dist.at(edge.to) = new_d;
                que.push(make_pair(new_d, edge.to));
            }
        }
    }
}

int main()
{
    int n, k, flag, from, goal, j, c, x, y;
    struct edge tmp;

    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> flag;
        if (flag) {
            cin >> x >> y >> c;
            for (j = 0; j < (int)G.at(x).size(); j++) {
                if (G.at(x).at(j).to == y) {
                    if (G.at(x).at(j).cost > c) {
                        G.at(x).at(j).cost = c;
                    }
                    break;
                }
            }
            for (j = 0; j < (int)G.at(y).size(); j++) {
                if (G.at(y).at(j).to == x) {
                    if (G.at(y).at(j).cost > c) {
                        G.at(y).at(j).cost = c;
                    }
                    printf("A");
                    break;
                }
            }
            if (j == (int)G.at(y).size()) {
                tmp.cost = c;
                tmp.to = x;
                G.at(x).push_back(tmp);
                tmp.to = y;
                G.at(y).push_back(tmp);
            }

        } else {
            cin >> from >> goal;
            init_dist();
            dijkstra(from);
            if(dist.at(goal) == INF) {
                cout << -1 << endl;
            } else {
                cout << dist.at(goal) << endl;
            }
        }
    }

    return 0;
}