#include <iostream>
#include <vector>
using namespace std;
#define INF 1<<29

int main()
{
    int n, m;
    vector<int> D(1002), C(1002);
    vector<vector<int>> dp(1002, vector<int>(1002, INF));

    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> D.at(i);
    for (int i = 1; i <= m; i++) cin >> C.at(i);

    for (int i = 0; i < m; i++) dp.at(0).at(i) = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i<=j) dp.at(i).at(j) = min(dp.at(i-1).at(j-1) + D.at(i)*C.at(j), dp.at(i).at(j-1));
        }
    }

    //  for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << dp.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp.at(n).at(m) << endl;;

    return 0;
}