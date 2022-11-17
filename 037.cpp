#include <iostream>
#include <vector>
using namespace std;
#define INF 1<<29

int main()
{
    int n, m;
    vector<int> coin(22);
    vector<vector<int>> dp(22, vector<int>(50002, INF));

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> coin.at(i);
    }

    // for (int i = 1; i <= n; i++) dp.at(1).at(i) = i;
    dp.at(1).at(0) = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j >= coin.at(i)) dp.at(i).at(j) = min(dp.at(i).at(j - coin.at(i)) + 1, dp.at(i-1).at(j));
            else dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i-1).at(j));
        } 
    }

    // for (int i = 1; i <= m; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << dp.at(i).at(j) << " ";
    //     } 
    //     cout << endl;
    // }

    cout << dp.at(m).at(n) << endl;

    return 0;
}