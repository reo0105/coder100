#include <iostream>
#include <vector>
using namespace std;

long long inf = 1L << 58;
vector<vector<long long> > dist(102, vector<long long>(102, inf));

int is_negative_loop(int n)
{
    for (int i = 0; i < n; i++) {
        if (dist.at(i).at(i) < 0) {
            return 1;
        }
    }

    return 0;
}


int main()
{
    int v, e;
    int s, t, d;

    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        cin >> s >> t >> d;
        dist.at(s).at(t) = d;
    }

    for (int i = 0; i < v; i++) {
        dist.at(i).at(i) = 0;
    }

    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                dist.at(i).at(j) = min(dist.at(i).at(j), dist.at(i).at(k) + dist.at(k).at(j));
            }
        }
    }

    if (is_negative_loop(v)) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                if (dist.at(i).at(j) > inf / 2) {
                    cout << "INF";
                } else {
                    cout << dist.at(i).at(j);
                }
                if (j != v-1) cout << " ";
            }
            cout << endl;
        }
    }

    return 0;
}