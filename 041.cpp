#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int d, n;
    vector<int> t(202, -1);
    vector<int> a(202), b(202), c(202);
    vector<vector<int>> dp(202, vector<int>(202));

    cin >> d >> n;

    for (int i = 0; i < d; i++) {
        cin >> t.at(i);
    }

    for (int i = 0; i < n; i++) {
        cin >> a.at(i) >> b.at(i) >> c.at(i);
    }

    for (int i = 1; i < d; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i != 1 && t.at(i) >= a.at(j) && t.at(i) <= b.at(j)) {
                    dp.at(i).at(j) =  max(dp.at(i).at(j), dp.at(i-1).at(k) + abs(c.at(k) - c.at(j)));
                } else if (i == 1 && t.at(0) >= a.at(k) && t.at(0) <= b.at(k) && t.at(i) >= a.at(j) && t.at(i) <= b.at(j)) {
                    dp.at(i).at(j) =  max(dp.at(i).at(j), dp.at(i-1).at(k) + abs(c.at(k) - c.at(j)));
                }
            }
        }
    }

    int ans = -1;

    for (int i = 0; i < n; i++) {
        if (dp.at(d-1).at(i) > ans) ans = dp.at(d-1).at(i);
    }

    cout << ans << endl;

    return 0;
}