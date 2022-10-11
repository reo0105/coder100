#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, reuslt = 0, cnt = 0;

    cin >> n;

    for (int i = 1; i <= n; i += 2) {
        for (int j = 1; j <=n ; j+=2) {
            if (i % j == 0) {
                cnt++;
            }
        }

        if (cnt == 8) {
            reuslt++;
        }
        cnt = 0;
    }

    cout << reuslt << endl;


    return 0;
}