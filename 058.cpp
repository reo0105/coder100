#include <iostream>
#include <vector>
#include <set>
#include <queue>
#define INF 1L<<58
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
struct edge {
    int to;
    ll cost;
};

vector<vector<edge>> G(100002);
vector<ll> charge(100002, INF);

void dijkstra(int from)
{
    priority_queue<P, vector<P>, greater<P>> que;
    charge.at(from) = 0;
    que.push(make_pair(0, from));

    while (!que.empty()) {
        ll c = que.top().first;
        int u = que.top().second;
        que.pop();

        if (charge.at(u) < c) { //最小ではない場合は更新を行わない
            continue;
        }

        // cout << "in" << endl;

        for (auto edge : G.at(u)) {
            // cout << "in" << endl;
            ll new_c = charge.at(u) + edge.cost;

            if (new_c < charge.at(edge.to)) {
                charge.at(edge.to) = new_c;
                que.push(make_pair(new_c, edge.to));
            }
        }
    }
}


int main()
{
    int n, m, k, s, u;
    int p, q;
    ll ans = 0;
    vector<int> c(100002);
    set<int> no, danger;
    struct edge tmp;
    

    cin >> n >> m >> k >> s;
    cin >> p >> q;

    for (int i = 0; i < k; i++) {
        cin >> c.at(i);
        no.insert(c.at(i));
    }
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        // if (!no.count(x+1) && !no.count(y+1) && x+1 != n && y+1 != n) {
            // if (danger.count(x+1)) {
            //     G.at(y+1).push_back(make_pair(x+1, q));
            // } else {
            //     G.at(y+1).push_back(make_pair(x+1, p));
            // }
            // if (danger.count(y+1)) {
            //     G.at(x+1).push_back(make_pair(y+1, q));
            // } else {
            //     G.at(x+1).push_back(make_pair(y+1, p));
            // }
        // } else if (x+1 == n || y+1 == n) {
      		tmp.to = y;
      		tmp.cost = p;
            G.at(x).push_back(tmp);
      		tmp.to = x;
            G.at(y).push_back(tmp);
        // }
    }

    vector<int> dist(100002, -1);
    queue<int> que;
  
    for (int i = 0; i < k; i++) {
        que.push(c.at(i));
        dist.at(c.at(i)) = 0;
        // cout << c.at(i) << " ";
    }

    // cout << endl;
    // for (auto next : G.at(1)) {
    //     cout << next.to << " ";
    // }

    // cout << endl;

    while(!que.empty()) {
        u = que.front();
        que.pop();
        if (dist.at(u) >= s) break;
        for (auto next : G.at(u)) {
            if (dist.at(next.to) != -1) continue;
            dist.at(next.to) = dist.at(u) + 1;
            que.push(next.to);
            danger.insert(next.to);
        }
    }

    // for (int i = 0; i < (int)danger.size(); i++)

    for (int i = 1; i <= n; i++) {
        if (no.count(i)) {
            queue<int> to;
            for (int j = 0; j < (int)G.at(i).size(); j++) {
                to.push(G.at(i).at(j).to);
            }
            while(!to.empty()) {
                int t = to.front();
                to.pop();
                for (auto &x : G.at(t)) {
					if (x.to == i) {
						x.cost = INF;
                      	break;
                    }
                }
            }
        } else if (danger.count(i)) {
            queue<int> to;
            for (int j = 0; j < (int)G.at(i).size(); j++) {
                to.push(G.at(i).at(j).to);
            }
            while(!to.empty()) {
                int t = to.front();
                to.pop();
                for (auto &x : G.at(t)) {
					if (x.to == i) {
						x.cost = q;
                      	break;
                    }
                }
            }
        } 
        if (i == n) {
            queue<int> to;
            for (int j = 0; j < (int)G.at(i).size(); j++) {
                to.push(G.at(i).at(j).to);
            }
            while(!to.empty()) {
                int t = to.front();
                to.pop();
                for (auto &x : G.at(t)) {
					if (x.to == i) {
						x.cost = 0;
                      	break;
                    }
                }
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (auto u : G.at(i)) {
    //         cout << i << ": " << u.to << " " << u.cost << endl;
    //     }
    // }

    dijkstra(1);

    // for (int i = 1; i <= n+1; i++) cout << charge.at(i) << endl;

    cout << charge.at(n) << endl;
}
