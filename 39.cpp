#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    vector<int> data(102);
    vector<vector<ll>> dp(102, vector<ll>(22, 0)); 

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data.at(i);
    }

    dp.at(1).at(data.at(0)) = 1;

    for (int i = 1; i < n-1; i++) {
        for (int j = 0; j < 21; j++) {
            if (j >= data.at(i)) dp.at(i+1).at(j-data.at(i)) += dp.at(i).at(j);
            if (j + data.at(i) <= 20) dp.at(i+1).at(j+data.at(i)) += dp.at(i).at(j);
        }
    }

    cout << dp.at(n-1).at(data.at(n-1)) << endl;

    return 0;
}