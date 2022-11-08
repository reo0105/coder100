#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,  cnt = 0, ans = 0;
    vector<int> data(30002);
    vector<int> dp(30002, 0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data.at(i);
    }

    for (int i = 0; i < n; i++) {
        int c = data.at(i);
        for (int j = 0; j < c; j++) {
            int dp_c = dp.at(j) + 1;
            if (dp.at(c) < dp_c) {
                dp.at(c) = dp_c;
            }
        }
    }

    cout << n - *max_element(dp.begin(), dp.end()) << endl;

    return 0;    
}