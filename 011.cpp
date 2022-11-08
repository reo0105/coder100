#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, ans = 0, cnt = 0, flag = 1;
    vector<int> k(12), p(12);
    vector<vector<int>> s(12, vector<int>(12));

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> k.at(i);
        for (int j = 0; j < k.at(i); j++) {
            int tmp;
            cin >> tmp;
            s.at(i).at(j) = 1 << (tmp - 1);
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> p.at(i);
    }

    for (int i = 0; i < (1 << n); i++) {
        flag = 1;
        for (int j = 0; j < m; j++) {
            cnt = 0;
            for (int l = 0; l < k.at(j); l++) {
                if ((s.at(j).at(l) & i) != 0) {
                    cnt++;
                }
            }

            if (cnt % 2 != p.at(j)) {
                flag = 0;
                // cout << cnt << " " << p.at(j) << endl;
                // cout << "break" << endl;
                break;
            }
        }

        if (flag) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}