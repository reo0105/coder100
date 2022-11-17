#include <iostream>
#include <vector>
using namespace std;
#define INF 1<<29

int main()
{
    int n;
    char color;
    vector<int> rwb(3002, 0);
    // vector<vector<char>> color(5, vector<char>(1002));
    vector<vector<vector<int>>> dp(3, vector<vector<int>>(3, vector<int>(1002, INF)));

    cin >> n;

    for (int i = 0; i < 5; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> color;
            if (color == 'R') rwb.at(j) += 1;
            if (color == 'W') rwb.at(j+1000) += 1;
            if (color == 'B') rwb.at(j+2000) += 1;
        }
    }

    // for (int i = 0; i < 5; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << rwb.at(j) << " ";
    //         cout << rwb.at(j+1000) << " ";
    //         cout << rwb.at(j+2000) << endl;
    //     }
    // }

    /*
        0:  赤
        1:　白
        2:　青
    */

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            dp.at(i).at(j).at(0) = 0;
        }
    }
    
    for (int l = 1; l <= n; l++) { // 何列目か
        for (int k = 0; k < 3; k++) { // 今塗る色
            for (int i = 0; i < 3; i++) { // 2つ前
                for (int j = 0; j < 3; j++) { // 1つ前
                    if (j == k) continue;
                    if (i == j) continue;
                    dp.at(j).at(k).at(l) = min(dp.at(i).at(j).at(l-1) + (5 - rwb.at(1000*k+l)), dp.at(j).at(k).at(l));
                }
            }
        }
    }

    int min = INF;

    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < 3; j++) {
    //         for (int k = 1; k <= n; k++) {
    //             cout << dp.at(i).at(j).at(k)<< " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (min > dp.at(i).at(j).at(n)) {
                min = dp.at(i).at(j).at(n);
            }
        }
    }

    cout << min << endl;

    return 0;
}