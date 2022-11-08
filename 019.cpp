#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(vector<int> dis, int key, int size)
{
    int left = 0, right = size;
    int mid;

    while (left < right) {
        mid = (left + right) / 2;
        if (dis.at(mid) == key) return mid;
        else if (dis.at(mid) > key) right = mid;
        else left = mid + 1;
    }

    return mid;
}

int main()
{
    int d, n, m, sum = 0, min;
    vector<int> dis;
    vector<int> to(10002);

    cin >> d >> n >> m;

    dis.push_back(0);

    for (int i = 1; i < n; i++) {
        int tmp;
        cin >> tmp;
        dis.push_back(tmp);
    }

    dis.push_back(d);

    // for (int i = 0; i <= n; i++) {
    //     cout << dis.at(i);
    // }
    // cout << endl;

    sort(dis.begin(), dis.end());

    // for (int i = 0; i <= n; i++) {
    //     cout << dis.at(i);
    // }
    // cout << endl;

    for (int i = 0; i < m; i++) {
        cin >> to.at(i);
    }

    for (int i = 0; i < m; i++) {
        min = 1 << 29;
        int x = binary_search(dis, to.at(i), n+1);
        // cout << x << endl;
        if (min > abs(to.at(i) - dis.at(x))) {
            min = abs(to.at(i) - dis.at(x));
            // cout << 300 << endl;
        }
        // cout << dis.at(x+1) << endl;
        if (x+1 <= n && min > abs(to.at(i) - dis.at(x+1))) {
            min = abs(to.at(i) - dis.at(x+1));
            // cout << 200 << endl;
        }
        // cout << dis.at(x-1) << endl;
        if (x-1 >= 0 && min > abs(to.at(i) - dis.at(x-1))) {
            min = abs(to.at(i) - dis.at(x-1));
            // cout << 100 << endl;
        }
        // cout << min << endl;
        sum += min;
    }

    cout << sum << endl;

    return 0;
}