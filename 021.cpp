#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define INF 1L << 60

int main()
{
    int n;
    ll ans = 0;

    vector<int> h(100002), s(100002);

    cin >> n;

    for (int i  = 0; i < n; i++) {
        cin >> h.at(i) >> s.at(i);
    }

    ll left = -1, right = INF;
    while(right - left > 1) {
        ll mid = (left + right) / 2;

        bool ok = true;
        vector<ll> time(n, 0);
        for (int i = 0; i < n; i++) {
            if (mid < h.at(i)) ok = false;
            else time.at(i) = (mid - h.at(i)) / s.at(i);
        }

        sort(time.begin(), time.end());

        for (int i = 0; i < n; i++) {
            if (time.at(i) < i) ok = false;
        }

        if (ok) right = mid;
        else left = mid;
    }

    cout << right << endl;

    return 0;
}

// // 汎用的な二分探索のテンプレ
// int binary_search(int key) {
//     int left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
//     int right = (int)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

//     /* どんな二分探索でもここの書き方を変えずにできる！ */
//     while (right - left > 1) {
//         int mid = left + (right - left) / 2;

//         if (isOK(mid, key)) right = mid;
//         else left = mid;
//     }

//     /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
//     return right;
// }

#include <iostream>
#include <vector>

bool binary_search(vector<int> x, int target, int size)
{
    int left = -1, right = size;

    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (x.at(mid) == target) return true;
        if (x.at(mid) > target) right = mid;
        else left = mid;
    }

    return false;
}

int main()
{
    int n, q, ans = 0, t;
    vector<int> s(100002);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s.at(i);
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> t;
        if (binary_search(s, t, n)) {
            ans++;
        }
    }

    cout << ans << endl;


    return 0;
}