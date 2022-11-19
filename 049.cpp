#include <iostream>
#include <vector>
using namespace std;
#define INF 1<<29

int main()
{
    int v, e;
    vector<vector<int>> G(20, vector<int>(20, INF));
    vector<vector<int>> dp(40000, vector<int>(20, INF));

    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        G.at(s).at(t) = d;
    }

    dp.at(0).at(0) = 0;

    for (int s = 0; s < (1 << v); s++) {
        for (int i = 0; i < v; i++) { // 次に通る点
            for (int j = 0; j < v; j++) { //過去の最新のやつ
                if (s != 0 && ((s & (1 << j)) == 0)) continue;

                if (((s & (1 << i)) == 0) && (i != j)) {
                    dp.at(s | (1<<i)).at(i) = min(dp.at(s | (1<<i)).at(i), dp.at(s).at(j) + G.at(i).at(j));
                }
            }
        }
    }

    if (dp.at((1<<v)-1).at(0) == INF) {
        cout << -1 << endl;
    } else {
        cout << dp.at((1<<v)-1).at(0) << endl;
    }

}
