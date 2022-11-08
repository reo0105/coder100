#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, idx;
    vector<int> x(202), y(202), r(202, 10000);
    double min = 10000, dis;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x.at(i) >> y.at(i) >> r.at(i);
    }

    for (int i = n; i < n + m; i++) {
        cin >> x.at(i) >> y.at(i);
    }

    min = *min_element(r.begin(), r.end());

    // cout << min << endl;

    for (int i = n; i < n + m; i++) {
        for (int j = 0; j < n; j++) {
            dis = sqrt((x.at(j) - x.at(i)) * (x.at(j) - x.at(i)) + (y.at(j) - y.at(i)) * (y.at(j) - y.at(i))) - r.at(j);
            if (min > dis) {
                min = dis;
            } 
        }
    }

    // cout << min << endl;

    for (int i = n; i < n + m; i++) {
        for(int j = i+1; j < n + m; j++) {
            dis = (double)sqrt((x.at(j) - x.at(i)) * (x.at(j) - x.at(i)) + (y.at(j) - y.at(i)) * (y.at(j) - y.at(i))) / 2;
            if (min > dis) {
                min = dis;
            }
        }
    }

    cout << fixed << setprecision(12) << min << endl;

    return 0;
}