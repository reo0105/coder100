#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, x, y;
    long long sum = 0, result = LONG_MAX;

    cin >> a >> b >> c >> x >> y;

    for (int i = 0; i < 200002; i+=2) {
        sum += c * i;

        int res_x = x - i/2;
        int res_y = y - i/2;

        if (res_x > 0) sum += a * res_x;
        if (res_y > 0) sum += b * res_y;

        result = min(result, sum);
        sum = 0;
    }
    cout << result;

    return 0;
}