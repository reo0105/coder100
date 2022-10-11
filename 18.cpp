#include <bits/stdc++.h>
using namespace std;

int n, q, t, cnt = 0;
vector<int> s(100002);

int binary_search(int key)
{
    int left = 0;
    int right = n;

    while (left < right) {
        int mid = (right + left) / 2;
        if (s.at(mid) == key) return mid;
        else if (s.at(mid) > key) right = mid;
        else if (s.at(mid) < key) left = mid + 1;
    }

    return -1;
}

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s.at(i);
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> t;
        /* binary search */
        if (binary_search(t) != -1) {
            cnt++;
        };
    }

    cout << cnt << endl;
}