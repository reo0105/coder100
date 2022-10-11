#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    vector<int> a(22);
    int q;
    vector<int> query(202);
    unordered_set<int> sum;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> query.at(i);
    }

    for (int i = 1; i < (1<<n); i++) {
        int x = 0;
        for (int j = 0; j < n; j++) {
            if (i && (1<<j)) x += a.at(j);
        }
        sum.insert(x);
    }

    for (int i = 0; i < q; i++) {
        int x = query.at(i);
        if (sum.count(x)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}