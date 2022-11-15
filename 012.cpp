#include <iostream>
#include <bitset>
#include <set>
using namespace std;
typedef pair<int, int> p;

int main()
{
    int n, m, max = -1, cnt = 0;
    set<p> relation;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        relation.insert(p(x, y));
    }

    for (int i = 1; i <= 0xfff; i++) {
        for (int j = 0; j < n; j++) {
            if (!((i >> j) & 1)) continue;
            for (int k = j+1; k < n; k++) {
                if (((i >> k) & 1)) {
                    if (!relation.count(p(j+1, k+1))) goto out;
                }
            }
        }
        // cout << bitset<12>(i) << endl;

        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) cnt++;
        }

        if (cnt > max) max = cnt;
        cnt = 0;
out:
        ;
    }

    cout << max << endl;
}   