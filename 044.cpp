#include <iostream>
#include <vector>
using namespace std;
#define INF 1<<29

int main()
{
    int cnt = 1, size;
    vector<int> tetra, odd;

    while(1) {
        int t = cnt * (cnt+1) * (cnt+2) / 6;
        if (t >= 1000000) break;
        tetra.push_back(t);
        if (t % 2 == 1) odd.push_back(t);
        cnt++;
    }

    vector<int> dp_1(1000002, INF);
    vector<int> dp_2(1000002, INF);
    dp_1.at(0) = 0;
    dp_2.at(0) = 0;

    for (int i = 0; i < (int)tetra.size(); i++) {
        for (int j = 1; j <= 1000000; j++) {
            if (j >= tetra.at(i)) dp_1.at(j) = min(dp_1.at(j-tetra.at(i)) + 1, dp_1.at(j));
        }
    }

    for (int i = 0; i < (int)odd.size(); i++) {
        for (int j = 1; j <= 1000000; j++) {
            if (j >= odd.at(i)) dp_2.at(j) = min(dp_2.at(j-odd.at(i)) + 1, dp_2.at(j));
        }
    }


    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;

        cout << dp_1.at(n) << " " << dp_2.at(n) << endl;
    }

    return 0;
}