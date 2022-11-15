#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int binary_search(vector<int> x, int target, int size)
{
    int left = -1, right = size; // left~right-1までが探索範囲
    int mid;

    // cout << "target :" << target << endl;

    while (right - left > 1) {
        mid = (left + right) / 2;
        if (x.at(mid) == target) return mid;
        if (x.at(mid) > target) right = mid; // midはtargetではないから0~mid-1を探索範囲にする
        else left = mid; //midはtargetではないから新しい探索範囲の左端はleft+1
    }

    return right;
}


int main()
{
    int n, x;
    vector<int> a, b, c;
    vector<int> mid(100002, 0);
    ll ans = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        cin >> x;
        b.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        cin >> x;
        c.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    // for (int i = 0; i < n; i++) {
    //     int middle = b.at(i);
    //     int top = binary_search(a, middle, n);
    //     int bottom = n - binary_search(c, middle, n);
    //     // mid.at(i) = n - index;
    //     cout << top << " " << bottom << endl;
    //     ans += top * bottom;
    // }
    // cout << ans << endl;

    // for (int i = n-1; i >= 0; i--) { 
    //     mid.at(i) += mid.at(i+1);
    // }



    for (int i = 0; i < n; i++) {
        int middle =  b.at(i);
        ll top =  lower_bound(a.begin(), a.end(), middle) - a.begin(); 
        ll bottom = c.end() - upper_bound(c.begin(), c.end(), middle);
        // cout << top << " " << bottom << endl;
        ans += top * bottom;
    }

    cout << ans << endl;

    return 0;
}