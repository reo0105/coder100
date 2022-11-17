#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;

    while(1) {
        cin >> n;
        if (n == 0) break;

        vector<int> w(n);
        vector<vector<int>> dp(n+1, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                for (int k = 1; k <= i; k++) {
                    int tmo = dp.at(k).at(j) + dp.at(i+1-k).at(j+k);
                    if (dp.at(i+1).at(j) < tmp) dp.at(i+1).at(j) = tmp;
                }
            }
        }

        for (int i = 0; i < n; i++) cin >> w.at(i);

    }
}