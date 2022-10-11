#include <bits/stdc++.h>
using namespace std;

int main()
{
    static const int ub = 1e+8;
    int n;
    cin >> n;
    vector<int> r_vec(n), c_vec(n);
    vector<vector<int> > dp(n, vector<int>(n, ub));
    
    for (int i = 0; i < n; ++i) { 
        cin >> r_vec.at(i) >> c_vec.at(i);
    }
    
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 0;
    }


    // for (int j = 1; j < n; ++j) {
    //     for (int i = 0; i < n - j; ++i) {
    //         int rc = r_vec.at(i) * c_vec.at(i + j);
    //         for (int k = 1; k <= j; ++k) {
    //             int tmp = dp[i][k - 1] + dp[i + k][j - k];
    //             tmp += rc * r_vec.at(i + k);
    //             if (dp[i][j] > tmp)
    //                 dp[i][j] = tmp;
    //         }
    //     }
    // }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            int rc = r_vec.at(i) * c_vec.at(i+j);
            for (int k = 1; k <= j; k++) {
            int tmp = dp.at(i).at(k-1) + dp.at(i+k).at(j-k);
            tmp += rc * r_vec.at(i+k);
            if (dp.at(i).at(j) > tmp) {
                dp.at(i).at(j) = tmp;
            } 
            }
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}