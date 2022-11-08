#include <iostream>
#include <vector>
using namespace std;


??????
int main()
{
    int n, K;
    vector<int> A(102, 0);
    vector<vector<vector<int>>> dp(102, vector<vector<int>>(5, vector<int>(5, 0)));

    cin >> n >> K;

    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        A.at(a-1) = b;
    }

    for (int j = 1; j < 4; j++) { // 2days ago
        if (A.at(0) != 0 && A.at(0) != j) continue;

        for (int i = 1; i < 4; i++) { // yesterday
            if (A.at(1) != 0 && A.at(1) != i) continue;
            dp.at(1).at(i).at(j) = 1;
        }
    }

    for (int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            cout << dp.at(1).at(i).at(j) << " ";
        }

        cout << endl;
    }

    for (int i = 2; i < n; i++) {
        for (int k = 1; k < 4; k++) { //1日前
            for (int l = 1; l < 4; l++) { //2日前
                for(int j = 1; j < 4; j++) { //今日
                    if (A.at(i) != 0) {
                        if (A.at(i) == j && !(i == j && j == k)) {
                            dp.at(i).at(j).at(k) += dp.at(i-1).at(k).at(l);
                            dp.at(i).at(j).at(k) %= 10000;
                        }
                    }
                    else if (!(i == j && j == k)) {
                        dp.at(i).at(j).at(k) += dp.at(i-1).at(k).at(l);
                        dp.at(i).at(j).at(k) %= 10000;
                    }
                }
            }
        }
    }

    int ans = 0;

    for(int i = 1; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            ans += dp.at(n-1).at(i).at(j);
            ans %= 10000;
        }
    }

    cout << ans << endl;

    return 0;
}