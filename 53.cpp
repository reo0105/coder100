#include <bits/stdc++.h>
using namespace std;

// ???
int main()
{
    static const int ub = 1e+9 + 1;
    int n;
    cin >> n;
    vector<int> a_vec(n);
    for (int i = 0; i < n; ++i)
        cin >> a_vec.at(i);
    vector<int> dp(n, ub);
    for (int a : a_vec) {
        auto ite = lower_bound(dp.begin(), dp.end(), a);
        *ite = a;
    }
    int len = lower_bound(dp.begin(), dp.end(), ub) - dp.begin();
    cout << len << endl;
}