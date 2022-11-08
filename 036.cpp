#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, W;
    vector<int> v(102), w(102);
    vector<vector<int>> dp(102, vector<int>(1002));

    cin >> n >> W;

    for (int i = 0; i < n; i++) {
        cin >> v.at(i) >> w.at(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= W; j++) {
            if(j-w.at(i+1) >= 0) dp.at(i+1).at(j) = max(dp.at(i).at(j), dp.at(i+1).at(j-w.at(i+1)) + v.at(i+1));
            else dp.at(i+1).at(j) = dp.at(i).at(j);
        }
    }

    cout << dp.at(n).at(W) << endl;

    return 0;
}