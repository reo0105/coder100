#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, cnt = 0, t = 0;
    bool x_ok = false, y_ok = false, z_ok = false;
    char x, y, z;
    string s;

    cin >> n >> s;

    for (int i = 0; i < 1000; i++) {
        x = i / 100;
        y = i / 10 - x * 10 + '0';
        x += '0';
        z = i % 10 + '0';
        for (int j = 0; j < n; j++) {
            if (!x_ok && s.at(j) == x) x_ok = true;
            else if (x_ok && !y_ok && s.at(j) == y) y_ok = true;
            else if (x_ok && y_ok && !z_ok && s.at(j) == z) z_ok = true;
        }
        if (x_ok && y_ok && z_ok) {
            cnt++;
            //cout << x << y << z << endl;
        }
        x_ok = false; y_ok = false; z_ok = false;
    }

    cout << cnt << endl;

    return 0;
}