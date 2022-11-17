#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int q;
    cin >> q;


    for (int k = 0; k < q; k++) {
        string x, y;
        vector<vector<int>> dp(1002, vector<int>(1002,0));
        cin >> x >> y;
        for (int i = 1; i <= (int)x.size(); i++) {
            for (int j = 1; j <= (int)y.size(); j++) {
                if (x.at(i-1) == y.at(j-1)) dp.at(i).at(j) = max(dp.at(i-1).at(j-1) + 1, dp.at(i).at(j));
                else dp.at(i).at(j) = max(dp.at(i).at(j-1), dp.at(i-1).at(j));
            }
        }

        // for (int i = 1; i <= (int)x.size(); i++) {
        //     for (int j = 1; j <= (int)y.size(); j++) {
        //         cout << dp.at(i).at(j) << " ";
        //     }
        //     cout << endl;
        // }

        cout << dp.at(x.size()).at(y.size()) << endl;
    }

    return 0;
}