#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int r, c, zero, one, tmp, ans = -1;
    vector<vector<int>> a(12, vector<int>(10002));

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a.at(i).at(j);
        }
    }

    for (int i = 0; i <= 0x03ff; i++) {
        tmp = 0;
        for (int j = 0; j < c; j++) {
            zero = 0; one = 0;
            for (int k = 0; k < r; k++) {
                if ((i >> k) & 1) {
                    //k行目を返す
                    if (a.at(k).at(j)) zero++;
                    else one++;
                } else {
                    //返さない
                    if (a.at(k).at(j)) one++;
                    else zero++;
                }
           }
           tmp += max(zero, one);
        }

        if (tmp > ans) ans = tmp;
    }

    cout << ans << endl;

    return 0;
}