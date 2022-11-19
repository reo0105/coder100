#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
#define INF 1<<58


int main()
{
    int n, m;
    ll cnt = 0;
    vector<vector<p>> G(20, vector<p>(20, make_pair(INF, -1)));
    vector<vector<p>> dp(70000, vector<p>(20, make_pair(INF, 0)));

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        ll s, t, d, time;
        cin >> s >> t >> d >> time;
        G.at(s-1).at(t-1) = make_pair(d, time);
        G.at(t-1).at(s-1) = make_pair(d, time);
    }

    dp.at(0).at(0) = make_pair(0, 0);

    for (int s = 0; s < (1<<n); s++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if ((s != 0) && ((s & (1<<v)) == 0)) continue;

                if (((s & (1 << u)) == 0) && (u != v)) {
                    // if (dp.at(s).at(v).first + G.at(v).at(u).first < G.at(v).at(u).second) {
                        dp.at(s|(1<<u)).at(u).first = min(dp.at(s|(1<<u)).at(u).first, dp.at(s).at(v).first + G.at(v).at(u).first);
                        dp.at(s|(1<<u)).at(u).second = min(dp.at(s|(1<<u)).at(u).second, dp.at(s).at(v).second + G.at(v).at(u).second);
                    // }
                }
            }
        }
    }

    if (dp.at((1<<n)-1).at(0).first == INF) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << dp.at((1<<n)-1).at(0).first << endl;
    }
}