#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int n, second = 0;
    string s;
    // vector<string> s(10002);
    vector<int> ans(86400, 0);

    while(1) {
        cin >> n;
        if (n == 0) break;

        // for (int i = 0; i < n; i++) {
            // cin >> s.at(i);
        // }

        for (int i = 0; i < n; i++) {
            cin >> s;
            second = 0;
            second += 36000 * (int)(s.at(0) - '0');
            second += 3600 * (int)(s.at(1) - '0');
            second += 600 * (int)(s.at(3) - '0');
            second += 60 * (int)(s.at(4) - '0');
            second += 10 * (int)(s.at(6) - '0');
            second += (int)(s.at(7) - '0');

            ans.at(second) += 1;
            second = 0;

            cin >> s;
            second += 36000 * (int)(s.at(0) - '0');
            second += 3600 * (int)(s.at(1) - '0');
            second += 600 * (int)(s.at(3) - '0');
            second += 60 * (int)(s.at(4) - '0');
            second += 10 * (int)(s.at(6) - '0');
            second += (int)(s.at(7) - '0');

            ans.at(second) -= 1;
        }

        int max = -1, cnt = 0;

        for (int i = 0; i < 86400; i++) {
            cnt += ans.at(i);
            if (cnt > max) max = cnt;
        }

        ans.assign(86400, 0);

        cout << max << endl;
    }
}