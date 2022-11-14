#include <iostream>
#include <vector>
using namespace std;
#define MOD 100000

int main()
{
    int n, m, ans = 0;
    int move, now = 1, next_now;
    vector<int> dist(100002, 0);

    cin >> n >> m;

    for (int i = 2; i <= n; i++) {
        cin >> dist.at(i);
    }

    for (int i = 2; i <= n; i++) {
        dist.at(i) += dist.at(i-1);
    }

    for (int i = 0; i < m; i++) {
        int to;
        cin >> move;
        to = now + move;
        next_now = to;
        if (now > to) {
            swap(now, to);
        }
        ans = ans + dist.at(to) - dist.at(now);
        ans %= MOD;
        // cout << ans << endl;
        now = next_now;
    }

    cout << ans << endl;

    return 0;
}